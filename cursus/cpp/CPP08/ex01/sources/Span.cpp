#include "Span.hpp"

Span::Span(long size)
{
    if (size < 0 || size > 4294967295)
        throw Span::OutofIndex();
    this->maxSize = (size_t)size;
}

Span::Span(const Span &cls)
{
    this->maxSize = cls.maxSize;
}

Span::~Span() {}

Span &Span::operator=(const Span &cls)
{
    this->maxSize = cls.maxSize;
    return *this;
}

void Span::addNumber(int elem)
{
    if (this->vec.size() == this->maxSize)
        throw Span::OutofIndex();
    vec.push_back(elem);
    std::sort(this->vec.begin(), this->vec.end());
}

int Span::shortestSpan(int &a, int &b)
{
    std::vector<int> tmp;
    int min = 2147483647;

    while (this->vec.size() != 1) {
        for (std::vector<int>::iterator iter = this->vec.begin(); iter < this->vec.end() - 1; iter++) {
            int minValue = this->min(min, (*iter - this->vec.back() < 0 ? this->vec.back() - *iter : *iter - this->vec.back()));
            if (minValue < min) {
                a = *iter;
                b = this->vec.back();
                min = minValue;
            }
        }

        tmp.push_back(this->vec.back());
        this->vec.pop_back();
    }
    tmp.push_back(this->vec.front());
    this->vec.swap(tmp);
    std::sort(this->vec.begin(), this->vec.end());

    return min;
}

int Span::longestSpan()
{
    std::vector<int> tmp;
    int max = -2147483648;

    while (this->vec.size() != 1) {
        for (std::vector<int>::iterator iter = this->vec.begin(); iter < this->vec.end() - 1; iter++)
            max = this->max(max, (*iter - this->vec.back() < 0 ? this->vec.back() - *iter : *iter - this->vec.back()));
        tmp.push_back(this->vec.back());
        this->vec.pop_back();
    }
    tmp.push_back(this->vec.front());
    this->vec.swap(tmp);
    std::sort(this->vec.begin(), this->vec.end());

    return max;
}

void Span::printSpan()
{
    for (std::vector<int>::iterator iter = this->vec.begin(); iter < this->vec.end(); iter++)
        std::cout << *iter << " ";
    std::cout << std::endl;
}

int Span::getMin()
{
    return this->vec.front();
}

int Span::getMax()
{
    return this->vec.back();
}

int Span::min(int a, int b)
{
    return a < b ? a : b;
}

int Span::max(int a, int b)
{
    return a > b ? a : b;
}
