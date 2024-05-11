#include "easyfind.hpp"

int main()
{
    std::vector<int> vec(10);
    std::deque<int> deq(10);

    for (int i = 0; i < 10; i++) {
        vec.push_back(i);
        deq.push_back(i);
    }

    std::cout << "===============================\n" << std::endl;

    try {
        std::cout << "vector ";
        ::easyfind<std::vector<int> >(vec, 0);
        std::cout << "vector ";
        ::easyfind<std::vector<int> >(vec, 1);
        std::cout << "vector ";
        ::easyfind<std::vector<int> >(vec, 2);
        std::cout << "vector ";
        ::easyfind<std::vector<int> >(vec, 3);
        std::cout << "vector ";
        ::easyfind<std::vector<int> >(vec, 4);
        ::easyfind<std::vector<int> >(vec, 100);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================\n" << std::endl;

    try {
        std::cout << "deque ";
        ::easyfind<std::deque<int> >(deq, 0);
        std::cout << "deque ";
        ::easyfind<std::deque<int> >(deq, 1);
        std::cout << "deque ";
        ::easyfind<std::deque<int> >(deq, 2);
        std::cout << "deque ";
        ::easyfind<std::deque<int> >(deq, 3);
        std::cout << "deque ";
        ::easyfind<std::deque<int> >(deq, 4);
        ::easyfind<std::deque<int> >(deq, 11);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n===============================" << std::endl;
}
