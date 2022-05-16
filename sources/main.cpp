#include "stack.hpp"
#include "map.hpp"
#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <stack>
#include <utility>
#include "utils.hpp"
#include "RB_TREE.hpp"

#define TESTED_NAMESPACE ft
#define TESTED_TYPE int
typedef std::list<int> container_type;
#define t_stack_ TESTED_NAMESPACE::stack<int, container_type>

template <class T_STACK>
void	cmp(const T_STACK &lhs, const T_STACK &rhs)
{
	static int i = 0;

	std::cout << "############### [" << i++ << "] ###############"  << std::endl;
	std::cout << "eq: " << (lhs == rhs) << " | ne: " << (lhs != rhs) << std::endl;
	std::cout << "lt: " << (lhs <  rhs) << " | le: " << (lhs <= rhs) << std::endl;
	std::cout << "gt: " << (lhs >  rhs) << " | ge: " << (lhs >= rhs) << std::endl;
}


void vector_test()
{
	std::map<std::string, int> test;
	
	test.insert(std::pair<std::string, int>("hello", 1));
	test["second"] = 100;

	for (std::map<std::string, int>::iterator it = test.begin(); it != test.end(); it++)
		std::cout << "[" << it->first << ", " << it->second << "]" << std::endl;

	ft::vector<int> t1(7);
	std::vector<int> t2(7);
	ft::stack<int> t3(7);
	std::cout << typeid(t1).name() << std::endl;
	std::cout << typeid(t2).name() << std::endl;
	std::cout << typeid(test).name() << std::endl;
	std::cout << typeid(t3).name() << std::endl;
	std::string class_name = typeid(t3).name();
	if (class_name.find("stack"))
		std::cout << "hello" << std::endl;
	if (class_name.find("vector"))
		std::cout << "world" << std::endl;
	ft::map<std::string, int> map;
	
}

void map_test()
{
	// ft::rb_tree tree(0);
	std::map<int, int> test;
	ft::map<int, int> test1;

	test.insert(std::pair<int, int>(1, 10));
	test1.insert(ft::pair<int, int>(1, 10));
	std::cout << test[2] << std::endl;
}

int main()
{
    try {
        // vector_test();
		map_test();
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
    // system("leaks ft_container");
}