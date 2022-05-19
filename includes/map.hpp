#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "RB_TREE.hpp"
# include "map_iterator.hpp"
# include "reverse_iterator.hpp"
# include "utils.hpp"

namespace ft
{
	template <class _Key, class _Tp, class _Compare = std::less<_Key>,
				class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{
		public:
			typedef _Key									key_type;
			typedef _Tp										mapped_type;
			typedef ft::pair<const key_type, mapped_type>	value_type;
			typedef _Compare								key_compare;
			typedef _Allocator								allocator_type;

			typedef typename allocator_type::reference			refernece;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			class value_compare
				: public ft::binary_function<value_type, value_type, bool> {

				friend class map;

				protected:
					key_compare comp;

					value_compare(key_compare c) : comp(c) {}

				public:
					bool operator()(const value_type &x, const value_type &y) const {
					return comp(x.first, y.first);
					}

					bool operator()(const value_type &x, const key_type &y) const {
					return comp(x.first, y);
					}

					bool operator()(const key_type &x, const value_type &y) const {
					return comp(x, y.first);
					}
			};

			typedef ft::rb_tree<value_type, value_compare>				tree_type;
			typedef ft::map_iterator<typename tree_type::iterator>		iterator;
			typedef ft::map_const_iterator<typename tree_type::const_iterator>	const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

		private:
		
			/*************************************/
			/*         Member Variables          */
			/*************************************/

			key_compare _comp;
			allocator_type _alloc;
			tree_type _tree;

		public:

			/*************************************/
			/*            Constructor            */
			/*************************************/

			map(const key_compare& comp = key_compare(),
              	const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(comp)) {}

			template <class InputIterator>
			map (InputIterator first, InputIterator last,
				const key_compare& comp = key_compare(),
				const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(comp))
			{ this->insert(first, last); }

			map (const map& cls): _comp(cls._comp), _alloc(cls._alloc), _tree(cls._tree) {}

			/*************************************/
			/*            Destructor             */
			/*************************************/

			~map() {}

			/*************************************/
			/*             Operator              */
			/*************************************/

			map &operator=(const map& cls)
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
			/*             Iterators             */
			/*************************************/

			void print_tree() { this->_tree.print_tree(this->_tree.root()); }

			iterator begin() { return this->_tree.begin(); }

			const_iterator begin() const { return this->_tree.begin(); }

			iterator end() { return this->_tree.end(); }
			
			const_iterator end() const { return this->_tree.end(); }

			reverse_iterator rbegin() { return reverse_iterator(this->_tree.end()); }

			const_reverse_iterator rbegin() const { return reverse_iterator(this->_tree.end()); }

			reverse_iterator rend() { return reverse_iterator(this->_tree.begin()); }

			const_reverse_iterator rend() const { return reverse_iterator(this->_tree.begin()); }


			/*************************************/
			/*             Capacity              */
			/*************************************/

			bool empty() const { return this->_tree.empty(); }

			size_type size() const { return this->_tree.size(); }

			size_type max_size() const { return this->_tree.max_size(); }

			/*************************************/
			/*           Element access          */
			/*************************************/

			mapped_type &operator[](const key_type &k)
			{
				ft::pair<iterator, bool> p = insert(ft::make_pair(k, mapped_type()));
				return (p.first)->second;
			}

			/*************************************/
			/*             Modifiers             */
			/*************************************/

			/* Insert */

			ft::pair<iterator, bool> insert(const value_type& val)
			{ return this->_tree.insert(val); }

			iterator insert(iterator position, const value_type& val)
			{ return this->_tree.insert(position.base(), val); }

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{ this->_tree.insert(first, last); }

			/* Erase */

			void erase (iterator position)
			{ this->_tree.erase(position); }

			size_type erase (const key_type& k)
			{ this->_tree.erase(k); }

			void erase (iterator first, iterator last)
			{ this->_tree.erase(first, last); }

			/* Swap */

			void swap (map& x)
			{ this->_tree.swap(x._tree); }

			/* Clear */

			void clear()
			{ this->_tree.clear(); }

			/*************************************/
			/*             Observers             */
			/*************************************/

			key_compare key_comp() const { return this->_comp; }

			value_compare value_comp() const { return value_compare(this->_comp); }

			/*************************************/
			/*             Operations            */
			/*************************************/

			/* Find */

			iterator find (const key_type& k) { return this->_tree.find(k); }

			const_iterator find (const key_type& k) const { return this->_tree.find(k); }

			/* Count */

			size_type count (const key_type& k) const;

			/* Lower_bound */

			iterator lower_bound (const key_type& k) { return this->_tree.lower_bound(k); }

			const_iterator lower_bound (const key_type& k) const { return this->_tree.lower_bound(k); }

			/* Upper_bound */

			iterator upper_bound (const key_type& k) { return this->_tree.upper_bound(k); }

			const_iterator upper_bound (const key_type& k) const { return this->_tree.upper_bound(k); }

			/* Equal_range */

			pair<const_iterator,const_iterator> equal_range (const key_type& k) const;

			pair<iterator,iterator>             equal_range (const key_type& k);

			/*************************************/
			/*             Allocator             */
			/*************************************/

			allocator_type get_allocator() const { return this->_tree.get_allocator(); }
	};
}

#endif