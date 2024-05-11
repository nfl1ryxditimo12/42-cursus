#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
    private:
        int         idx;
        std::string first_name;
        std::string last_name;
        std::string nickname;
        std::string phone_number;
        std::string darkest_secret;
    public:
        Contact(void);
        ~Contact(void);

        void set_contact(int& idx);
        void set_field(std::string field, std::string& member);
        std::string get_first_name(void);
        std::string get_last_name(void);
        std::string get_nickname(void);
        std::string get_phone_number(void);
        std::string get_darkest_secret(void);
};

#endif