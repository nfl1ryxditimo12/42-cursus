#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog: public Animal
{
    private:
    
    public:
        Dog();
        Dog(const Dog &cls);
        ~Dog();

        Dog &operator=(const Dog &cls);

        void makeSound() const;
};

#endif