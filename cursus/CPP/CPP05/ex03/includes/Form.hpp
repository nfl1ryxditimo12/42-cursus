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
        const std::string   target;
    
    public:
        Form();
        Form(std::string name, int signGrade, int executeGrade, std::string target);
        Form(const Form &cls);
        virtual ~Form();

        Form &operator=(const Form &cls);

        virtual void execute(Bureaucrat const &executor) const = 0;
        void beSigned(const Bureaucrat &cls);
        const std::string &getName() const;
        const int &getSignGrade() const;
        const int &getExecuteGrade() const;
        bool getSign() const;
        const std::string &getTarget() const;

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

        class NotSigned: public std::exception
        {
            public:
                const char *what() const throw();
        };
};

std::ostream &operator<<(std::ostream &stream, const Form &cls);

#endif