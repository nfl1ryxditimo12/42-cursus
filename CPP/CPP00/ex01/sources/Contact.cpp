#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::set_field(std::string field, std::string& member)
{
    while (1)
    {
        std::cout << field;
        if (!std::getline(std::cin, member))
        {
            std::cout << "\nGood bye" << std::endl;
            exit(1);
        }
        
        if (member.length() > 0)
            break ;
    }
}

void Contact::set_contact(int& index)
{
    this->idx = index;

    set_field("First name: ", this->first_name);
    set_field("Last name: ", this->last_name);
    set_field("Nickname: ", this->nickname);
    set_field("Phone number: ", this->phone_number);
    set_field("Darkest secret: ", this->darkest_secret);
}

std::string Contact::get_first_name(void)
{
    return this->first_name;
}

std::string Contact::get_last_name(void)
{
    return this->last_name;
}

std::string Contact::get_nickname(void)
{
    return this->nickname;
}

std::string Contact::get_phone_number(void)
{
    return this->phone_number;
}

std::string Contact::get_darkest_secret(void)
{
    return this->darkest_secret;
}