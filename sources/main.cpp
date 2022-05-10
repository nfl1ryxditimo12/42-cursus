#include "vector.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include "utils.hpp"

void	is_empty(TESTED_NAMESPACE::vector<TESTED_TYPE> const &vct)
{
	std::cout << "is_empty: " << vct.empty() << std::endl;
}

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

template <class T>
void ft_print(ft::vector<T> vec) // 참조자 빼고 호출하면 복사 생성자가 호출되는데 메모리 이중 해제 이슈 있음
{
	std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << ", *end: " << *vec.end() << ", pointer: " << (vec.begin() == vec.end()) << std::endl;
    std::cout << "[ft::vector]  :";
    for (typename ft::vector<T>::iterator it = vec.begin(); it < vec.end(); it++)
        std::cout << " " << *it;
    std::cout << std::endl;

	std::cout << "\n===================================================\n" << std::endl;
}

template <class T>
void std_print(std::vector<T> vec)
{
	std::cout << "\n===================================================\n" << std::endl;

	std::cout << "size: " << vec.size() << ", capacity: " << vec.capacity() << ", *end: " << *vec.end() << ", pointer: " << (vec.begin() == vec.end()) << std::endl;
    std::cout << "[std::vector] :";
    for (typename std::vector<T>::iterator it = vec.begin(); it < vec.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;
}

void vector_test()
{
    std::vector<int> vec;
	ft::vector<int> vec2;
	ft::vector<int> vec3(vec2);
	std::vector<int> vec4(vec);

	for (int i = 0; i < 10; i++) {
		vec.push_back(i + 1);
		vec2.push_back(i + 1);
	}

	std_print(vec);
	// std_print(vec4);
	ft_print(vec2);
	// ft_print(vec3);
}

int main()
{
    try {
        vector_test();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // system("leaks ft_container");
}