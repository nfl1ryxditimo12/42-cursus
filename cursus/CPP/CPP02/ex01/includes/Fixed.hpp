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
        int     toInt(void) const;
};

/* ------------ ex01 ------------ */

std::ostream &operator<<(std::ostream &stream, const Fixed &cls);

#endif
