#include "Intern.hpp"

Intern::Intern() {}

Intern::Intern(const Intern &cls)
{
    *this = cls;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &cls)
{
    (void)cls;
    return *this;
}

Form *Intern::makeForm(std::string form, std::string target)
{
    std::string list[3] = {
        "ShrubberyCreation",
        "RobotomyRequest",
        "PresidentialPardon"
    };
    Form *(Intern::*intern[3])(std::string target);
    int idx = -1;

    intern[0] = &Intern::createShrubberyCreationForm;
    intern[1] = &Intern::createRobotomyRequestForm;
    intern[2] = &Intern::createPresidentialPardonForm;
    
    for (int i = 0; i < 3; i++)
        ((list[i] == form) && (idx = i));

    ((idx == -1) && NothingForm());

    return (this->*intern[idx])(target);
}

Form *Intern::createShrubberyCreationForm(std::string target)
{
    return (new ShrubberyCreationForm(target));
}

Form *Intern::createRobotomyRequestForm(std::string target)
{
    return (new RobotomyRequestForm(target));
}

Form *Intern::createPresidentialPardonForm(std::string target)
{
    return (new PresidentialPardonForm(target));
}

int Intern::NothingForm(void)
{
    throw Intern::Nothing();
    return (1);
}

const char *Intern::Nothing::what() const throw()
{
    return ("Intern: cannot find form!!");
}
