#include "Serialization.hpp"

int main()
{
    Serialization   serial;
    Data            data;
    uintptr_t       addr;

    std::cout << "Data address: " << &data << std::endl;
    std::cout << "integer: " << *(data.getInteger()) << ", str: " << *(data.getString()) << ", ptr: " << *(data.getPointer()) << std::endl;
    std::cout << std::endl;

    addr = serial.serialize(&data);
    std::cout << "Serialized data address: " << addr << std::endl;
    std::cout << std::endl;

    Data *casting;
    casting = serial.deserialize(addr);
    std::cout << "Deserialized data address: " << casting << std::endl;
    std::cout << "integer: " << *(casting->getInteger()) << ", str: " << *(casting->getString()) << ", ptr: " << *(casting->getPointer()) << std::endl;

    return (0);
}
