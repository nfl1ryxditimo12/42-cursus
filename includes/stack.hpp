#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{
    template <class _TP, class _Container = ft::vector<_TP> >
    class stack
    {
        public:

            typedef _Container                               container_type;
            typedef typename container_type::value_type      value_type;
            typedef typename container_type::reference       reference;
            typedef typename container_type::const_reference const_reference;
            typedef typename container_type::size_type       size_type;

        protected:

            container_type c;

        public:

            explicit stack (const container_type& ctnr = container_type()): c(ctnr) {}

            stack(const stack &cls): c(cls.c) {}

            ~stack() {}

            stack& operator=(const stack &cls) { c = cls.c; return *this; }

        public:

            bool empty() const { return c.empty(); }

            size_type size() const { return c.size(); }

            reference top() { return c.back(); }

            const_reference top() const { return c.back(); }

            void push(const value_type& val) { c.push_back(val); }

            void pop() { c.pop_back(); }

            template <class T1, class _C1>
            friend bool operator==(const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);

            template <class T1, class _C1>
            friend bool operator< (const stack<T1, _C1>& __x, const stack<T1, _C1>& __y);
    };

    template <class T, class Container>
    bool operator== (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    { return lhs.c == rhs.c; }

    template <class T, class Container>
    bool operator!= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    { return !(lhs == rhs); }

    template <class T, class Container>
    bool operator<  (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    { return lhs.c < rhs.c; }

    template <class T, class Container>
    bool operator<= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    { return !(lhs > rhs); }

    template <class T, class Container>
    bool operator>  (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    { return rhs < lhs; }

    template <class T, class Container>
    bool operator>= (const stack<T, Container>& lhs, const stack<T, Container>& rhs)
    { return !(lhs < rhs); }
}

#endif