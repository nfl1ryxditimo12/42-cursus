#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *brain;
    public:
        Cat();
        Cat(std::string idea);
        Cat(const Cat &cls);
        ~Cat();

        Cat &operator=(const Cat &cls);

        void makeSound() const;
        void getBrainAddr() const;
        void getBrainValue() const;
};

#endif