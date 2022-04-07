#include "Contact.hpp"

Contact::Contact(void)
{
}

Contact::~Contact(void)
{
}

void Contact::set_contact(int& index)
{
    this->idx = index;
    std::cout << "First name: ";
    std::getline(std::cin, this->first_name);
    std::cout << "Last name: ";
    std::getline(std::cin, this->last_name);
    std::cout << "Nickname: ";
    std::getline(std::cin, this->nickname);
    std::cout << "Phone number: ";
    std::getline(std::cin, this->phone_number);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, this->darkest_secret);
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