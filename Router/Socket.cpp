#include "Socket.hpp"

#include "Response.hpp"
#include "Validator.hpp"

static ws::Validator validator;

/*
  메모리를 많이 사용하고 CPU를 적게 사용할 지
  반대로 사용할 지 trade-off 케이스를 생각해 보자
  보통 서버에선 전자로 많이 사용한다.
*/

/* console test code */
#include <iostream>
#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YLW "\e[0;33m"
#define CYN "\e[0;36m"
/* console test code */

ws::Socket::Socket(const ws::Configure& cls): _conf(&cls), _kernel() {

  ws::Configure::listen_vec_type host = cls.get_host_list();

  for (size_t i = 0; i < host.size(); i++) {
    int                 socket_fd;
    struct sockaddr_in  addr_info;

    if ((socket_fd = socket(PF_INET, SOCK_STREAM, 0)) == -1)
      exit_socket();

    memset(&addr_info, 0, sizeof(addr_info));
    addr_info.sin_family = AF_INET;
    addr_info.sin_addr.s_addr = host[i].first;
    addr_info.sin_port = host[i].second;

    if (bind(socket_fd, (struct sockaddr*)&addr_info, sizeof(addr_info)) == -1) {
      std::cout << strerror(errno) << std::endl;
        exit_socket();
    }
    if (listen(socket_fd, 5) == -1)
      exit_socket();
    fcntl(socket_fd, F_SETFL, O_NONBLOCK);
    _server.insert(server_map_type::value_type(socket_fd, host[i]));
    _kernel.kevent_ctl(socket_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, reinterpret_cast<void*>(&Socket::connect_client));
  }
}

ws::Socket::~Socket() {

}

void ws::Socket::connection() {
  size_t event_size = _server.size() * 8;
  struct kevent event_list[event_size];
  int new_event;

  while (1) {
    new_event = _kernel.kevent_wait(event_list, event_size);

    for (int i = 0; i < new_event; i++) {
      kevent_func func = reinterpret_cast<kevent_func>(event_list[i].udata);
      (*func)(this, event_list[i]);
    }
  }
}

/* Private function */

void ws::Socket::init_client(int fd, listen_type listen, client_value_type* client_data) {
  client_data->request = new ws::Request(listen);
  client_data->repository = new ws::Repository();
  client_data->response = NULL;
  client_data->status = 0;
  _client.insert(client_map_type::value_type(fd, client_data));
}

void ws::Socket::disconnect_client(int fd) {
  client_map_type::iterator client_iter = _client.find(fd);

  if (client_iter == _client.end())
    return;

  client_value_type* client_data = client_iter->second;

  delete client_data->request;
  delete client_data->repository;
  delete client_data;

  _client.erase(client_iter);
  close(fd);
}

void ws::Socket::exit_socket() {
  for (client_map_type::iterator it = _client.begin(); it != _client.end(); ++it) {
    client_value_type* client_data = it->second;

    delete client_data->request;
    delete client_data->repository;
    delete client_data;
  }
  exit(1);
}

void ws::Socket::connect_client(ws::Socket* self, struct kevent event) {
  listen_type& listen = self->_server.find(event.ident)->second;
  int client_socket_fd;

  if ((client_socket_fd = accept(event.ident, NULL, NULL)) == -1)
    self->exit_socket();
  fcntl(client_socket_fd, F_SETFL, O_NONBLOCK);
  self->init_client(client_socket_fd, listen, new client_value_type);
  self->_kernel.kevent_ctl(client_socket_fd, EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, reinterpret_cast<void*>(&Socket::recv_request));
}

/*
  eof가 아닌데 buffer size가 0인 경우 타임아웃 처리를 해야할 듯
*/
void ws::Socket::recv_request(ws::Socket* self, struct kevent event) {
  client_value_type* client_data = self->_client.find(event.ident)->second;
  char buffer[1024 * 1024];
  int  n;

  if ((n = read(event.ident, buffer, sizeof(buffer))) == -1)
    self->exit_socket();

  /*
    과연 if (n > 0) 이라는 조건이 필요할까?
    Request 클래스 내부적으로 판단할 지 생각해 보자.
  */
  if (n > 0)
    client_data->status = client_data->request->parse_request_message(self->_conf,client_data->repository, buffer);

  /*
    Request 클래스에서 모든 데이터를 다 읽었다면 eof == true로 설정된다.
    이 후 오류가 있다면 바로 process_request 함수로 가게 설정해준다.
    Repository 클래스를 Request 클래스에서 request header 파싱 후 초기화 해줄 지 고민해봐야 함
  */
  if (client_data->request->eof()) {
    /* EV_DELETE flags는 필요 없을듯 keep-alive 생각 */
    // self->_kernel.kevent_ctl(event.ident, EVFILT_READ, EV_DELETE, 0, 0, NULL);
    self->_kernel.kevent_ctl(event.ident, EVFILT_USER, EV_ONESHOT, 0, 0, reinterpret_cast<void*>(&Socket::process_request));
  }
}



void ws::Socket::process_request(ws::Socket* self, struct kevent event) {
  client_value_type* client_data = self->_client.find(event.ident)->second;

  if (!client_data->status)
    validator(client_data);
  
  client_data->response = new Response(client_data);

  client_data->response->generate_response();

  /*
    EVFILT_USER를 사용하는 경우 EV_ONESHOT flag 사용으로
    한번만 kevent의 change_list에 넣는 방식도 생각해 볼만 하다.
  */
  self->_kernel.kevent_ctl(event.ident, EVFILT_WRITE, EV_ADD, 0, 0, reinterpret_cast<void*>(&Socket::send_response));
}

void ws::Socket::send_response(ws::Socket* self, struct kevent event) {
  int n;
  std::string body = "hello world " + std::to_string(event.ident);
  std::string response = std::string("HTTP/1.1 200 OK\r\nAccept-Ranges: bytes\r\nConnection: keep-alive\r\nContent-Length: ") + std::to_string(body.length()) + std::string("\r\nContent-Type: text\r\nDate: Mon, 20 Jun 2022 02:59:03 GMT\r\nETag: \"62afd0a1-267\"\r\nLast-Modified: Mon, 20 Jun 2022 01:42:57 GMT\r\nServer: webserv\r\n\r\n") + body;

  if ((n = write(event.ident, response.c_str(), response.size())) == -1)
    self->exit_socket();

  /*
    keep-alive 방식으로 납둘지 close 해버릴지 고민해봐야함
    세션같은 경우 keep-alive가 좋을 수도 있다.

    EVFILT_WRITE인 경우 event.data의 값이 커널에 할당 가능한 buffer size 일텐데 이게 정확한 방법인지 생각해봐야 한다.
  */
  if (n <= event.data)
    self->disconnect_client(event.ident);
}
