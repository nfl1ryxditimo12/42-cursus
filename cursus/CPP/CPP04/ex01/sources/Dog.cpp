#include "Dog.hpp"

Dog::Dog()
{
    std::cout << "Dog Default Constructor" << std::endl;
    this->type = "Dog";
    this->brain = new Brain();
}

Dog::Dog(std::string idea)
{
    std::cout << "Dog String Constructor" << std::endl;
    this->type = "Dog";
    this->brain = new Brain(idea);
}

Dog::Dog(const Dog &cls)
{
    std::cout << "Dog Copy Constructor" << std::endl;
    this->brain = new Brain();
    *this = cls;
}

Dog::~Dog()
{
    std::cout << "Dog Destructor" << std::endl;
    delete this->brain;
}

Dog &Dog::operator=(const Dog &cls)
{
    std::cout << "Dog Copy Assignment Operator" << std::endl;
    this->Animal::operator=(cls);
    delete this->brain;
    *this->brain = *(cls.brain);
    
    return *this;
}

void Dog::makeSound() const
{
    std::cout << "Bow!! Bow!! Bow!!" << std::endl;
}
