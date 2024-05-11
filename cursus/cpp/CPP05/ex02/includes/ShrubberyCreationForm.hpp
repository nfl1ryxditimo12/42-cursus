#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <fstream>

# include "Form.hpp"

class ShrubberyCreationForm: public Form
{
    private:
        ShrubberyCreationForm();

    public:
        ShrubberyCreationForm(std::string target);
        ShrubberyCreationForm(const ShrubberyCreationForm &cls);
        ~ShrubberyCreationForm();

        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &cls);

        void execute(Bureaucrat const &executor) const;

        class FileOpenFailure: public std::exception
        {
            public:
                const char *what() const throw();
        };
};

#endif