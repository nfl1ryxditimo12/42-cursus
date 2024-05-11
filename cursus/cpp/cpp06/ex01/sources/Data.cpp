#include "Data.hpp"

Data::Data(): integer(1), str("DefaultData"), ptr(&integer) {}

Data::Data(const Data &cls)
{
    *this = cls;
}

Data::~Data() {}

Data &Data::operator=(const Data &cls)
{
    this->integer = cls.integer;
    this->str = cls.str;
    this->ptr = cls.ptr;
    return *this;
}

int *Data::getInteger()
{
    return &(this->integer);
}

std::string *Data::getString()
{
    return &(this->str);
}

int **Data::getPointer()
{
    return &(this->ptr);
}
