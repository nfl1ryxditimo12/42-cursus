#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"

class WrongCat: public WrongAnimal
{
    private:
    
    public:
        WrongCat();
        WrongCat(const WrongCat &cls);
        ~WrongCat();

        WrongCat &operator=(const WrongCat &cls);

        void makeSound() const;
};

#endif