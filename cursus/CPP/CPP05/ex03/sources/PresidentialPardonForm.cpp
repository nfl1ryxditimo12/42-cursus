#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target)
: Form("PresidentialPardon", 25, 5, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &cls)
: Form(cls) {}

PresidentialPardonForm::~PresidentialPardonForm() {std::cout << "dd" << std::endl;}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &cls)
{
    this->Form::operator=(cls);
    return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
    std::cout << "Informs that \"" << executor.getName() << "\" has been pardoned by Zaphod Beeblebrox" << std::endl;
}