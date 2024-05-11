#include "Bureaucrat.hpp"

int main()
{
    try {
        Bureaucrat a;
        Bureaucrat b("b", 100);

        std::cout << a << std::endl;
        std::cout << b << std::endl;

        b.increaseGrade(30);

        std::cout << b << std::endl;

        b.increaseGrade(100);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat c("c", 0);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Bureaucrat d("d", 100);

        d.decreaseGrade(110);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }
}