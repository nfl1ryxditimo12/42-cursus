#ifndef RB_TREE_HPP
# define RB_TREE_HPP

namespace ft
{
	template <class _Tp, class _Compare, class _Allocator>
	class tree
	{
		public:
			typedef _Tp			value_type;
			typedef _Compare	value_compare;
			typedef _Allocator	allocator_type;

			typedef typename allocator_type::reference			refernece;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

		
	};
}

#endif