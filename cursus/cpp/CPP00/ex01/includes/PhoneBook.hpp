#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <iomanip>

class PhoneBook
{
    private:
        Contact contact[8];
        int     count;
    public:
        PhoneBook(void);
        ~PhoneBook(void);

        void add_contact(void);
        void get_contact(void);
};

#endif