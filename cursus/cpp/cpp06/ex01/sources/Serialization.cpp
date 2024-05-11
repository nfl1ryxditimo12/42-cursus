#include "Serialization.hpp"

Serialization::Serialization(): writeFile("serial.txt", std::ofstream::trunc)
{}

Serialization::Serialization(const Serialization &cls)
{
    *this = cls;
}

Serialization::~Serialization() {}

Serialization &Serialization::operator=(const Serialization &cls)
{
    (void)cls;
    return *this;
}

uintptr_t Serialization::serialize(Data *ptr)
{
    uintptr_t addr = reinterpret_cast<uintptr_t>(ptr);
    std::stringstream buffer;

    buffer << "=================================\n";
    buffer << "Origin Data\n\n";
    buffer << "Integer Value: " << *(ptr->getInteger()) << "\n";
    buffer << "Integer Address: " << ptr->getInteger() << "\n";
    buffer << "String Value: \"" << *(ptr->getString()) << "\"\n";
    buffer << "String Address: " << ptr->getString() << "\n";
    buffer << "Pointer Reference Value: " << **(ptr->getPointer()) << "\n";
    buffer << "Pointer Value: " << *(ptr->getPointer()) << "\n";
    buffer << "Pointer Address: " << (ptr->getPointer()) << "\n";
    buffer << "=================================\n\n";

    writeFile << buffer.str();

    return addr;
}

Data *Serialization::deserialize(uintptr_t raw)
{
    Data *deserial = reinterpret_cast<Data *>(raw);
    std::stringstream buffer;

    buffer << "=================================\n";
    buffer << "Serialized Address: " << raw << "\n";
    buffer << "=================================\n\n";

    buffer << "=================================\n";
    buffer << "Deserialized Data\n\n";
    buffer << "Integer Value: " << *(deserial->getInteger()) << "\n";
    buffer << "Integer Address: " << deserial->getInteger() << "\n";
    buffer << "String Value: \"" << *(deserial->getString()) << "\"\n";
    buffer << "String Address: " << deserial->getString() << "\n";
    buffer << "Pointer Reference Value: " << **(deserial->getPointer()) << "\n";
    buffer << "Pointer Value: " << *(deserial->getPointer()) << "\n";
    buffer << "Pointer Address: " << (deserial->getPointer()) << "\n";
    buffer << "=================================\n";

    writeFile << buffer.str();
    writeFile.close();

    return deserial;
}
