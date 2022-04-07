#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void): count(0)
{
}

PhoneBook::~PhoneBook(void)
{
}

void PhoneBook::add_contact(void)
{
    this->contact[this->count % 8].set_contact(this->count);
    this->count++;
}

int str_to_number(std::string input, int count)
{
    int number = 0;

    if (!input.length())
        return (-1);
    for (int i = 0; i < (int)input.length(); i++) {
        if (!(48 <= static_cast<int>(input[i]) && static_cast<int>(input[i]) <= 57))
            return (-1);
        number = number * 10 + (static_cast<int>(input[i]) - 48);
    }
    if (number > count - 1)
        return (-1);
    return (number);
}

void printColumn(std::string str)
{
    if (str.length() <= 10) {
        std::cout << std::setw(10) << str;
    } else {
        std::cout << str.substr(0, 9) << ".";
    }
    std::cout << "|";
}

void PhoneBook::get_contact(void)
{
    std::string input;
    std::string seperator = "+----------+----------+----------+----------+";
    int         i;

    while (1)
    {
        std::cout << "Index number: ";
        std::getline(std::cin, input);
        if ((i = str_to_number(input, this->count)) == -1) {
            std::cout << "Incorrect number!!" << std::endl;
            return ;
        }

        std::cout << seperator << std::endl;
        std::cout << "|    INDEX |   F_NAME |   L_NAME | NICKNAME |" << std::endl;
        std::cout << seperator << std::endl;
        std::cout << "|" << std::setw(10) << i << "|";
        printColumn(this->contact[i].get_first_name());
        printColumn(this->contact[i].get_last_name());
        printColumn(this->contact[i].get_nickname());
        std::cout << std::endl;
        std::cout << seperator << std::endl;
    }
}