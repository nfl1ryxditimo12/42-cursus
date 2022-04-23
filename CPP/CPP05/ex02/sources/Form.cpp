#include "Form.hpp"

Form::Form()
: name("DefaultForm"),
  signGrade(150),
  executeGrade(150),
  sign(false),
  target("DefaultTarget") {}

Form::Form(std::string name, int signGrade, int executeGrade, std::string target)
: name(name),
  signGrade(signGrade),
  executeGrade(executeGrade),
  target(target)
{
    if (signGrade < 1 || executeGrade < 1)
        throw Form::GradeTooHighException();
    if (signGrade > 150 || signGrade > 150)
        throw Form::GradeTooLowException();
    this->sign = false;
}

Form::Form(const Form &cls)
: name(cls.getName()),
  signGrade(cls.getSignGrade()),
  executeGrade(cls.getExecuteGrade()),
  sign(cls.getSign()),
  target(cls.getTarget()) {}

Form::~Form() {};

Form &Form::operator=(const Form &cls)
{
    this->sign = cls.getSign();
    return *this;
}

void Form::beSigned(const Bureaucrat &cls)
{
    try {
        this->sign = false;
        if (cls.getGrade() > this->getSignGrade())
            throw Form::GradeTooLowException();
        this->sign = true;
    } catch (std::exception &e) {
        std::cout << "\e[0;31m" << cls.getName() << " failed to sign " << this->getName() << "\e[0m" << std::endl;
        throw ;
    }
}

const std::string &Form::getName() const
{
    return this->name;
}

const int &Form::getSignGrade() const
{
    return this->signGrade;
}

const int &Form::getExecuteGrade() const
{
    return this->executeGrade;
}

bool Form::getSign() const
{
    return this->sign;
}

const std::string &Form::getTarget() const
{
    return this->target;
}

const char *Form::GradeTooHighException::what() const throw()
{
    return ("Form: Grade too high!!");
}

const char *Form::GradeTooLowException::what() const throw()
{
    return ("Form: Grade too low!!");
}

const char *Form::NotSigned::what() const throw()
{
    return ("Form: Not signed to this form!!");
}

std::ostream &operator<<(std::ostream &stream, const Form &cls)
{
    stream << "name: " << cls.getName() << ", signGrade: " << cls.getSignGrade();
    stream << ", executeGrade: " << cls.getExecuteGrade() << ", signed: " << cls.getSign();

    return stream;
}
