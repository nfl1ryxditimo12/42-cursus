#ifndef RB_TREE_ITERATOR_HPP
# define RB_TREE_ITERATOR_HPP

# include <iostream>
# include "utils.hpp"

namespace ft
{
	template <class T, class NodePtr>
	class rb_tree_iterator
	{
		public:

			typedef T			value_type;
			typedef T& 			reference;
			typedef T*			pointer;
			typedef NodePtr		node_pointer;
			typedef size_t		size_type;
			typedef long int	difference_type;

			typedef std::bidirectional_iterator_tag	iterator_category;

		private:

			node_pointer _node;

		public:

			rb_tree_iterator() {}

			rb_tree_iterator(const node_pointer &node): _node(node) {}

			rb_tree_iterator(const rb_tree_iterator &cls): _node(cls.base()) {}

			// rb_tree_iterator(const const_iterator &cls): _node(cls.base()) {}

			~rb_tree_iterator() {}

			rb_tree_iterator &operator=(const rb_tree_iterator &cls)
			{
				this->_node = cls.base();
				return *(this);
			}

			reference operator*() { return _node->data; }

			pointer operator->() { return &_node->data; }

			bool operator==(const rb_tree_iterator &cls)
			{ return this->base() == cls.base(); }

			bool operator!=(const rb_tree_iterator &cls)
			{ return !(*this == cls); }

			node_pointer base() { return _node; }
	};
}

#endif