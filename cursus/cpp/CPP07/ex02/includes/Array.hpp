#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template<class T>
class Array
{
    private:
        T   *arr;
        int length;
    public:
        Array();
        Array(const int length);
        Array(const Array &cls);
        ~Array();

        Array &operator=(const Array &cls);
        T &operator[](const int idx);

        T *getArray();
        int getLength();

        class OutOfIndex: public std::exception
        {
            public:
                const char *what() const throw() {
                    return "Out of index!!!";
                }
        };
};

template<class T>
Array<T>::Array(): arr(new T[0]), length(0) {}

template<class T>
Array<T>::Array(const int length): arr(new T[length]), length(length) {}

template<class T>
Array<T>::Array(const Array &cls)
{
    this->arr = new T[cls.length];
    this->length = cls.length;
    for (int i = 0; i < cls.length; i++)
        arr[i] = cls.arr[i];
}

template<class T>
Array<T>::~Array()
{
    delete [] this->arr;
}

template<class T>
Array<T> &Array<T>::operator=(const Array &cls)
{
    if (this == &cls)
        return *this;
    delete [] this->arr;
    arr = new T[cls.length];
    for (int i = 0; i < cls.length; i++)
        arr[i] = cls.arr[i];
    length = cls.length;
    return *this;
}

template<class T>
T &Array<T>::operator[](const int idx)
{
    if (idx < 0 || idx >= this->length)
        throw Array<T>::OutOfIndex();
    return *(this->arr + idx);
}

template<class T>
T *Array<T>::getArray()
{
    return this->arr;
}

template<class T>
int Array<T>::getLength()
{
    return this->length;
}

#endif
