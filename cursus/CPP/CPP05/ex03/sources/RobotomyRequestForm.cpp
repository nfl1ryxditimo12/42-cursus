#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target)
: Form("RobotomyRequest", 72, 45, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &cls)
: Form(cls) {}

RobotomyRequestForm::~RobotomyRequestForm() {std::cout << "dd" << std::endl;}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &cls)
{
    this->Form::operator=(cls);
    return *this;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
    std::cout << "🛠 Drrrrrrrriillllllll 🛠" << std::endl;

    std::srand(std::time(NULL));
    if (std::rand() % 2 == 0)
        std::cout << "Robotomized to \"" << executor.getName() << "\" successfully!!" << std::endl;
    else
        std::cout << "Robotomized to \"" << executor.getName() << "\" fail.." << std::endl;
}