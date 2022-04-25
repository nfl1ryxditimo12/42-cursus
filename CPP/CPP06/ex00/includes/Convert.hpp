#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <sstream>

class Convert
{
    private:
        std::string _arg;
        std::string _type;
        int         _positive;
        long        _exponent;
        long        _fraction;

        Convert();
    public:
        Convert(std::string arg);
        Convert(const Convert &cls);
        ~Convert();

        Convert &operator=(const Convert &cls);

        void getType(std::string arg);
        void detectType();
        void toChar();
        void toInt();
        void toFloat();
        void toDouble();
};

#endif
