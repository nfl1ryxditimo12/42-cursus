#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>

namespace ft
{
/*************************************/
/*               pair                */
/*************************************/

    template <class T1, class T2>
    class pair
    {
        public:
            T1 first;
            T2 second;

            pair(): first(), second() {}
            pair(T1 first, T2 second): first(first), second(second) {}
            pair(const pair &cls): first(cls.first), second(cls.second) {}
            ~pair() {}

            pair &operator=(const pair &cls)
            {
                if (this != &cls) {
                    this->first = cls.first;
                    this->second = cls.second;
                }
                return *this;
            }
    };

    template <class T1, class T2>
    bool operator==(const pair<T1,T2>& cls1, const pair<T1,T2>& cls2)
    { return cls1.first==cls2.first && cls1.second==cls2.second; }

    template <class T1, class T2>
    bool operator!=(const pair<T1,T2>& cls1, const pair<T1,T2>& cls2)
    { return !(cls1==cls2); }

    template <class T1, class T2>
    bool operator<(const pair<T1,T2>& cls1, const pair<T1,T2>& cls2)
    { return cls1.first<cls2.first || (!(cls2.first<cls1.first) && cls1.second<cls2.second); }

    template <class T1, class T2>
    bool operator<=(const pair<T1,T2>& cls1, const pair<T1,T2>& cls2)
    { return !(cls2<cls1); }

    template <class T1, class T2>
    bool operator>(const pair<T1,T2>& cls1, const pair<T1,T2>& cls2)
    { return cls2<cls1; }

    template <class T1, class T2>
    bool operator>=(const pair<T1,T2>& cls1, const pair<T1,T2>& cls2)
    { return !(cls1<cls2); }

/*************************************/
/*             make_pair             */
/*************************************/

    template <class T1, class T2>
    ft::pair<T1, T2> make_pair(T1 first, T2 second)
    { return ft::pair<T1, T2>(first, second); }

/*************************************/
/*             enable_if             */
/*************************************/

    template<bool B, class T = void>
    struct enable_if {};

    template<class T>
    struct enable_if<true, T> { typedef T type; };

/*************************************/
/*            is_integral            */
/*************************************/

    template <class T>
    struct is_integral { static const bool value = false; };

    template <>
    struct is_integral<bool> { static const bool value = true; };

    template <>
    struct is_integral<char> { static const bool value = true; };

    template <>
    struct is_integral<unsigned char> { static const bool value = true; };

    template <>
    struct is_integral<short> { static const bool value = true; };

    template <>
    struct is_integral<unsigned short> { static const bool value = true; };

    template <>
    struct is_integral<int> { static const bool value = true; };

    template <>
    struct is_integral<unsigned int> { static const bool value = true; };

    template <>
    struct is_integral<long> { static const bool value = true; };

    template <>
    struct is_integral<unsigned long> { static const bool value = true; };

/*************************************/
/*               equal               */
/*************************************/

    template <class InputIterator1, class InputIterator2>
    bool equal(InputIterator1 first1, InputIterator1 last1, InputIterator2 first2)
    {
        while (first1 != last1) {
            if (!(*first1 == *first2))
                return false;
            ++first1; ++first2;
        }
        return true;
    }

/*************************************/
/*      lexicographical_compare      */
/*************************************/

    template <class InputIterator1, class InputIterator2>
    bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
                                InputIterator2 first2, InputIterator2 last2)
    {
        while (first1 != last1) {
            if (first2 == last2 || *first1 > *first2) return false;
            else if (*first1 < *first2) return true;
            ++first1; ++first2;
        }
        return (first2 != last2);
    }

    static class nullptr_t {
    public:
    template <class T> operator T *() const { return (0); }

    template <class C, class T> operator T C::*() const { return (0); }

    private:
    void operator&() const;

    } u_nullptr;
};

#endif
