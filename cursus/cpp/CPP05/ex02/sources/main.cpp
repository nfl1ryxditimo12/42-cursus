#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


int main()
{
    try {
        Bureaucrat man("man", 25);
        ShrubberyCreationForm berry("ShrubberyCreation");
        RobotomyRequestForm robot("RobotomyRequest");
        PresidentialPardonForm pardon("PresidentialPardon");

        berry.beSigned(man);
        man.executeForm(berry);

        std::cout << std::endl;

        robot.beSigned(man);
        man.executeForm(robot);

        std::cout << std::endl;

        pardon.beSigned(man);
        man.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}