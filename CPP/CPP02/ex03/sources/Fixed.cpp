#include "Fixed.hpp"

const int Fixed::bit = 8;

/* ------------ ex00 ------------ */

Fixed::Fixed()
{
    this->fixedPoint = 0;
}

Fixed::Fixed(const Fixed &cls)
{
    *this = cls;
}

Fixed &Fixed::operator=(const Fixed &cls)
{
    this->fixedPoint = cls.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
}

int Fixed::getRawBits() const
{
    return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPoint = raw;
}

/* ------------ ex01 ------------ */

Fixed::Fixed(int num)
{
    this->fixedPoint = num << bit;
}

Fixed::Fixed(float num)
{
    this->fixedPoint = (int)roundf(num * (1 << 8));
}

float Fixed::toFloat() const
{
    return (float)this->fixedPoint / (1 << bit);
}

int Fixed::toInt() const
{
    return (int)this->fixedPoint >> bit;
}

/* ------------ ex02 ------------ */

bool Fixed::operator>(const Fixed &cls) const
{
    return this->getRawBits() > cls.getRawBits();
}

bool Fixed::operator<(const Fixed &cls) const
{
    return this->getRawBits() < cls.getRawBits();
}

bool Fixed::operator>=(const Fixed &cls) const
{
    return this->getRawBits() >= cls.getRawBits();
}

bool Fixed::operator<=(const Fixed &cls) const
{
    return this->getRawBits() <= cls.getRawBits();
}

bool Fixed::operator==(const Fixed &cls) const
{
    return this->getRawBits() == cls.getRawBits();
}

bool Fixed::operator!=(const Fixed &cls) const
{
    return this->getRawBits() != cls.getRawBits();
}

Fixed &Fixed::operator+(const Fixed &cls)
{
    this->fixedPoint += cls.getRawBits();
    return *this;
}

Fixed &Fixed::operator-(const Fixed &cls)
{
    this->fixedPoint -= cls.getRawBits();
    return *this;
}

Fixed &Fixed::operator*(const Fixed &cls)
{
    this->fixedPoint *= cls.getRawBits();
    this->fixedPoint = this->toInt();
    return *this;
}
Fixed &Fixed::operator/(const Fixed &cls)
{
    this->fixedPoint = (this->fixedPoint << bit) / (cls.getRawBits() << bit);
    this->fixedPoint = this->toInt();
    return *this;
}

Fixed &Fixed::operator++()
{
    this->fixedPoint += 1;
    return *this;
}

Fixed Fixed::operator++(int)
{
    Fixed op;

    op.setRawBits(this->getRawBits());
    ++(*this);
    return op;
}

Fixed &Fixed::operator--()
{
    this->fixedPoint -= 1;
    return *this;
}

Fixed Fixed::operator--(int)
{
    Fixed op;
    
    op.setRawBits(this->getRawBits());
    --(*this);
    return op;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
    if (a < b)
        return a;
    else
        return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
    if (a > b)
        return a;
    else
        return b;
}

/* ------------ ex01 ------------ */

std::ostream &operator<<(std::ostream &stream, const Fixed &cls)
{
    stream << cls.toFloat();
    return stream;
}
