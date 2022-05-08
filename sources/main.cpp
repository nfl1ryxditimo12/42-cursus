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

    std::cout << "=================================" << std::endl;
    std::cout << v7[-1] << std::endl;
    std::cout << v7[0] << std::endl;
    std::cout << v7[1] << std::endl;
    std::cout << v7[2] << std::endl;
    std::cout << v7[3] << std::endl;
    std::cout << v7[10] << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << v8[-1] << std::endl;
    std::cout << v8[0] << std::endl;
    std::cout << v8[1] << std::endl;
    std::cout << v8[2] << std::endl;
    std::cout << v8[3] << std::endl;
    std::cout << v8[10] << std::endl;
    std::cout << "=================================\n" << std::endl;

    std::vector<int> t1;
    ft::vector<int> t3;

    for (int i = 1; i <= 10; i++)
        t1.push_back(i);
    std::cout << "size: " << t1.size() << ", " << t1.capacity() << std::endl;
    std::cout << "t1:";
    for (std::vector<int>::iterator it = t1.begin(); it < t1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    t1.erase(t1.begin() + 3, t1.begin() + 7);
    std::cout << "size: " << t1.size() << ", " << t1.capacity() << std::endl;
    std::cout << "t1:";
    for (std::vector<int>::iterator it = t1.begin(); it < t1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    for (int i = 1; i <= 10; i++)
        t3.push_back(i);
    std::cout << "size: " << t3.size() << ", " << t3.capacity() << std::endl;
    std::cout << "t3:";
    for (ft::vector<int>::iterator it = t3.begin(); it < t3.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    t3.erase(t3.begin() + 3, t3.begin() + 7);

    std::cout << "size: " << t3.size() << ", " << t3.capacity() << std::endl;
    std::cout << "t3:";
    for (ft::vector<int>::iterator it = t3.begin(); it < t3.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;
    std::cout << *(t3.end()) << ", " << *(t1.end()) << std::endl;

    t1.erase(t1.begin() + 1, t1.end());
    t3.erase(t3.begin() + 1, t3.end());


    std::cout << "size: " << t1.size() << ", " << t1.capacity() << std::endl;
    std::cout << "t1:";
    for (std::vector<int>::iterator it = t1.begin(); it < t1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << "size: " << t3.size() << ", " << t3.capacity() << std::endl;
    std::cout << "t3:";
    for (ft::vector<int>::iterator it = t3.begin(); it < t3.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << *(t3.end()) << ", " << *(t1.end()) << std::endl;

    std::cout << "\n===================================================\n" << std::endl;

    for (int i = 1; i <= 10; i++)
        t1.push_back(i);
    for (int i = 1; i <= 10; i++)
        t3.push_back(i);

    t1.erase(t1.end() - 1);
    t3.erase(t3.end() - 1);


    std::cout << "size: " << t1.size() << ", " << t1.capacity() << std::endl;
    std::cout << "t1:";
    for (std::vector<int>::iterator it = t1.begin(); it < t1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << "size: " << t3.size() << ", " << t3.capacity() << std::endl;
    std::cout << "t3:";
    for (ft::vector<int>::iterator it = t3.begin(); it < t3.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << *(t3.end()) << ", " << *(t1.end()) << std::endl;

    std::cout << "\n===================================================\n" << std::endl;

    std::vector<int> res1;
    ft::vector<int> res2;

    for (int i = 1; i <= 10; i++)
        res1.push_back(i);
    for (int i = 1; i <= 10; i++)
        res2.push_back(i);

    res1.resize(5);
    res2.resize(5);

    std::cout << "size: " << res1.size() << ", " << res1.capacity() << std::endl;
    std::cout << "res1:";
    for (std::vector<int>::iterator it = res1.begin(); it < res1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << "size: " << res2.size() << ", " << res2.capacity() << std::endl;
    std::cout << "res2:";
    for (ft::vector<int>::iterator it = res2.begin(); it < res2.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << *(res1.end() + 4) << ", " << *(res2.end() + 4) << std::endl;

    std::cout << "\n===================================================\n" << std::endl;

    std::vector<int> g1(10);
    ft::vector<int> g2(10);

    g1.reserve(16);
    g2.reserve(16);

    std::cout << "size: " << g1.size() << ", " << g1.capacity() << std::endl;
    std::cout << "g1:";
    for (std::vector<int>::iterator it = g1.begin(); it < g1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << "size: " << g2.size() << ", " << g2.capacity() << std::endl;
    std::cout << "g2:";
    for (ft::vector<int>::iterator it = g2.begin(); it < g2.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << "\n===================================================\n" << std::endl;

    std::vector<int> a1;

    for (int i = 1; i <= 10; i++)
        a1.push_back(i);

    std::cout << "size: " << a1.size() << ", " << a1.capacity() << std::endl;
    std::cout << "a1:";
    for (std::vector<int>::iterator it = a1.begin(); it < a1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    a1.insert(a1.begin() + 5, 10, 100);

    std::cout << "size: " << a1.size() << ", " << a1.capacity() << std::endl;
    std::cout << "a1:";
    for (std::vector<int>::iterator it = a1.begin(); it < a1.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << *a1.end() << "\n" << std::endl;

    ft::vector<int> a2;

    for (int i = 1; i <= 10; i++)
        a2.push_back(i);

    std::cout << "size: " << a2.size() << ", " << a2.capacity() << std::endl;
    std::cout << "a2:";
    for (ft::vector<int>::iterator it = a2.begin(); it < a2.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    a2.insert(a2.begin() + 5, 10, 100);

    std::cout << "size: " << a2.size() << ", " << a2.capacity() << std::endl;
    std::cout << "a2:";
    for (ft::vector<int>::iterator it = a2.begin(); it < a2.end(); it++)
        std::cout << " " << *it;
    std::cout << "\n" << std::endl;

    std::cout << *a2.end() << "\n" << std::endl;
}

int main()
{
    try {
        test();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // system("leaks ft_container");
}