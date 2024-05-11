#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>

class WrongAnimal
{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &cls);
        ~WrongAnimal();

        WrongAnimal &operator=(const WrongAnimal &cls);

        void makeSound() const;
        std::string getType() const;
};

#endif