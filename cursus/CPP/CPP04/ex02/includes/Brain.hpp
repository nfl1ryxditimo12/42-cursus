#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define SIZE 100

class Brain
{
    private:
        std::string ideas[100];

    public:
        Brain();
        Brain(std::string idea);
        Brain(const Brain &cls);
        ~Brain();

        Brain &operator=(const Brain &cls);

        void printBrain();
};

#endif