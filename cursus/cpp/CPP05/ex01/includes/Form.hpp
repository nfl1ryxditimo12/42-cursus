#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
    private:
        const std::string   name;
        const int           signGrade;
        const int           executeGrade;
        bool                sign;
    
    public:
        Form();
        Form(std::string name, int signGrade, int executeGrade);
        Form(const Form &cls);
        ~Form();

        Form &operator=(const Form &cls);

        void beSigned(const Bureaucrat &cls);
        const std::string &getName() const;
        const int &getSignGrade() const;
        const int &getExecuteGrade() const;
        bool getSign() const;

        class GradeTooHighException: public std::exception
        {
            public:
                const char *what() const throw();
        };

        class GradeTooLowException: public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, const Form &cls);

#endif