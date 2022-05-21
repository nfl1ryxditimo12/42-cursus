#ifndef SET_ITERATOR_HPP
# define SET_ITERATOR_HPP

namespace ft
{
	template <class T1> class set_const_iterator;

	template <class Iterator>
	class set_iterator
	{
		public:
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::node_pointer			node_pointer;
			typedef const value_type*						pointer;
			typedef const value_type&						reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::size_type			size_type;
			typedef typename Iterator::iterator_category	iterator_category;

			typedef ft::set_const_iterator<typename Iterator::const_iterator> const_iterator;
		
		private:
			Iterator _iter;

		public:
			set_iterator() {}

			set_iterator(const Iterator iter): _iter(iter) {}

			set_iterator(const set_iterator &cls): _iter(cls.base()) {}

			set_iterator(const const_iterator &cls): _iter(cls.base()) {}

			~set_iterator() {}

			set_iterator &operator=(const set_iterator &cls)
			{
				this->_iter = cls._iter;
				return (*this);
			}

			Iterator base() const { return this->_iter; }

			reference operator*() const { return *this->_iter; }

			pointer operator->() const { return &(*this->_iter); }

			set_iterator &operator++()
			{
				++this->_iter;
				return *this;
			}

			set_iterator operator++(int)
			{
				set_iterator temp(*this);
				++(*this);
				return temp;
			}

			set_iterator &operator--()
			{
				--this->_iter;
				return *this;
			}

			set_iterator operator--(int)
			{
				set_iterator temp(*this);
				--(*this);
				return temp;
			}

			bool operator==(const set_iterator &cls) const { return this->_iter == cls._iter; }

  			bool operator!=(const set_iterator &cls) const { return this->_iter != cls._iter; }
	};

	template <class Iterator>
	class set_const_iterator
	{
		public:
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::node_pointer			node_pointer;
			typedef const value_type*						pointer;
			typedef const value_type&						reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::size_type			size_type;
			typedef typename Iterator::iterator_category	iterator_category;
			typedef ft::set_iterator<typename Iterator::non_const_iterator> non_const_iterator;
		
		private:
			Iterator _iter;

		public:
			set_const_iterator() {}

			set_const_iterator(const Iterator iter): _iter(iter) {}

			set_const_iterator(non_const_iterator cls): _iter(cls.base()) {}

			~set_const_iterator() {}

			set_const_iterator &operator=(const set_const_iterator &cls)
			{
				this->_iter = cls._iter;
				return (*this);
			}

			Iterator base() const { return this->_iter; }

			reference operator*() const { return *this->_iter; }

			pointer operator->() const { return &(*this->_iter); }

			set_const_iterator &operator++()
			{
				++this->_iter;
				return *this;
			}

			set_const_iterator operator++(int)
			{
				set_const_iterator temp(*this);
				++(*this);
				return temp;
			}

			set_const_iterator &operator--()
			{
				--this->_iter;
				return *this;
			}

			set_const_iterator operator--(int)
			{
				set_const_iterator temp(*this);
				--(*this);
				return temp;
			}

			bool operator==(const set_const_iterator &cls) const { return this->_iter == cls._iter; }

  			bool operator!=(const set_const_iterator &cls) const { return !(*this == cls); }
	};
}

#endif