#ifndef INTERN_HPP
# define INTERN_HPP

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern
{
    private:

    public:
        Intern();
        Intern(const Intern &cls);
        ~Intern();

        Intern &operator=(const Intern &cls);

        Form *makeForm(std::string form, std::string target);
        Form *createShrubberyCreationForm(std::string target);
        Form *createRobotomyRequestForm(std::string target);
        Form *createPresidentialPardonForm(std::string target);
        int NothingForm(void);

        class Nothing: public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif