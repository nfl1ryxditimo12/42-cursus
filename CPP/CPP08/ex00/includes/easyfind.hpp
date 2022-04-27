#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <algorithm>
# include <vector>
# include <deque>
# include <stack>

class notFound: public std::exception
{
    public:
        const char *what() const throw() {
            return ": Not Found";
        }
};

template<class T>
void easyfind(T container, int idx)
{
    typename T::iterator iter;

    iter = std::find(container.begin(), container.end(), idx);
    std::cout << idx;
    if (iter == container.end())
        throw notFound();
    std::cout << ": Found!!" << std::endl;
}

#endif
