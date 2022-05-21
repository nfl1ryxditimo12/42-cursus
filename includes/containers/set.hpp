#ifndef SET_HPP
# define SET_HPP

# include "RB_TREE.hpp"
# include "utils.hpp"
# include "set_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set
	{
		public:
			typedef T					key_type;
			typedef key_type			value_type;
			typedef Compare				key_compare;
			typedef key_compare			value_compare;

			typedef Alloc				allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::difference_type	difference_type;
			typedef typename allocator_type::size_type			size_type;

			typedef rb_tree<key_type, value_type, value_type, value_compare>	tree_type;

			typedef ft::set_iterator<typename tree_type::iterator>				iterator;
			typedef ft::set_const_iterator<typename tree_type::const_iterator>	const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

		private:

			key_compare		_comp;
			allocator_type	_alloc;
			tree_type		_tree;

		public:

			/*************************************/
			/*            Constructor            */
			/*************************************/

			explicit set (const key_compare& comp = key_compare(),
							const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(comp)) {}

			template <class InputIterator>
			set (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(_comp))
			{ this->insert(first, last); }

			set (const set& cls): _comp(cls._comp), _alloc(cls._alloc), _tree(cls._tree) {}

			/*************************************/
			/*            Destructor             */
			/*************************************/

			~set() {}

			/*************************************/
			/*             Operator              */
			/*************************************/

			set &operator=(const set &cls)
			{
				if (this != &cls) {
					this->clear();
					this->_comp = cls._comp;
					this->_alloc = cls._alloc;
					this->insert(cls.begin(), cls.end());
				}
				return (*this);
			}

			/*************************************/
			/*            Iterators              */
			/*************************************/

			iterator begin() { return this->_tree.begin(); }

			const_iterator begin() const { return this->_tree.begin(); }

			iterator end() { return this->_tree.end(); }

			const_iterator end() const { return this->_tree.end(); }

			reverse_iterator rbegin() { return reverse_iterator(this->_tree.end()); }

			const_reverse_iterator rbegin() const { return reverse_iterator(this->_tree.end()); }

			reverse_iterator rend() { return reverse_iterator(this->_tree.begin()); }

			const_reverse_iterator rend() const { return reverse_iterator(this->_tree.begin()); }

			/*************************************/
			/*            Capacity               */
			/*************************************/

			bool empty() const { return this->_tree.empty(); }

			size_type size() const { return this->_tree.size(); }

			size_type max_size() const { return this->_tree.max_size(); }

			/*************************************/
			/*            Modifiers              */
			/*************************************/

			/* insert */

			pair<iterator,bool> insert (const value_type& val)
			{ return this->_tree.insert(val); }

			iterator insert (iterator position, const value_type& val)
			{ return this->_tree.insert(position.base(), val); }

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{ this->_tree.insert(first, last); }

			/* erase */

			void erase (iterator position)
			{ this->_tree.erase(position.base()); }

			size_type erase (const value_type& val)
			{
				iterator iter = this->find(val);
				if (iter == this->end())
					return 0;
				this->erase(iter);
				return 1;
			}

			void erase (iterator first, iterator last)
			{
				while (first != last)
					this->erase(first++);
			}

			/* swap */

			void swap (set& cls)
			{
				this->_tree.swap(cls._tree);
				std::swap(this->_comp, cls._comp);
				std::swap(this->_alloc, cls._alloc);
			}

			/* clear */

			void clear() { this->_tree.clear(); }

			/*************************************/
			/*            Observers              */
			/*************************************/

			key_compare key_comp() const { return this->_comp; }

			value_compare value_comp() const { return this->_comp; }

			/*************************************/
			/*           Operations              */
			/*************************************/

			/* find */

			iterator find (const value_type& val) { return this->_tree.find(val); }

			const_iterator find (const value_type& val) const { return this->_tree.find(val); }

			/* count */

			size_type count (const value_type& val) const { return (this->find(val) != this->end()); }

			/* lower_bound */

			iterator lower_bound (const value_type& val) { return this->_tree.lower_bound(val); }

			const_iterator lower_bound (const value_type& val) const { return this->_tree.lower_bound(val); }

			/* upper_bound */

			iterator upper_bound (const value_type& val) { return this->_tree.upper_bound(val); }

			const_iterator upper_bound (const value_type& val) const { return this->_tree.upper_bound(val); }

			/* equal_range */

			ft::pair<iterator, iterator> equal_range (const value_type& val)
			{ return pair<iterator, iterator>(lower_bound(val), upper_bound(val)); }

			ft::pair<const_iterator, const_iterator> equal_range (const value_type& val) const
			{ return pair<const_iterator, const_iterator>(lower_bound(val), upper_bound(val)); }

			/*************************************/
			/*            Allocator              */
			/*************************************/

			allocator_type get_allocator() const { return this->_alloc; }
	};

	template <class T, class Compare, class Alloc>
	bool operator== ( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )
	{ return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()); }

	template <class T, class Compare, class Alloc>
	bool operator!= ( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )
	{ return !(lhs == rhs); }

	template <class T, class Compare, class Alloc>
	bool operator<  ( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )
	{ return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()); }

	template <class T, class Compare, class Alloc>
	bool operator<= ( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )
	{ return !(rhs < lhs); }

	template <class T, class Compare, class Alloc>
	bool operator>  ( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )
	{ return (rhs < lhs); }

	template <class T, class Compare, class Alloc>
	bool operator>= ( const set<T,Compare,Alloc>& lhs,
						const set<T,Compare,Alloc>& rhs )
	{ return !(lhs < rhs); }

	template <class T, class Compare, class Alloc>
  	void swap (set<T,Compare,Alloc>& x, set<T,Compare,Alloc>& y)
	{ x.swap(y); }
}

#endif