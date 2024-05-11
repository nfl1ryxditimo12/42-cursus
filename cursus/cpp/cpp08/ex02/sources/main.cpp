#include "MutantStack.hpp"

int main()
{
    MutantStack<int> mstack;
    std::list<int> list;

    mstack.push(5);
    mstack.push(17);
    mstack.pop();
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    list.push_back(5);
    list.push_back(17);
    list.pop_back();
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);



    MutantStack<int>::iterator stackIter = mstack.begin();
    MutantStack<int>::iterator stackIterEnd = mstack.end();
    std::list<int>::iterator listIter = list.begin();
    std::list<int>::iterator listIterEnd = list.end();

    ++stackIter;
    --stackIter;

    std::cout << "==================================\n" << std::endl;

    std::cout << "Mutant Stack Iterator: ";
    while (stackIter != stackIterEnd) {
        std::cout << *stackIter << " ";
        ++stackIter;
    }
    std::cout << std::endl;
    std::cout << "Mutant Stack Size: " << mstack.size() << std::endl;
    std::cout << "Mutant Stack Top: "<< mstack.top() << std::endl;

    std::cout << "\n==================================\n" << std::endl;

    std::cout << "List Iterator: ";
    while (listIter != listIterEnd) {
        std::cout << *listIter << " ";
        ++listIter;
    }
    std::cout << std::endl;
    std::cout << "List Size: " << list.size() << std::endl;
    std::cout << "List Top: "<< list.back() << std::endl;

    std::cout << "\n==================================\n" << std::endl;

    std::stack<int> s(mstack);
    std::stack<int> tmp(s);

    std::cout << "Origin Stack Values: ";
    while (tmp.size()) {
        std::cout << tmp.top() << " ";
        tmp.pop();
    }
    std::cout << std::endl;
    std::cout << "Origin Stack Size: " << s.size() << std::endl;
    std::cout << "Origin Stack Top: "<< s.top() << std::endl;

    std::cout << "\n==================================" << std::endl;

    return 0;
}
