#ifndef UTILS_HPP
# define UTILS_HPP

#include <iostream>

namespace ft
{

    /*************************************/
    /*          Iterator traits          */
    /*************************************/

    template <class Iterator>
    class iterator_traits
    {
        public:
            typedef typename Iterator::difference_type      difference_type;
            typedef typename Iterator::value_type           value_type;
            typedef typename Iterator::pointer              pointer;
            typedef typename Iterator::reference            reference;
            typedef typename Iterator::iterator_category    iterator_category;
    };

    template <class T>
    class iterator_traits<T *>
    {
        public:
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef T*                              pointer;
            typedef T&                              reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    template <class T>
    class iterator_traits<const T *>
    {
        public:
            typedef ptrdiff_t                       difference_type;
            typedef T                               value_type;
            typedef const T*                        pointer;
            typedef const T&                        reference;
            typedef std::random_access_iterator_tag iterator_category;
    };

    /*************************************/
    /*               pair                */
    /*************************************/

    template <class T1, class T2>
    class pair
    {
        public:

            typedef T1 first_type;
            typedef T2 second_type;

            first_type first;
            second_type second;

            pair(): first(), second() {}

            template <class U, class V>
            pair(const pair<U, V> &cls): first(cls.first), second(cls.second) {}

            pair(const first_type &a, const second_type &b): first(a), second(b) {}

            // ~pair() {}

            pair &operator=(const pair& cls)
            {
                this->first = cls.first;
                this->second = cls.second;
                return *this;
            }
    };
    template <class T1, class T2>
    class pair<const T1, T2>
    {
        public:
        typedef T1 first_type;
        typedef T2 second_type;

        first_type first;
        second_type second;

        pair() : first(), second() {}

        template <class U, class V>
        pair(const ft::pair<U, V> &pr) : first(pr.first), second(pr.second) {}

        pair(first_type const &a, second_type const &b) : first(a), second(b) {}

        pair &operator=(const pair &pr) {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
    };

    template <class T1, class T2>
    std::ostream &operator<<(std::ostream &os, const ft::pair<T1, T2> &x)
    { os << x.first; return os; }

    template <class T1, class T2>
    bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return lhs.first == rhs.first && lhs.second == rhs.second; }

    template <class T1, class T2>
    bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return !(lhs == rhs); }

    template <class T1, class T2>
    bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return (lhs.first < rhs.first) || (!(rhs.first < lhs.first) && (lhs.second < rhs.second)); }

    template <class T1, class T2>
    bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return !(rhs < lhs); }

    template <class T1, class T2>
    bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { return rhs < lhs; }

    template <class T1, class T2>
    bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
    { !(lhs < rhs); }

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

    /*************************************/
    /*          binary_function          */
    /*************************************/

    template <class Arg1, class Arg2, class Result>
    struct binary_function {
        typedef Arg1 first_argument_type;
        typedef Arg2 second_argument_type;
        typedef Result result_type;
    };

    /*************************************/
    /*              rb_node              */
    /*************************************/

    enum Color
    {
        RED,
        BLACK
    };

    enum Type
    {
        END,
        LEAF,
        NODE
    };

    template <class T, class Alloc = std::allocator<T> > class rb_node {
        public:
            typedef T value_type;
            typedef rb_node *node_pointer;

            value_type data;
            node_pointer left, right, parent;
            Color color;
            Type type;

        public:
            explicit rb_node() {
                this->data = value_type();
                this->color = BLACK;
                this->type = END;
                this->left = this->right = this->parent = u_nullptr;
            }

            explicit rb_node(value_type data) {
                this->data = data;
                this->color = RED;
                this->type = NODE;
                this->left = this->right = this->parent = u_nullptr;
            }
    };
};

#endif
