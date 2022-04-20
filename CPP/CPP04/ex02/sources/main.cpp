#include "Dog.hpp"
#include "Cat.hpp"

int main()
{
    Cat *cat1 = new Cat();
    Cat *cat2 = new Cat("meow");

    std::cout << std::endl;

    cat1->getBrainAddr();
    cat2->getBrainAddr();

    std::cout << std::endl;
    cat1->getBrainValue();
    cat2->getBrainValue();
    std::cout << std::endl;

    Cat cat3(*cat1);
    *cat1 = *cat2;

    std::cout << std::endl;
    cat1->getBrainAddr();
    cat2->getBrainAddr();
    cat3.getBrainAddr();

    std::cout << std::endl;
    cat1->getBrainValue();
    cat2->getBrainValue();
    cat3.getBrainValue();
    std::cout << std::endl;
    
    delete cat1;
    delete cat2;
    
    return 0;
}
