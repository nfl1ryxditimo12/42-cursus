#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"

namespace ft
{
    template <class Iterator>
    class reverse_iterator
    {
        /* Type define */
        public:
            typedef Iterator                                                 iterator_type;
            typedef typename iterator_traits<Iterator>::iterator_category    iterator_category;
            typedef typename iterator_traits<Iterator>::value_type           value_type;
            typedef typename iterator_traits<Iterator>::difference_type      difference_type;
            typedef typename iterator_traits<Iterator>::pointer              pointer;
            typedef typename iterator_traits<Iterator>::reference            reference;

        private:
            iterator_type iter;

        public:

            reverse_iterator(): iter(NULL) {}

            explicit reverse_iterator(iterator_type it): iter(it) {}

            template <class Iter>
            reverse_iterator (const reverse_iterator<Iter>& rev_it): iter(rev_it.base()) {};

        public:

            iterator_type base() const { return this->iter; }

        public:

            reverse_iterator& operator++() { --this->iter; return *this; }
            reverse_iterator  operator++(int) { reverse_iterator tmp(*this); ++(*this); return tmp; }
            reverse_iterator& operator--() { ++this->iter; return *this; }
            reverse_iterator  operator--(int) { reverse_iterator tmp(*this); --(*this); return tmp; }
            
            reference operator*() const { return *(this->iter - 1); }
            pointer operator->() const { return &(this->operator*()); }
            reference operator[] (difference_type n) const { return *(*this + n); }

            reverse_iterator operator+(difference_type n) const { reverse_iterator tmp(*this); tmp += n; return tmp; }
            reverse_iterator& operator+= (difference_type n) { this->iter -= n; return *this; }
            reverse_iterator operator-(difference_type n) const { reverse_iterator tmp(*this); tmp -= n; return tmp; }
            reverse_iterator& operator-= (difference_type n) { this->iter += n; return *this; }
    };

    template <class Iterator1, class Iterator2>
    bool operator== (const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs)
    { return (lhs.base() == rhs.base()); }

    template <class Iterator1, class Iterator2>
    bool operator!= (const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs)
    { return (lhs.base() != rhs.base()); }

    template <class Iterator1, class Iterator2>
    bool operator<  (const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs)
    { return (lhs.base() > rhs.base()); }

    template <class Iterator1, class Iterator2>
    bool operator<= (const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs)
    { return (lhs.base() >= rhs.base()); }

    template <class Iterator1, class Iterator2>
    bool operator>  (const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs)
    { return (lhs.base() < rhs.base()); }

    template <class Iterator1, class Iterator2>
    bool operator>= (const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs)
    { return (lhs.base() <= rhs.base()); }

    template <class Iterator>
    reverse_iterator<Iterator> operator+ (
            typename reverse_iterator<Iterator>::difference_type n,
            const reverse_iterator<Iterator>& rev_it)
    { return reverse_iterator<Iterator>(rev_it.base() - n); }

    template <class Iterator1, class Iterator2>
    typename reverse_iterator<Iterator1>::difference_type operator- (
                    const reverse_iterator<Iterator1>& lhs,
                    const reverse_iterator<Iterator2>& rhs)
    { return (rhs.base() - lhs.base()); }
}

#endif