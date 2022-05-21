#ifndef RB_TREE_ITERATOR_HPP
# define RB_TREE_ITERATOR_HPP

# include <iostream>
# include "utils.hpp"

namespace ft
{
	template <class T, class NodePtr> class rb_tree_const_iterator;

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
			typedef ft::rb_tree_const_iterator<T, NodePtr> const_iterator;

		private:

			node_pointer _node;

		public:

			rb_tree_iterator() {}

			rb_tree_iterator(const node_pointer node): _node(node) {}

			rb_tree_iterator(const rb_tree_iterator &cls): _node(cls.base()) {}

			rb_tree_iterator(const const_iterator &cls): _node(cls.base()) {}

			~rb_tree_iterator() {}

			rb_tree_iterator &operator=(const rb_tree_iterator &cls)
			{
				this->_node = cls._node;
				return *(this);
			}

			reference operator*() const { return this->_node->data; }

			pointer operator->() const { return &this->_node->data; }

			bool operator==(const rb_tree_iterator &cls) const
			{ return this->_node == cls._node; }

			bool operator!=(const rb_tree_iterator &cls) const
			{ return this->_node != cls._node; }

			rb_tree_iterator operator++()
			{
				if (this->_node->right->type != LEAF) {
					tree_min(this->_node->right);
					return *this;
				}
				while (!is_left_child_node())
					this->_node = this->_node->parent;
				this->_node = this->_node->parent;
				return *this;
			}

			rb_tree_iterator operator++(int)
			{
				rb_tree_iterator temp(*this);
				++(*this);
				return temp;
			}

			rb_tree_iterator operator--()
			{
				if (this->_node->left->type != LEAF) {
					tree_max(this->_node->left);
					return (*this);
				}
				while (is_left_child_node())
					_node = _node->parent;
				_node = _node->parent;
				return *this;
			}

			rb_tree_iterator operator--(int)
			{
				rb_tree_iterator temp(*this);
				--(*this);
				return temp;
			}

			node_pointer base() const { return _node; }

		private:

			void tree_min(node_pointer node)
			{
				while (node->left->type != LEAF)
					node = node->left;
				this->_node = node;
			}

			void tree_max(node_pointer node)
			{
				while (node->right->type != LEAF)
					node = node->right;
				this->_node = node;
			}

			bool is_left_child_node()
			{ return this->_node == this->_node->parent->left; }

			bool is_right_child_node()
			{ return this->_node == this->_node->parent->right; }

			bool has_brother(node_pointer node)
			{
				return ((!is_right_child_node(node) && node->parent->right != u_nullptr)
						|| (!is_left_child_node(node) && node->parent->left != u_nullptr));
			}
	};

	template <class T, class NodePtr>
	class rb_tree_const_iterator
	{
		public:

			typedef T			value_type;
			typedef const T& 	reference;
			typedef const T*	pointer;
			typedef NodePtr		node_pointer;
			typedef size_t		size_type;
			typedef long int	difference_type;

			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef ft::rb_tree_iterator<T, NodePtr> non_const_iterator;

		private:

			node_pointer _node;

		public:

			rb_tree_const_iterator() {}

			rb_tree_const_iterator(const node_pointer node): _node(node) {}

			rb_tree_const_iterator(const rb_tree_const_iterator &cls): _node(cls.base()) {}

			rb_tree_const_iterator(non_const_iterator cls): _node(cls.base()) {}

			~rb_tree_const_iterator() {}

			rb_tree_const_iterator &operator=(const rb_tree_const_iterator &cls)
			{
				this->_node = cls._node;
				return *(this);
			}

			reference operator*() const { return this->_node->data; }

			pointer operator->() const { return &this->_node->data; }

			bool operator==(const rb_tree_const_iterator &cls) const
			{ return this->_node == cls._node; }

			bool operator!=(const rb_tree_const_iterator &cls) const
			{ return !(*this == cls); }

			rb_tree_const_iterator operator++()
			{
				if (this->_node->right->type != LEAF) {
					tree_min(this->_node->right);
					return (*this);
				}
				while (!is_left_child_node())
					_node = _node->parent;
				_node = _node->parent;
				return *this;
			}

			rb_tree_const_iterator operator++(int)
			{
				rb_tree_const_iterator temp(*this);
				++(*this);
				return temp;
			}

			rb_tree_const_iterator operator--()
			{
				if (this->_node->left->type != LEAF) {
					tree_max(this->_node->left);
					return (*this);
				}
				while (is_left_child_node())
					_node = _node->parent;
				_node = _node->parent;
				return *this;
			}

			rb_tree_const_iterator operator--(int)
			{
				rb_tree_const_iterator temp(*this);
				--(*this);
				return temp;
			}

			node_pointer base() const { return _node; }

		private:

			void tree_min(node_pointer node)
			{
				while (node->left->type != LEAF)
					node = node->left;
				this->_node = node;
			}

			void tree_max(node_pointer node)
			{
				while (node->right->type != LEAF)
					node = node->right;
				this->_node = node;
			}

			bool is_left_child_node()
			{ return this->_node == this->_node->parent->left; }

			bool is_right_child_node()
			{ return this->_node == this->_node->parent->right; }

			bool has_brother(node_pointer node)
			{
				return ((!is_right_child_node(node) && node->parent->right != u_nullptr)
						|| (!is_left_child_node(node) && node->parent->left != u_nullptr));
			}
	};
}

#endif