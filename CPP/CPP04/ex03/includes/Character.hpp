#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"

class Character: public ICharacter
{
    private:
        AMateria *slot[4];
        std::string type;

    public:
        Character();
        Character(std::string type);
        Character(const Character &cls);
        ~Character();

        Character &operator=(const Character &cls);

        std::string const &getName() const;
        void equip(AMateria *m);
        void unequip(int idx);
        void use(int idx, ICharacter &target);
};

#endif
