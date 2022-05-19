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
#include "test.hpp"

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
	ft::vector<int> v;

	for (int i = 0; i < 10; i++)
		v.push_back(i + 1);
	ft::vector<int>::iterator it = v.begin();
	ft::vector<int>::const_iterator cit = v.begin();
	ft::vector<int>::reverse_iterator rit = v.rbegin();
	ft::vector<int>::const_reverse_iterator crit = v.rbegin();

	std::cout << (it == cit) << std::endl;
	std::cout << (rit == crit) << std::endl;

	
}
#include <ctime>
void map_test()
{
	// ft::rb_tree tree(0);
	ft::pair<int, int>pair(1, 10);

	// std::cout << "pair: " << pair.first << ", " << pair.second << std::endl;

	clock_t start1, end1;

	start1 = clock();
	std::map<int, int> test;

	test.insert(std::pair<int, int>(3, 5));
	test.insert(std::pair<int, int>(1, 20));
	test.insert(std::pair<int, int>(5, 30));
	test.insert(std::pair<int, int>(7, 10));
	test.insert(std::pair<int, int>(10, 100));
	test.insert(std::pair<int, int>(15, 100));
	test.insert(std::pair<int, int>(17, 100));
	test.insert(std::pair<int, int>(20, 100));
	// test.insert(std::pair<int, int>(2, 100));
	// test.insert(std::pair<int, int>(4, 100));
	// test.insert(std::pair<int, int>(6, 100));
	// test.insert(std::pair<int, int>(21, 100));
	// test.insert(std::pair<int, int>(22, 100));
	// test.insert(std::pair<int, int>(23, 100));
	// test.insert(std::pair<int, int>(24, 100));
	// test.insert(std::pair<int, int>(25, 100));
	// test.insert(std::pair<int, int>(26, 100));
	// test.insert(std::pair<int, int>(27, 100));
	// test.insert(std::pair<int, int>(28, 100));
	// test.insert(std::pair<int, int>(39, 100));
	// test.insert(std::pair<int, int>(102, 100));
	end1 = clock();

	// double duration1 = (double)(end1 - start1) / CLOCKS_PER_SEC;
    std::cout << (end1 - start1) << "초" << std::endl;

	clock_t start2, end2;

	start2 = clock();

	ft::map<int, int> test1;
	test1.insert(ft::pair<int, int>(3, 5));
	test1.insert(ft::pair<int, int>(1, 20));
	test1.insert(ft::pair<int, int>(5, 30));
	test1.insert(ft::pair<int, int>(7, 10));
	test1.insert(ft::pair<int, int>(10, 100));
	test1.insert(ft::pair<int, int>(15, 100));
	test1.insert(ft::pair<int, int>(17, 100));
	test1.insert(ft::pair<int, int>(20, 100));
	// test1.insert(ft::pair<int, int>(2, 100));
	// test1.insert(ft::pair<int, int>(4, 100));
	// test1.insert(ft::pair<int, int>(6, 100));
	// test1.insert(ft::pair<int, int>(21, 100));
	// test1.insert(ft::pair<int, int>(22, 100));
	// test1.insert(ft::pair<int, int>(23, 100));
	// test1.insert(ft::pair<int, int>(24, 100));
	// test1.insert(ft::pair<int, int>(25, 100));
	// test1.insert(ft::pair<int, int>(26, 100));
	// test1.insert(ft::pair<int, int>(27, 100));
	// test1.insert(ft::pair<int, int>(28, 100));
	// test1.insert(ft::pair<int, int>(39, 100));


	end2 = clock();

	// double duration2 = (double)(end2 - start2) / CLOCKS_PER_SEC;
    std::cout << (end2 - start2) << "초" << std::endl;

	ft::map<int, int> test2;

	test2.insert(ft::pair<int, int>(6, 100));
	test2.insert(ft::pair<int, int>(21, 100));
	test2.insert(ft::pair<int, int>(22, 100));
	test2.insert(ft::pair<int, int>(23, 100));
	test2.insert(ft::pair<int, int>(24, 100));
	test2.insert(ft::pair<int, int>(25, 100));
	test2.insert(ft::pair<int, int>(26, 100));
	test2.insert(ft::pair<int, int>(27, 100));
	test2.insert(ft::pair<int, int>(28, 100));

	test1.swap(test2);


	// std::map<int, int>::iterator it = test.find(1223);
	ft::map<int, int>::iterator it = test2.lower_bound(7);
	std::cout << (*it).first << ", " << (*it).second << std::endl;

	std::map<int, int>::iterator it1 = test.lower_bound(7);
	std::cout << (*it1).first << ", " << (*it1).second << std::endl;

	std::cout << "\n=====================================\n" << std::endl;
	
	test1.print_tree();
	std::cout << "\n=====================================\n" << std::endl;
	// std::cout << test[1] << std::endl;
	// std::cout << test1[1] << std::endl;
	// std::cout << test[2] << std::endl;
	// std::cout << test1[2] << std::endl;
	// std::cout << std::endl;
	// ft::map<int, int>::iterator ft_it = test1.begin();
	// std::map<int, int>::iterator std_it = test.begin();


	// for (; std_it != test.end();) {
	// 	std::cout << "[" << (*std_it).first << ", " << (*ft_it).first << "] [" << (*std_it).second << ", " << (*ft_it).second << "]" << std::endl;
	// 	ft_it++;
	// 	std_it++;
	// }

	print(test2, test);
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