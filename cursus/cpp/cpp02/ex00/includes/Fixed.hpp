#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
    private:
        static const int    bit;
        int                 fixedPoint;
    
    public:
        Fixed();
        ~Fixed();
        Fixed(const Fixed &cls);

        Fixed &operator=(const Fixed &cls);

        int     getRawBits() const;
        void    setRawBits(int const raw);
};

#endif
