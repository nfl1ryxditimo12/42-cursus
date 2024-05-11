#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include "Data.hpp"

class Data;

class Serialization
{
    private:
        std::ofstream writeFile;

    public:
        Serialization();
        Serialization(const Serialization &cls);
        ~Serialization();

        Serialization &operator=(const Serialization &cls);

        uintptr_t serialize(Data* ptr);
        Data *deserialize(uintptr_t raw);
};

#endif
