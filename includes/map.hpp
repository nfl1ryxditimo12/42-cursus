#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "utils.hpp"
# include "RB_TREE.hpp"

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

		private:
			typedef typename ft::rb_tree<value_type, value_compare>	tree_type;

			key_compare _comp;
			allocator_type _alloc;
			tree_type _tree;

		public:
			map(const key_compare& comp = key_compare(),
              	const allocator_type& alloc = allocator_type())
			: _comp(comp), _alloc(alloc), _tree(value_compare(comp)) {}


			pair<iterator,bool> insert (const value_type& val)
			{
				
			}
	};
}

#endif