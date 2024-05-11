#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
: Form("ShrubberyCreation", 145, 137, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &cls)
: Form(cls) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {std::cout << "dd" << std::endl;}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &cls)
{
    this->Form::operator=(cls);
    return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    std::ofstream writeFile(this->getTarget() + "_shrubbery", std::ofstream::trunc);

    if (!writeFile.is_open())
        throw ShrubberyCreationForm::FileOpenFailure();
    
    writeFile << "ex02\n";
    writeFile << "├─── includes\n";
    writeFile << "│    └──── Bureaucrat.hpp\n";
    writeFile << "│    └──── Form.hpp\n";
    writeFile << "│    └──── PresidentialPardonForm.hpp\n";
    writeFile << "│    └──── RobotomyRequestForm.hpp\n";
    writeFile << "│    └──── ShrubberyCreationForm.hpp\n";
    writeFile << "├─── sources\n";
    writeFile << "│    └──── Bureaucrat.cpp\n";
    writeFile << "│    └──── Form.cpp\n";
    writeFile << "│    └──── main.cpp\n";
    writeFile << "│    └──── PresidentialPardonForm.cpp\n";
    writeFile << "│    └──── RobotomyRequestForm.cpp\n";
    writeFile << "│    └──── ShrubberyCreationForm.cpp\n";
    writeFile << "└─── Makefile";

    writeFile.close();

    std::cout << "\"" << executor.getName() << "\" successfully create \"" << this->getTarget() << "_shrubbery\" file!!" << std::endl;
}

const char *ShrubberyCreationForm::FileOpenFailure::what() const throw()
{
    return ("Output file is not open!!");
}