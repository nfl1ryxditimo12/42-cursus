#include "PhoneBook.hpp"
#include <limits>

int main()
{
    PhoneBook book;
    std::string command;

    while (1)
    {
        std::cout << "Command: ";
        if (!std::getline(std::cin, command))
        {
            std::cout << "\nGood bye" << std::endl;
            return (1);
        }
        
        if (command.compare("ADD") == 0)
            book.add_contact();
        else if (command.compare("SEARCH") == 0)
            book.get_contact();
        else if (command.compare("EXIT") == 0)
            break ;
        else
            std::cout << "Wrong Input!!" << std::endl;
    }
    std::cout << "Good bye" << std::endl;
    return (0);
}