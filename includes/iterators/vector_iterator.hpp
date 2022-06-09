#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "../utils/utils.hpp"

namespace ft
{
	template <class Iterator>
	class vector_iterator
	{
		public:
			typedef Iterator												iterator_type;
			typedef typename iterator_traits<Iterator>::iterator_category	iterator_category;
            typedef typename iterator_traits<Iterator>::value_type       	value_type;
            typedef typename iterator_traits<Iterator>::difference_type  	difference_type;
            typedef typename iterator_traits<Iterator>::pointer    	        pointer;
            typedef typename iterator_traits<Iterator>::reference           reference;
		
		private:
			Iterator _iter;

		public:
			vector_iterator(): _iter(NULL) {}

			vector_iterator(const Iterator iter): _iter(iter) {}

			template <class Iter>
            vector_iterator (const vector_iterator<Iter>& iter): _iter(iter.base()) {};

			~vector_iterator() {}

			vector_iterator &operator=(const vector_iterator &cls)
			{
				this->_iter = cls._iter;
				return (*this);
			}

			Iterator base() const { return this->_iter; }

			reference operator*() const { return *this->_iter; }

			pointer operator->() const { return &(*this->_iter); }

			vector_iterator &operator++()
			{
				++this->_iter;
				return *this;
			}

			vector_iterator operator++(int)
			{
				vector_iterator temp(*this);
				++(*this);
				return temp;
			}

			vector_iterator &operator--()
			{
				--this->_iter;
				return *this;
			}

			vector_iterator operator--(int)
			{
				vector_iterator temp(*this);
				--(*this);
				return temp;
			}

            vector_iterator operator+(difference_type n) const
            {
                vector_iterator temp(*this);
                temp += n;
                return temp;
            }

            vector_iterator &operator+=(difference_type n)
            {
                this->_iter += n;
                return *this;
            }

            vector_iterator operator-(difference_type n) const
            { return (*this + (-n)); }

            vector_iterator &operator-=(difference_type n)
            {
                *this += -n;
                return *this;
            }

            reference operator[](difference_type n) const
            { return this->_iter[n]; }

    };

	template <class Iterator1, class Iterator2>
    bool operator== (const vector_iterator<Iterator1>& lhs,
                    const vector_iterator<Iterator2>& rhs)
    { return (lhs.base() == rhs.base()); }

    template <class Iterator1, class Iterator2>
    bool operator!= (const vector_iterator<Iterator1>& lhs,
                    const vector_iterator<Iterator2>& rhs)
    { return !(lhs == rhs); }

    template <class Iterator1, class Iterator2>
    bool operator<  (const vector_iterator<Iterator1>& lhs,
                    const vector_iterator<Iterator2>& rhs)
    { return (lhs.base() < rhs.base()); }

    template <class Iterator1, class Iterator2>
    bool operator<= (const vector_iterator<Iterator1>& lhs,
                    const vector_iterator<Iterator2>& rhs)
    { return !(rhs < lhs); }

    template <class Iterator1, class Iterator2>
    bool operator>  (const vector_iterator<Iterator1>& lhs,
                    const vector_iterator<Iterator2>& rhs)
    { return rhs < lhs; }

    template <class Iterator1, class Iterator2>
    bool operator>= (const vector_iterator<Iterator1>& lhs,
                    const vector_iterator<Iterator2>& rhs)
    { return !(lhs < rhs); }

	template <class Iterator>
    vector_iterator<Iterator> operator+ (
            typename vector_iterator<Iterator>::difference_type n,
            vector_iterator<Iterator> rev_it)
    {
        rev_it += n;
        return rev_it;
    }

    template <class Iter>
    typename vector_iterator<Iter>::difference_type operator- (
                    const vector_iterator<Iter>& lhs,
                    const vector_iterator<Iter>& rhs)
    { return (lhs.base() - rhs.base()); }

    template <class Iterator1, class Iterator2>
    typename vector_iterator<Iterator1>::difference_type operator- (
                    const vector_iterator<Iterator1>& lhs,
                    const vector_iterator<Iterator2>& rhs)
    { return (lhs.base() - rhs.base()); }
}

#endif