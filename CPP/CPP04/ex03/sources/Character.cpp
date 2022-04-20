#include "Character.hpp"

Character::Character(): type("default")
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
}

Character::Character(std::string type): type(type)
{
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
}

Character::Character(const Character &cls) { *this = cls; }

Character::~Character() {}

Character &Character::operator=(const Character &cls)
{
    this->type = cls.type;
    for (int i = 0; i < 4; i++) {
        if (this->slot[i] != NULL) delete this->slot[i];
        this->slot[i] = cls.slot[i]->clone();
    }
    return *this;
}

std::string const &Character::getName() const
{
    return this->type;
}

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
        if (this->slot[i] == NULL) {
            this->slot[i] = m;
            return ;
        }
}

void Character::unequip(int idx)
{
    if (idx >= 0 && idx <= 3) {
        this->slot[idx] = NULL;
    }
}

void Character::use(int idx, ICharacter &target)
{
    if (idx >= 0 && idx <= 3 && this->slot[idx] != NULL)
        this->slot[idx]->use(target);
}