#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>

class Span
{
    private:
        std::vector<int> vec;
        size_t          maxSize;

        Span();

        int min(int a, int b);
        int max(int a, int b);
    public:
        Span(long size);
        Span(const Span &cls);
        ~Span();

        Span &operator=(const Span &cls);

        void addNumber(int elem);
        int shortestSpan(int &a, int &b);
        int longestSpan();

        void printSpan();
        int getMin();
        int getMax();

        class OutofIndex: public std::exception
        {
            public:
                const char *what() const throw() {
                    return "Error: out of index!!";
                }
        };
};

#endif
