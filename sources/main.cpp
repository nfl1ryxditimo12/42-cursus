#include "vector.hpp"
#include <iostream>
#include <vector>
#include <utility>
#include "utils.hpp"

void test()
{
    ft::vector<int> v1;

    std::cout << v1.size() << ", " << v1.capacity() << std::endl;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    v1.push_back(5);

    std::cout << v1.size() << ", " << v1.capacity() << std::endl;
    std::cout << "v1:";
    for (ft::vector<int>::iterator it = v1.begin(); it < v1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    ft::vector<int> v2;

    v2 = v1;

    std::cout << v2.size() << ", " << v2.capacity() << std::endl;
    std::cout << "v2:";
    for (ft::vector<int>::iterator it = v2.begin(); it < v2.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;
}

int main()
{
    try {
        test();

        std::vector<int> v3;
        std::vector<int> v4;

        v3.push_back(1);
        v3.push_back(2);
        v3.push_back(3);
        v3.push_back(4);
        v3.push_back(5);

        v4 = v3;

        std::cout << v4.size() << ", " << v4.capacity() << std::endl;
        std::cout << "v4:";
        for (std::vector<int>::iterator it = v4.begin(); it < v4.end(); it++)
            std::cout << " " << *it;
        std::cout << "\n" << std::endl;

        std::vector<std::string> v5(10);
        std::vector<std::string> v6;

        std::cout << v5[0] << v5.empty() << std::endl;
        std::cout << v6.empty() << std::endl;

        std::cout << std::endl;

        std::vector<int> v7(5, 100);
        ft::vector<int> v8(5, 100);

        std::cout << v7.size() << ", " << v7.capacity() << std::endl;
        std::cout << "v7:";
        for (std::vector<int>::iterator it = v7.begin(); it < v7.end(); it++)
            std::cout << " " << *it;
        std::cout << "\n" << std::endl;

        std::cout << v8.size() << ", " << v8.capacity() << std::endl;
        std::cout << "v8:";
        for (ft::vector<int>::iterator it = v8.begin(); it < v8.end(); it++)
            std::cout << " " << *it;
        std::cout << "\n" << std::endl;

        v7.resize(10);
        v8.resize(10);

        std::cout << v7.size() << ", " << v7.capacity() << std::endl;
        std::cout << "v7:";
        for (std::vector<int>::iterator it = v7.begin(); it < v7.end(); it++)
            std::cout << " " << *it;
        std::cout << "\n" << std::endl;

        std::cout << v8.size() << ", " << v8.capacity() << std::endl;
        std::cout << "v8:";
        for (ft::vector<int>::iterator it = v8.begin(); it < v8.end(); it++)
            std::cout << " " << *it;
        std::cout << "\n" << std::endl;

    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // system("leaks ft_container");
}