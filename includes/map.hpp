#ifndef MAP_HPP
# define MAP_HPP

# include <iostream>
# include "utils.hpp"
# include "rb_tree.hpp"

namespace ft
{
	template <class _Key, class _Tp, class _Compare = std::less<_Key>,
				class _Allocator = std::allocator<ft::pair<const _Key, _Tp> > >
	class map
	{
		public:
			typedef _Key								key_type;
			typedef _Tp									mapped_type;
			typedef pair<const key_type, mapped_type>	value_type;
			typedef _Compare							key_compare;
			typedef _Allocator							allocator_type;

			typedef typename allocator_type::reference			refernece;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

		private:
			typedef typename ft::tree<value_type, key_compare, allocator_type>	tree_type;

			tree_type tree;
	};
}

#endif