#include "iter.hpp"

int main()
{
    std::cout << "============ int ============" << std::endl;

    int intArr[10];

    for (int i = 0; i < 10; i++)
        intArr[i] = i;
    ::iter(intArr, 10, callFunc);

    std::cout << "\n============ char ============" << std::endl;

    char charArr[10];

    for (int i = 97; i < 107; i++)
        charArr[i - 97] = static_cast<char>(i);
    ::iter(charArr, 10, callFunc);

    std::cout << "\n============ string ============" << std::endl;

    std::string strArr[10];

    for (int i = 0; i < 10; i++) {
        strArr[i] = "str";
        strArr[i] += '0' + i;
    }
    ::iter(strArr, 10, callFunc);

    std::cout << std::endl;
}
