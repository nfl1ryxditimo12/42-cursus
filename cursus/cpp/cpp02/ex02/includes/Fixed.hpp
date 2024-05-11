#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private:
        static const int    bit;
        int                 fixedPoint;

    public:

        /* ------------ ex00 ------------ */

        Fixed();
        ~Fixed();
        Fixed(const Fixed &cls);

        Fixed &operator=(const Fixed &cls);

        int     getRawBits() const;
        void    setRawBits(int const raw);

        /* ------------ ex01 ------------ */

        Fixed(int num);
        Fixed(float num);

        float   toFloat() const;
        int     toInt() const;

        /* ------------ ex02 ------------ */

        bool operator>(const Fixed &cls) const;
        bool operator<(const Fixed &cls) const;
        bool operator>=(const Fixed &cls) const;
        bool operator<=(const Fixed &cls) const;
        bool operator==(const Fixed &cls) const;
        bool operator!=(const Fixed &cls) const;

        Fixed &operator+(const Fixed &cls);
        Fixed &operator-(const Fixed &cls);
        Fixed &operator*(const Fixed &cls);
        Fixed &operator/(const Fixed &cls);

        Fixed &operator++();      
        Fixed operator++(int);
        Fixed &operator--();
        Fixed operator--(int);

        static Fixed &min(Fixed &a, Fixed &b);
        static const Fixed &min(const Fixed &a, const Fixed &b);
        static Fixed &max(Fixed &a, Fixed &b);
        static const Fixed &max(const Fixed &a, const Fixed &b);
};

/* ------------ ex01 ------------ */

std::ostream &operator<<(std::ostream &stream, const Fixed &cls);

#endif
