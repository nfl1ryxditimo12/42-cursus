#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include "Form.hpp"

class PresidentialPardonForm: public Form
{
    private:
        PresidentialPardonForm();

    public:
        PresidentialPardonForm(std::string target);
        PresidentialPardonForm(const PresidentialPardonForm &cls);
        ~PresidentialPardonForm();

        PresidentialPardonForm &operator=(const PresidentialPardonForm &cls);

        void execute(Bureaucrat const &executor) const;
};

#endif