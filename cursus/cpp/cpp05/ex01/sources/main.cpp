#include "Form.hpp"

int main()
{
    try {
        Form form("form1", 30, 30);
        Bureaucrat a("a", 50);
        Bureaucrat b("b", 2);

        std::cout << form << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;

        std::cout << std::endl;

        b.signForm(form);

        form.beSigned(a);
        a.signForm(form);

        form.beSigned(b);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}