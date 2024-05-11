#include "Convert.hpp"

Convert::Convert(std::string arg)
: _arg(arg),
  _type("impossible"), 
  _positive(1),
  _exponent(0),
  _fraction(0) {}

Convert::Convert(const Convert &cls)
{
    *this = cls;
}

Convert::~Convert() {}

Convert &Convert::operator=(const Convert &cls)
{
    this->_type = cls._type;
    this->_positive = cls._positive;
    this->_exponent = cls._exponent;
    this->_fraction = cls._fraction;

    return *this;
}

void Convert::getType(std::string arg)
{
    std::cout << "Argument: " << arg << ", Type: " << this->_type << ", Positive: " << this->_positive << std::endl;
}

void Convert::detectType()
{
    if (this->_arg.length() == 1) {
        this->_type = "num";
        this->_exponent = static_cast<int>(this->_arg[0]);
        return ;
    }

    std::string::size_type  start;

    if ((start = this->_arg.find("-")) != std::string::npos) {
        this->_arg.erase(start, 1);
        this->_positive = -1;
    }
    else if ((start = this->_arg.find("+")) != std::string::npos)
        this->_arg.erase(start, 1);
    
    std::string::size_type  length = this->_arg.length();

    if (this->_arg == "inff" || this->_arg == "inf") {
        this->_type = "inf";
        return ;
    }

    int flag = 0;
    for (std::string::size_type i = 0; i < length; i++) {
        if (this->_arg[i] == '.')
            flag++;
        if ((this->_arg[i] == 'f' && i != length - 1) || flag > 1
            || ((this->_arg[i] < 48 || this->_arg[i] > 57) && this->_arg[i] != '.' && this->_arg[i] != 'f'))
            return ;
    }

    if ((start = this->_arg.find(".")) != std::string::npos) {
        if (start == length - 1 || this->_arg[start + 1] == 'f')
            return ;

        for (std::string::size_type i = (start > 10 ? start - 10 : 0); i < start && this->_arg[i] != 'f'; i++)
            this->_exponent = this->_exponent * 10 + static_cast<int>(this->_arg[i]) - 48;
        
        for (std::string::size_type i = start + 1; i < (length > start + 7 ? start + 7 : length) && this->_arg[i] != 'f'; i++)
            this->_fraction = this->_fraction * 10 + static_cast<int>(this->_arg[i]) - 48;
    } else {
        for (std::string::size_type i = (length > 10 ? length - 10 : 0); i < length && this->_arg[i] != 'f'; i++)
            this->_exponent = this->_exponent * 10 + static_cast<int>(this->_arg[i]) - 48;
    }

    this->_type = "num";
    this->_exponent *= this->_positive;
}

void Convert::toChar()
{
    if (this->_type != "num")
        std::cout << "Char     : impossible" << std::endl;
    else if (this->_exponent < -128 || this->_exponent > 126)
        std::cout << "Char     : conversion is impossible" << std::endl;
    else if (this->_exponent < 31 && this->_exponent < 126)
        std::cout << "Char     : Non displayable" << std::endl;
    else
        std::cout << "Char     : \'" << static_cast<char>(this->_exponent) << "\'" << std::endl;
}

void Convert::toInt()
{
    if (this->_type != "num")
        std::cout << "Integer  : impossible" << std::endl;
    else if (this->_exponent > 2147483647 || this->_exponent < -2147483648)
        std::cout << "Integer  : conversion is impossible" << std::endl;
    else
        std::cout << "Integer  : " << this->_exponent << std::endl;
}

void Convert::toFloat()
{
    if (this->_exponent > 999999 || this->_exponent < -999999)
        std::cout << "Float    : conversion is impossible" << std::endl;
    else if (this->_type == "num")
        std::cout << "Float    : " << this->_exponent << "." << this->_fraction << "f" << std::endl;
    else if (this->_type == "inf")
        std::cout << "Float    : " << (this->_positive == 1 ? "" : "-") << "inff" << std::endl;
    else
        std::cout << "Float    : impossible" << std::endl;
}

void Convert::toDouble()
{
    if (this->_exponent > 999999 || this->_exponent < -999999)
        std::cout << "Double   : conversion is impossible" << std::endl;
    else if (this->_type == "num")
        std::cout << "Double   : " << this->_exponent << "." << this->_fraction << std::endl;
    else if (this->_type == "inf")
        std::cout << "Double   : " << (this->_positive == 1 ? "" : "-") << "inf" << std::endl;
    else
        std::cout << "Double   : impossible" << std::endl;
}
