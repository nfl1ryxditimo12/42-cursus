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

    if (input.length() != 1)
        return (-1);
    if (!(48 <= static_cast<int>(input[0]) && static_cast<int>(input[0]) <= 55))
        return (-1);

    number = static_cast<int>(input[0]) - 48;
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
    std::string init_seperator = "+----------+----------+----------+----------+";
    std::string init_title = "|    INDEX |   F_NAME |   L_NAME | NICKNAME |";
    std::string search_seperator = "+----------+----------+----------+----------+----------+----------+";
    std::string search_title = "|    INDEX |   F_NAME |   L_NAME | NICKNAME |    PHONE |   SECRET |";
    int         i;

    std::cout << init_seperator << std::endl;
    std::cout << init_title << std::endl;
    std::cout << init_seperator << std::endl;

    for (int j = 0; j < (this->count > 8 ? 8 : this->count); j++) {
        std::cout << "|" << std::setw(10) << j << "|";
        printColumn(this->contact[j].get_first_name());
        printColumn(this->contact[j].get_last_name());
        printColumn(this->contact[j].get_nickname());
        std::cout << std::endl;
        std::cout << init_seperator << std::endl;
    }

    while (1)
    {
        std::cout << "Index number: ";
        if (!std::getline(std::cin, input)) {
            std::cout << "\nGood bye" << std::endl;
            exit(1);
        };
        if ((i = str_to_number(input, this->count)) == -1) {
            std::cout << "Incorrect number!!" << std::endl;
            return ;
        }

        std::cout << search_seperator << std::endl;
        std::cout << search_title << std::endl;
        std::cout << search_seperator << std::endl;
        std::cout << "|" << std::setw(10) << i << "|";
        printColumn(this->contact[i].get_first_name());
        printColumn(this->contact[i].get_last_name());
        printColumn(this->contact[i].get_nickname());
        printColumn(this->contact[i].get_phone_number());
        printColumn(this->contact[i].get_darkest_secret());
        std::cout << std::endl;
        std::cout << search_seperator << std::endl;
    }
}