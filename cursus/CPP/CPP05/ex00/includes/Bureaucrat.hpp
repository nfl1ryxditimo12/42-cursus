#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>

class Bureaucrat
{
    private:
        const std::string   name;
        int                 grade;
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int grade);
        Bureaucrat(const Bureaucrat &cls);
        ~Bureaucrat();

        Bureaucrat &operator=(const Bureaucrat &cls);

        const std::string &getName() const;
        const int &getGrade() const;
        void increaseGrade(int amount);
        void decreaseGrade(int amount);

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

std::ostream &operator<<(std::ostream &stream, const Bureaucrat &cls);

#endif