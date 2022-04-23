#include "Intern.hpp"

int main()
{
    std::string forms[4] = {
        "ShrubberyCreation",
        "RobotomyRequest",
        "PresidentialPardon",
        "Nothing"
    };

    try {
        Bureaucrat man("man", 1);
        Intern intern;
        Form *form;

        for (int i = 0; i < 4; i++) {
            form = intern.makeForm(forms[i], forms[i]);
            form->beSigned(man);
            man.executeForm(*form);
            std::cout << std::endl;
        }
    } catch (std::exception &e) {
        std::cerr << "\e[0;31m" << e.what() << "\e[0m" << std::endl;
    }
}