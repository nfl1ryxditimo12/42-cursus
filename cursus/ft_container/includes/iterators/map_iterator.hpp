#ifndef MAP_ITERATOR_HPP
# define MAP_ITERATOR_HPP

namespace ft
{
	template <class Iterator>
	class map_iterator
	{
		public:
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::node_pointer			node_pointer;
			typedef typename Iterator::pointer				pointer;
			typedef typename Iterator::reference			reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::size_type			size_type;
			typedef typename Iterator::iterator_category	iterator_category;
		
		private:
			Iterator _iter;

		public:
			map_iterator() {}

			map_iterator(const Iterator iter): _iter(iter) {}

			// map_iterator(const map_iterator &cls): _iter(cls._iter) {}

			~map_iterator() {}

			map_iterator &operator=(const map_iterator &cls)
			{
				this->_iter = cls._iter;
				return (*this);
			}

			Iterator base() { return this->_iter; }

			reference operator*() const { return *this->_iter; }

			pointer operator->() const { return &(*this->_iter); }

			map_iterator &operator++()
			{
				++this->_iter;
				return *this;
			}

			map_iterator operator++(int)
			{
				map_iterator temp(*this);
				++(*this);
				return temp;
			}

			map_iterator &operator--()
			{
				--this->_iter;
				return *this;
			}

			map_iterator operator--(int)
			{
				map_iterator temp(*this);
				--(*this);
				return temp;
			}

			bool operator==(const map_iterator &cls) const { return this->_iter == cls._iter; }

  			bool operator!=(const map_iterator &cls) const { return this->_iter != cls._iter; }
	};

	template <class Iterator>
	class map_const_iterator
	{
		public:
			typedef typename Iterator::value_type			value_type;
			typedef typename Iterator::node_pointer			node_pointer;
			typedef const value_type*						pointer;
			typedef const value_type&						reference;
			typedef typename Iterator::difference_type		difference_type;
			typedef typename Iterator::size_type			size_type;
			typedef typename Iterator::iterator_category	iterator_category;
			typedef ft::map_iterator<typename Iterator::non_const_iterator> non_const_iterator;
		
		private:
			Iterator _iter;

		public:
			map_const_iterator() {}

			map_const_iterator(const Iterator iter): _iter(iter) {}

			map_const_iterator(non_const_iterator cls): _iter(cls.base()) {}

			~map_const_iterator() {}

			map_const_iterator &operator=(const map_const_iterator &cls)
			{
				this->_iter = cls._iter;
				return (*this);
			}

			Iterator base() { return this->_iter; }

			reference operator*() const { return *this->_iter; }

			pointer operator->() const { return &(*this->_iter); }

			map_const_iterator &operator++()
			{
				++this->_iter;
				return *this;
			}

			map_const_iterator operator++(int)
			{
				map_const_iterator temp(*this);
				++(*this);
				return temp;
			}

			map_const_iterator &operator--()
			{
				--this->_iter;
				return *this;
			}

			map_const_iterator operator--(int)
			{
				map_const_iterator temp(*this);
				--(*this);
				return temp;
			}

			bool operator==(const map_const_iterator &cls) const { return this->_iter == cls._iter; }

  			bool operator!=(const map_const_iterator &cls) const { return !(*this == cls); }
	};
}

#endif