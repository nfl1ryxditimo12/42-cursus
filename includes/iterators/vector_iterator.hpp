#ifndef VECTOR_ITERATOR_HPP
# define VECTOR_ITERATOR_HPP

# include "../utils/utils.hpp"

namespace ft
{
	template <class Iterator>
	class vector_iterator
	{
		public:
			typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
            typedef typename iterator_traits<Iterator>::value_type        value_type;
            typedef typename iterator_traits<Iterator>::difference_type   difference_type;
            typedef typename iterator_traits<Iterator>::pointer           pointer;
            typedef typename iterator_traits<Iterator>::reference         reference;
		
		private:
			Iterator _iter;

		public:
			vector_iterator(): _iter {}

			vector_iterator(const Iterator iter): _iter(iter.base()) {}

			// vector_iterator(const vector_iterator &cls): _iter(cls._iter) {}

			~vector_iterator() {}

			vector_iterator &operator=(const vector_iterator &cls)
			{
				this->_iter = cls._iter;
				return (*this);
			}

			Iterator base() { return this->_iter; }

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

	template <class Iterator>
	class vector_const_iterator
	{
		public:
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::node_pointer			node_pointer;
			typedef const value_type*						pointer;
			typedef const value_type&						reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::size_type			size_type;
			typedef typename Iterator::iterator_category	iterator_category;
			typedef ft::vector_iterator<typename Iterator::non_const_iterator> non_const_iterator;
		
		private:
			Iterator _iter;

		public:
			vector_const_iterator() {}

			vector_const_iterator(const Iterator iter): _iter(iter) {}

			vector_const_iterator(non_const_iterator cls): _iter(cls.base()) {}

			~vector_const_iterator() {}

			vector_const_iterator &operator=(const vector_const_iterator &cls)
			{
				this->_iter = cls._iter;
				return (*this);
			}

			Iterator base() { return this->_iter; }

			reference operator*() const { return *this->_iter; }

			pointer operator->() const { return &(*this->_iter); }

			vector_const_iterator &operator++()
			{
				++this->_iter;
				return *this;
			}

			vector_const_iterator operator++(int)
			{
				vector_const_iterator temp(*this);
				++(*this);
				return temp;
			}

			vector_const_iterator &operator--()
			{
				--this->_iter;
				return *this;
			}

			vector_const_iterator operator--(int)
			{
				vector_const_iterator temp(*this);
				--(*this);
				return temp;
			}

			bool operator==(const vector_const_iterator &cls) const { return this->_iter == cls._iter; }

  			bool operator!=(const vector_const_iterator &cls) const { return !(*this == cls); }
	};

    template <class Iter1, class Iter2>
    bool operator==(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
    { return this->_iter == cls._iter; }

    template <class Iter1, class Iter2>
    bool operator!=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
    { return this->_iter != cls._iter; }

    template <class Iter1, class Iter2>
    bool operator<(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
    { return this->_iter < cls._iter; }

    template <class Iter1, class Iter2>
    bool operator<=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
    { return this->_iter <= cls._iter; }

    template <class Iter1, class Iter2>
    bool operator>(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
    { return this->_iter > cls._iter; }

    template <class Iter1, class Iter2>
    bool operator>=(const vector_iterator<Iter1> &lhs, const vector_iterator<Iter2> &rhs)
    { return this->_iter >= cls._iter; }
}

#endif