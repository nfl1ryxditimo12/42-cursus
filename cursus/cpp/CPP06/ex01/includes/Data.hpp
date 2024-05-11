#ifndef DATA_HPP
# define DATA_HPP

# include <iostream>

class Data
{
    private:
        int integer;
        std::string str;
        int *ptr;

    public:
        Data();
        Data(const Data &cls);
        ~Data();

        Data &operator=(const Data &cls);

        int *getInteger();
        std::string *getString();
        int **getPointer();

};

#endif
