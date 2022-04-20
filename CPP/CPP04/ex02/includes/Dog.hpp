#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog: public Animal
{
    private:
        Brain *brain;
    public:
        Dog();
        Dog(std::string idea);
        Dog(const Dog &cls);
        ~Dog();

        Dog &operator=(const Dog &cls);

        void makeSound() const;
};

#endif