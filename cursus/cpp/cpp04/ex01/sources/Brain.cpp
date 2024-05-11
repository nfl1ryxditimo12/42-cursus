#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain Default Constructor" << std::endl;
    for (int i = 0; i < SIZE; i++)
        this->ideas[i] = "brain";
}

Brain::Brain(std::string idea)
{
    std::cout << "Brain String Constructor" << std::endl;
    for (int i = 0; i < SIZE; i++)
        this->ideas[i] = idea;
}

Brain::Brain(const Brain &cls)
{
    std::cout << "Brain Copy Constructor" << std::endl;
    *this = cls;
}

Brain::~Brain()
{
    std::cout << "Brain Destructor" << std::endl;
}

Brain &Brain::operator=(const Brain &cls)
{
    std::cout << "Brain Copy Assignment Operator" << std::endl;
    for (int i = 0; i < SIZE; i++)
        this->ideas[i] = cls.ideas[i];
    return *this;
}

void Brain::printBrain()
{
    for (int i = 0; i < SIZE; i++)
        std::cout << this->ideas[i] << " ";
    std::cout << std::endl;
}