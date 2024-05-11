#include "Fixed.hpp"

const int Fixed::bit = 8;

/* ------------ ex00 ------------ */

Fixed::Fixed()
{
    std::cout << "Default constructor called" << std::endl;
    this->fixedPoint = 0;
}

Fixed::Fixed(const Fixed &cls)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = cls;
}

Fixed &Fixed::operator=(const Fixed &cls)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPoint = cls.getRawBits();
    return *this;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
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
    std::cout << "Int constructor called" << std::endl;
    this->fixedPoint = num << bit;
}

Fixed::Fixed(float num)
{
    std::cout << "Float constructor called" << std::endl;
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

/* ------------ ex01 ------------ */

std::ostream &operator<<(std::ostream &stream, const Fixed &cls)
{
    stream << cls.toFloat();
    return stream;
}
