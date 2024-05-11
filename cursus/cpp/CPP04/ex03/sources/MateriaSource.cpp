#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
    for (int i = 0; i < 4; i++)
        this->slot[i] = NULL;
};

MateriaSource::MateriaSource(const MateriaSource &cls) { *this = cls; }

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
        if (this->slot[i] != NULL) {
            delete this->slot[i];
            this->slot[i] = NULL;
        }
}

MateriaSource &MateriaSource::operator=(const MateriaSource &cls)
{
    if (this == &cls) return *this;
    for (int i = 0; i < 4; i++) {
        if (this->slot[i] != NULL) delete this->slot[i];
        this->slot[i] = cls.slot[i]->clone();
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria *m)
{
    for (int i = 0; i < 4; i++) {
        if (this->slot[i] == NULL) {
            this->slot[i] = m;
            return ;
        }
    }
}

AMateria *MateriaSource::createMateria(std::string const &type)
{
    for (int i = 0; i < 4; i++) {
        if (this->slot[i] != NULL && this->slot[i]->getType() == type)
            return this->slot[i];
    }
    return NULL;
}