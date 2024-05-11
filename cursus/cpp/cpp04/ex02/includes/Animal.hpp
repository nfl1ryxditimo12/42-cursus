#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>

class Animal
{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &cls);
        virtual ~Animal();

        Animal &operator=(const Animal &cls);

        virtual void makeSound() const = 0;
        std::string getType() const;
};

#endif