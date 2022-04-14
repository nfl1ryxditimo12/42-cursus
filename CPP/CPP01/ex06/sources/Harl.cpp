#include "Harl.hpp"

Harl::Harl()
{
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
    std::string list[4] = { "DEBUG", "INFO", "WARNING", "ERROR" };
    void (Harl::*harl[5])();
    int idx = 4;

    harl[0] = &Harl::debug;
    harl[1] = &Harl::info;
    harl[2] = &Harl::warning;
    harl[3] = &Harl::error;
    harl[4] = &Harl::nothing;

    for (int i = 0; i < 4; i++)
        ((list[i] == level) && (idx = i));
    
    switch(idx)
    {
        case 0:
            (this->*harl[0])();
            std::cout << std::endl;
            (this->*harl[1])();
            std::cout << std::endl;
            (this->*harl[2])();
            std::cout << std::endl;
            (this->*harl[3])();
            break ;
        case 1:
            (this->*harl[1])();
            std::cout << std::endl;
            (this->*harl[2])();
            std::cout << std::endl;
            (this->*harl[3])();
            break ;
        case 2:
            (this->*harl[2])();
            std::cout << std::endl;
            (this->*harl[3])();
            break ;
        case 3:
            (this->*harl[3])();
            break ;
        default:
            (this->*harl[4])();
            break ;
    }
}

void Harl::debug()
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl;
}

void Harl::info()
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning()
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month." << std::endl;
}

void Harl::error()
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::nothing()
{
    std::cout << "[ NOTHING ]" << std::endl;
    std::cout << "This level is nothing!!" << std::endl;
}
