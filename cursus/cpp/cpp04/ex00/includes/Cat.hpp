#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"

class Cat: public Animal
{
    private:
    
    public:
        Cat();
        Cat(const Cat &cls);
        ~Cat();

        Cat &operator=(const Cat &cls);

        void makeSound() const;
};

#endif