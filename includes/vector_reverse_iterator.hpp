#ifndef VECTOR_REVERSE_ITERATOR_HPP
# define VECTOR_REVERSE_ITERATOR_HPP

namespace ft
{
    template <class _Tp>
    class vector_reverse_iterator
    {
        /* Type define */
        public:
            typedef _Tp                     value_type;
            typedef size_t                  size_type;
            typedef long int                difference_type;

            typedef value_type*             pointer;
            typedef value_type&             reference;
    };
}

#endif