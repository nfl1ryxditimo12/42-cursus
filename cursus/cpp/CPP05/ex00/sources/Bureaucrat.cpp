#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("default"), grade(1) {}

Bureaucrat::Bureaucrat(std::string name, int grade): name(name)
{
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cls): name(cls.getName()), grade(cls.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &cls)
{
    this->grade = cls.grade;

    return *this;
}

const std::string &Bureaucrat::getName() const
{
    return this->name;
}

const int &Bureaucrat::getGrade() const
{
    return this->grade;
}

void Bureaucrat::increaseGrade(int amount)
{
    if (this->grade - amount < 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade -= amount;
}

void Bureaucrat::decreaseGrade(int amount)
{
    if (this->grade + amount > 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade += amount;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return ("Bureaucrat: Grade too high!!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
    return ("Bureaucrat: Grade too low!!");
}

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &cls)
{
    stream << cls.getName() << ", bureaucrat grade " << cls.getGrade() << ".";

    return stream;
}