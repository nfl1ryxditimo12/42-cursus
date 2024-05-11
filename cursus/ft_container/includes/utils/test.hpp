#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <map>
# include <time.h>

# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"
# include "utils.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define YLW "\e[0;33m"
#define CYN "\e[0;36m"

#define LINE "====================================================================\n"

void	vector_test(void);
void	map_test(void);

/*************************************/
/*       Time Compare Function       */
/*************************************/

template <class T>
void compare_time(T f_time, T s_time)
{
	std::cout << CYN << "compare_time" << NC << " [" << \
		((f_time <= s_time * 20)
			? "\e[0;32mOK\e[0m"
			: "\e[0;31mFALSE\e[0m") << "] - ft: " \
		<< YLW << f_time << "ms" << NC << ", std: " \
		<< YLW << s_time << "ms" << NC << \
	std::endl;
}

template <class T>
T	sub_time(T t1, T t2)
{
	return (t2 - t1);
}

/*************************************/
/*      Vector Compare Function      */
/*************************************/

template <class T>
void print(ft::vector<T> const &ft_vec, std::vector<T> const &std_vec, bool time = false, clock_t f_time = 0, clock_t s_time = 0)
{
	std::cout << LINE << std::endl;
	std::cout << CYN << "max_size" << NC << " [" << (ft_vec.max_size() == std_vec.max_size() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_vec.max_size() << ", std: " << std_vec.max_size() << std::endl;
	std::cout << CYN << "size" << NC << "     [" << (ft_vec.size() == std_vec.size() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_vec.size() << ", std: " << std_vec.size() << std::endl;
	std::cout << CYN << "capacity" << NC << " [" << (ft_vec.capacity() == std_vec.capacity() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_vec.capacity() << ", std: " << std_vec.capacity() << std::endl;
	typename ft::vector<T>::const_iterator f_it = ft_vec.begin();
	typename std::vector<T>::const_iterator s_it = std_vec.begin();
	int	flag = 1;
	std::cout << CYN << "Internal values" << NC << " [";
	for (; (f_it < ft_vec.end() || s_it < std_vec.end()); f_it++, s_it++) {
		if (*f_it != *s_it) {
			std::cout << "\e[0;31mFALSE\e[0m]" << std::endl;
			flag = 0;
			break;
		}
	}
	if (flag && (f_it == ft_vec.end() && s_it == std_vec.end()))
		std::cout << "\e[0;32mOK\e[0m]" << std::endl;
	std::cout << "[ft::vector]  :";
	for (typename ft::vector<T>::const_iterator it = ft_vec.begin(); it < ft_vec.end(); it++) {
		if (it == ft_vec.begin())
			std::cout << " " << *it;
		else
        	std::cout << ", " << *it;
	}
	std::cout << std::endl;
	std::cout << "[std::vector] :";
	for (typename std::vector<T>::const_iterator it = std_vec.begin(); it < std_vec.end(); it++) {
		if (it == std_vec.begin())
			std::cout << " " << *it;
		else
        	std::cout << ", " << *it;
	}
	std::cout << std::endl;
	if (time != false)
		compare_time(f_time, s_time);
	std::cout << std::endl;
}

/*************************************/
/*       Map Compare Function        */
/*************************************/

template <class Key, class Value>
void print(ft::map<Key, Value> const &ft_map, std::map<Key, Value> const &std_map, bool time = false, clock_t f_time = 0, clock_t s_time = 0)
{
	std::cout << LINE << std::endl;
	typename ft::map<Key, Value>::const_iterator ft_it = ft_map.begin();
	typename std::map<Key, Value>::const_iterator std_it = std_map.begin();
	int flag = 0;

	std::cout << CYN << "max_size" << NC << " [" << (ft_map.max_size() == std_map.max_size() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_map.max_size() << ", std: " << std_map.max_size() << std::endl;
	std::cout << CYN << "size" << NC << "     [" << (ft_map.size() == std_map.size() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_map.size() << ", std: " << std_map.size() << std::endl;
	std::cout << CYN << "Internal values" << NC << " [";

	// while (std_it != std_map.end() || ft_it != ft_map.end()) {
	// 	if ((*std_it).first != (*ft_it).first || (*std_it).second != (*ft_it).second) {
	// 		std::cout << "\e[0;31mFALSE\e[0m]" << std::endl;
	// 		flag = 1;
	// 		break;
	// 	}
	// 	++std_it;
	// 	++ft_it;
	// }

	for (; std_it != std_map.end() || ft_it != ft_map.end(); std_it++, ft_it++) {
		if ((*std_it).first != (*ft_it).first || (*std_it).second != (*ft_it).second) {
			std::cout << "\e[0;31mFALSE\e[0m]" << std::endl;
			flag = 1;
			break;
		}
	}

	if (!flag) {
		if (ft_map.size() == 0 && std_map.size() == ft_map.size())
			std::cout << "\e[0;32mOK\e[0m]" << std::endl;
		else if (std_it != std_map.end() || ft_it != ft_map.end())
			std::cout << "\e[0;31mFALSE\e[0m]" << std::endl;
		else
			std::cout << "\e[0;32mOK\e[0m]" << std::endl;
	}

	std::cout << YLW << "[ft::map]  -" << NC;
	for (typename ft::map<Key, Value>::const_iterator it = ft_map.begin(); it != ft_map.end(); it++) {
		std::cout << " [" << (*it).first << ", " << (*it).second << "]";
	}
	std::cout << std::endl;
	
	std::cout << YLW << "[std::map] -" << NC;
	for (typename std::map<Key, Value>::const_iterator it = std_map.begin(); it != std_map.end(); it++) {
		std::cout << " [" << (*it).first << ", " << (*it).second << "]";
	}
	std::cout << std::endl;
	if (time != false)
		compare_time(f_time, s_time);
	std::cout << std::endl;
}




#endif