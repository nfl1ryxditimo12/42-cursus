#ifndef TEST_HPP
# define TEST_HPP

# include <iostream>
# include <vector>
# include <stack>
# include <map>

# include "vector.hpp"
# include "stack.hpp"
# include "map.hpp"
# include "utils.hpp"

#define NC "\e[0m"
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define CYN "\e[0;36m"


/*************************************/
/*      Vector Compare Function      */
/*************************************/

template <class T>
void print(ft::vector<T> const &ft_vec, std::vector<T> const &std_vec)
{
	std::cout << CYN << "max_size" << NC << " [" << (ft_vec.max_size() == std_vec.max_size() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_vec.max_size() << ", std: " << std_vec.max_size() << std::endl;
	std::cout << CYN << "size" << NC << "     [" << (ft_vec.size() == std_vec.size() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_vec.size() << ", std: " << std_vec.size() << std::endl;
	std::cout << CYN << "capacity" << NC << " [" << (ft_vec.capacity() == std_vec.capacity() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_vec.capacity() << ", std: " << std_vec.capacity() << std::endl;
	std::cout << CYN << "Internal values" << NC << " [";
	size_t size = std::max(std_vec.size(), ft_vec.size());
	for (size_t i = 0; i < size; i++) {
		if (std_vec[i] != ft_vec[i]) {
			std::cout << "\e[0;31mFALSE\e[0m]" << std::endl;
			break;
		}
		if (i == size - 1)
			std::cout << "\e[0;32mOK\e[0m]" << std::endl;
	}
	if (ft_vec.size() == 0 && std_vec.size() == ft_vec.size())
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
	std::cout << "\n" << std::endl;
}

/*************************************/
/*       Map Compare Function        */
/*************************************/

template <class Key, class Value>
void print(ft::map<Key, Value> const &ft_map, std::map<Key, Value> const &std_map)
{
	std::cout << CYN << "max_size" << NC << " [" << (ft_map.max_size() == std_map.max_size() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_map.max_size() << ", std: " << std_map.max_size() << std::endl;
	std::cout << CYN << "size" << NC << "     [" << (ft_map.size() == std_map.size() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_map.size() << ", std: " << std_map.size() << std::endl;
	// std::cout << CYN << "capacity" << NC << " [" << (ft_map.capacity() == std_map.capacity() ? "\e[0;32mOK\e[0m" : "\e[0;31mFALSE\e[0m") << "] - ft: " << ft_vec.capacity() << ", std: " << std_vec.capacity() << std::endl;
	std::cout << CYN << "Internal values" << NC << " [";
	size_t size = std::max(std_map.size(), ft_map.size());
	typename ft::map<Key, Value>::const_iterator iter1 = ft_map.begin();
	typename std::map<Key, Value>::const_iterator iter2 = std_map.begin();
	for (size_t i = 0; i < size; i++, iter1++, iter2++) {
		if ((*iter1).first != (*iter2).first || (*iter1).second != (*iter2).second) {
			std::cout << "\e[0;31mFALSE\e[0m]" << std::endl;
			break;
		}
		if (i == size - 1)
			std::cout << "\e[0;32mOK\e[0m]" << std::endl;
	}
	if (ft_map.size() == 0 && std_map.size() == ft_map.size())
		std::cout << "\e[0;32mOK\e[0m]" << std::endl;
	std::cout << "[ft::map]  :";
	for (typename ft::map<Key, Value>::const_iterator it = ft_map.begin(); it != ft_map.end(); it++) {
		std::cout << " [" << (*it).first << ", " << (*it).second << "]";
	}
	std::cout << std::endl;
	std::cout << "[std::map] :";
	for (typename std::map<Key, Value>::const_iterator it = std_map.begin(); it != std_map.end(); it++) {
		std::cout << " [" << (*it).first << ", " << (*it).second << "]";
	}
	std::cout << "\n" << std::endl;
}




#endif