#include "Cat.hpp"

Cat::Cat()
{
    std::cout << "Cat Default Constructor" << std::endl;
    this->type = "Cat";
    this->brain = new Brain();
}

Cat::Cat(std::string idea)
{
    std::cout << "Cat String Constructor" << std::endl;
    this->type = "Cat";
    this->brain = new Brain(idea);
}

Cat::Cat(const Cat &cls)
{
    std::cout << "Cat Copy Constructor" << std::endl;
    this->brain = new Brain();
    *this = cls;
}

Cat::~Cat()
{
    std::cout << "Cat Destructor" << std::endl;
    delete this->brain;
}

Cat &Cat::operator=(const Cat &cls)
{
    std::cout << "Cat Copy Assignment Operator" << std::endl;
    this->Animal::operator=(cls);
    delete this->brain;
    this->brain = new Brain(*(cls.brain));

    return *this;
}

void Cat::makeSound() const
{
    std::cout << "Meeeeeeoooowww~" << std::endl;
}

void Cat::getBrainAddr() const
{
    std::cout << "Cat's brain addr is " << &this->brain << std::endl;
}

void Cat::getBrainValue() const
{
    this->brain->printBrain();
}
