#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <list>

template <class T>
class MutantStack: public std::stack<T>
{
    
    private:
    
    public:
        typedef typename MutantStack::stack::container_type::iterator iterator;

        MutantStack(): MutantStack::stack() {};
        MutantStack(const MutantStack &cls): MutantStack::stack(cls) {};
        ~MutantStack() {};

        MutantStack &operator=(const MutantStack &cls)
        {
            if (this != &cls)
                MutantStack::stack::operator=(cls);
            return *this;
        };

        iterator begin() { return this->c.begin(); };
        iterator end() { return this->c.end(); };
};

#endif
