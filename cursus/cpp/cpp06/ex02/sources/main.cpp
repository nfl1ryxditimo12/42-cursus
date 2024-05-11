#include "Class.hpp"

Base *generate(void)
{
    int random;

    std::srand(std::time(NULL));
    random = rand() % 3;

    if (random == 0) {
        std::cout << "\'A\' Class created" << std::endl;
        return new A;
    }
    else if (random == 1) {
        std::cout << "\'B\' Class created" << std::endl;
        return new B;
    }
    std::cout << "\'C\' Class created" << std::endl;
    return new C;
}

void identify(Base *p)
{
    A *a = dynamic_cast<A *>(p);
    B *b = dynamic_cast<B *>(p);
    C *c = dynamic_cast<C *>(p);

    if (a != NULL)
        std::cout << "This object pointed to by \'A\' Class" << std::endl;
    if (b != NULL)
        std::cout << "This object pointed to by \'B\' Class" << std::endl;
    if (c != NULL)
        std::cout << "This object pointed to by \'C\' Class" << std::endl;
}

void identify(Base &p)
{
    try {
        A a = dynamic_cast<A &>(p);
        std::cout << "This object reffered to by \'A\' Class" << std::endl;
    } catch (std::exception &e) {}
    try {
        B b = dynamic_cast<B &>(p);
        std::cout << "This object reffered to by \'B\' Class" << std::endl;
    } catch (std::exception &e) {}
    try {
        C c = dynamic_cast<C &>(p);
        std::cout << "This object reffered to by \'C\' Class" << std::endl;
    } catch (std::exception &e) {}
}

int main()
{
    Base *base = generate();

    identify(base);
    identify(*base);

    delete base;
    return (0);
}
