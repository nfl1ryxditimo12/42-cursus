#include "Span.hpp"

void test()
{
    Span span(10);

    span.addNumber(100);
    span.addNumber(5);
    span.addNumber(3);
    span.addNumber(50);
    span.addNumber(47);
    span.addNumber(150);
    span.addNumber(9);

    std::cout << "======================================\n" << std::endl;

    int a = 0;
    int b = 0;
    std::cout << "Shortest value: " << span.shortestSpan(a, b) << std::endl;
    std::cout << "Min value: " << a << ", Max value: " << b << std::endl;

    std::cout << std::endl;

    std::cout << "Longest value: " << span.longestSpan() << std::endl;
    std::cout << "Min value: " << span.getMin() << ", Max value: " << span.getMax() << std::endl;

    std::cout << "\n======================================\n" << std::endl;

    Span test(10000);

    std::srand(std::time(NULL));
    for (int i = 0; i < 10000; i++)
        test.addNumber(std::rand());

    // test.printSpan(); 평가때 사용

    a = 0;
    b = 0;
    std::cout << "Shortest value: " << test.shortestSpan(a, b) << std::endl;
    std::cout << "Min value: " << a << ", Max value: " << b << std::endl;

    std::cout << std::endl;

    std::cout << "Longest value: " << test.longestSpan() << std::endl;
    std::cout << "Min value: " << test.getMin() << ", Max value: " << test.getMax() << std::endl;

    std::cout << "\n======================================\n" << std::endl;

    try {
        Span err(100);

        for (int i = 0; i < 101; i++)
            err.addNumber(i);
    } catch (std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << "\n======================================\n" << std::endl;
}

int main()
{
    test();
    system("leaks ex01");
    std::cout << "======================================" << std::endl;

    return (0);
}
