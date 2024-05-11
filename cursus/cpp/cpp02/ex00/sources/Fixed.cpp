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
    this->fixedPoint = cls.getRawBits();
}

Fixed &Fixed::operator=(const Fixed &cls)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->fixedPoint = cls.getRawBits();
    return *this;
}

int Fixed::getRawBits() const
{
    std::cout << "getRawBits member function called" << std::endl;
    return this->fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
    this->fixedPoint = raw;
}

Fixed::~Fixed()
{
    std::cout << "Destructor called" << std::endl;
}
