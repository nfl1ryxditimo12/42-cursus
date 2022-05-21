#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <iostream>
# include "RB_TREE_iterator.hpp"
# include "utils.hpp"

namespace ft
{
	template <class _Key, class _Value, class value_type, class _Compare>
	class rb_tree
	{
		public:

			/*************************************/
			/*           Define Types            */
			/*************************************/

			typedef _Key							key_type;
			typedef _Value							mapped_type;
			typedef _Compare						compare_type;
			typedef value_type&						reference;
			typedef const value_type&				const_reference;
			typedef ft::rb_node<value_type>			node_type;
			typedef node_type*						node_pointer;

			typedef std::allocator<node_type> 					allocator_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef ft::rb_tree_iterator<value_type, node_pointer>	iterator;
			typedef ft::rb_tree_const_iterator<value_type, node_pointer> const_iterator;

		private:

			/*************************************/
			/*         Member Variables          */
			/*************************************/

			enum ERROR_FLAG {
				// LEAF,
				ROOT_IS_NOT_BLACK,
				DOUBLE_RED,
				BLACK_COUNT_NOT_VALID,
				NONE
			};

			class ERROR_CASE
			{
				public:
					ERROR_FLAG		flag;
					node_pointer	node;
					int				black_count;

					ERROR_CASE(): flag(NONE), node(u_nullptr), black_count(0) {}
					ERROR_CASE(node_pointer node): flag(NONE), node(node), black_count(0) {}
					~ERROR_CASE() {}
			};
		
			allocator_type _alloc;
			compare_type _comp;
			node_pointer _root;
			node_pointer _end;
			node_pointer _leaf;
			size_type _size;

			/**
			 * 기본 연산 (탐색, 삽입, 삭제)
			 * 
			 * 탐색 - 이진 트리와 똑같이 구현하면 된다
			 * 삽입 - 회전 - 우회전, 좌회전
			*/

		public:

			/*************************************/
			/*            Constructor            */
			/*************************************/

			rb_tree(const compare_type &comp = compare_type())
			: _alloc(allocator_type()), _comp(comp), _size(0)
			{
				_end = _alloc.allocate(1);
				_leaf = _alloc.allocate(1);
				_alloc.construct(_end, node_type());
				_alloc.construct(_leaf, node_type());
				_leaf->type = LEAF;
				_end->left = _leaf;
				_end->right = _leaf;
				_root = _end;
			}

			rb_tree(const rb_tree &cls)
			: _alloc(cls._alloc), _comp(cls._comp), _size(0)
			{
				_end = _alloc.allocate(1);
				_leaf = _alloc.allocate(1);
				_alloc.construct(_end, node_type());
				_alloc.construct(_leaf, node_type());
				_leaf->type = LEAF;
				_end->left = _leaf;
				_end->right = _leaf;
				_root = _end;
				*this = cls;
			}

			/*************************************/
			/*             Destructor            */
			/*************************************/

			~rb_tree()
			{
				this->clear();
				this->_alloc.destroy(this->_end);
				this->_alloc.destroy(this->_leaf);
				this->_alloc.deallocate(this->_end, 1);
				this->_alloc.deallocate(this->_leaf, 1);
			}

			/*************************************/
			/*              Operator             */
			/*************************************/

			rb_tree &operator=(const rb_tree &cls)
			{
				if (this != &cls) {
					this->clear();
					this->_alloc = cls._alloc;
					this->_comp = cls._comp;
					this->insert(cls.begin(), cls.end());
				}
				return *this;
			}

		public:

			/*************************************/
			/*             Iterators             */
			/*************************************/

			iterator begin()
			{ return iterator(this->tree_min(this->root())); }

			const_iterator begin() const
			{ return const_iterator(this->tree_min(this->root())); }

			iterator end() { return this->_end; }
			
			const_iterator end() const { return this->_end; }

			node_pointer root() { return this->_end->left; }

			node_pointer root() const { return this->_end->left; }

			/*************************************/
			/*             Capacity              */
			/*************************************/

			bool empty() const { return this->_size == 0; }

			size_type size() const { return this->_size; }

			size_type max_size() const { return std::min<size_type>(_alloc.max_size(), std::numeric_limits<difference_type>::max()); }

			/*************************************/
			/*             Modifiers             */
			/*************************************/

			pair<iterator, bool> insert (const_reference val)
			{
				node_pointer parent;
				node_pointer new_node = create_node(val);
				node_pointer &dest = find_pos(parent, val);
				bool inserted = dest == this->_leaf ? true : false;
				node_pointer result = insert_node(parent, dest, new_node);
				rebuild_tree(dest);
				this->_root = this->root();

				return pair<iterator, bool>(iterator(result), inserted);
			}

			iterator insert (iterator position, const_reference val)
			{
				node_pointer parent;
				node_pointer new_node = create_node(val);
				node_pointer &dest = find_pos(position, parent, val);
				node_pointer result = insert_node(parent, dest, new_node);
				rebuild_tree(dest);
				return iterator(result);
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				for (; first != last; first++)
					insert(*first);
			}

			/* Erase */

			void erase (iterator position) { this->remove_node(position.base()); }

			/* Swap */

			void swap (rb_tree& cls)
			{
				std::swap(this->_alloc, cls._alloc);
				std::swap(this->_comp, cls._comp);
				std::swap(this->_end, cls._end);
				std::swap(this->_leaf, cls._leaf);
				std::swap(this->_root, cls._root);
				std::swap(this->_size, cls._size);
			}

			/* Clear */

			void clear()
			{
				clear_tree(this->root());
				this->_root = this->_end;
				this->_size = 0;
				this->_end->left = this->_leaf;
			}

			/*************************************/
			/*             Operations            */
			/*************************************/

			/* Find */

			template <class key_type>
			iterator find (const key_type &k)
			{
				iterator pos = this->lower_bound(k);
				if (pos != this->end() && !this->_comp(k, *pos))
					return pos;
				return this->end();
			}

			template <class key_type>
			const_iterator find (const key_type& k) const
			{
				const_iterator pos = this->lower_bound(k);
				if (pos != this->end() && !this->_comp(k, *pos))
					return pos;
				return this->end();
			}

			/* Lower_bound */

			template <class key_type>
			iterator lower_bound (const key_type& k)
			{
				node_pointer root = this->root();
				node_pointer ret = this->_end;

				while (root != this->_leaf) {
					if (!this->_comp(root->data, k)) {
						ret = root;
						root = root->left;
					} else
						root = root->right;
				}
				return iterator(ret);
			}

			template <class key_type>
			const_iterator lower_bound (const key_type& k) const
			{
				node_pointer root = this->root();
				node_pointer ret = this->_end;

				while (root != this->_leaf) {
					if (!this->_comp(root->data, k)) {
						ret = root;
						root = root->left;
					} else
						root = root->right;
				}
				return const_iterator(ret);
			}

			/* Upper_bound */

			template <class key_type>
			iterator upper_bound (const key_type& k)
			{
				node_pointer root = this->root();
				node_pointer ret = this->_end;

				while (root != this->_leaf) {
					if (this->_comp(k, root->data)) {
						ret = root;
						root = root->left;
					} else
						root = root->right;
				}
				return iterator(ret);
			}

			template <class key_type>
			const_iterator upper_bound (const key_type& k) const
			{
				node_pointer root = this->root();
				node_pointer ret = this->_end;

				while (root != this->_leaf) {
					if (this->_comp(k, root->data)) {
						ret = root;
						root = root->left;
					} else
						root = root->right;
				}
				return const_iterator(ret);
			}

			/*************************************/
			/*             Allocator             */
			/*************************************/

			allocator_type get_allocator() const { return this->_alloc; }

		private:


			node_pointer create_node(const value_type &val)
			{
				node_pointer node = _alloc.allocate(1);
				_alloc.construct(node, node_type(val));
				node->left = _leaf;
				node->right = _leaf;
				return node;
			}

			node_pointer &find_pos(node_pointer &parent, const_reference val)
			{
				node_pointer node = this->root();
				parent = this->_end;

				while (node != this->_leaf) {
					parent = node;
					if (this->_comp(val, node->data)) {
						if (node->left != this->_leaf)
							node = node->left;
						else
							return parent->left;
					}
					else if (this->_comp(node->data, val))
						if (node->right != this->_leaf)
							node = node->right;
						else
							return parent->right;
					else
						return parent;
				}
				return parent->left;
			}

			node_pointer &find_pos(iterator position, node_pointer &parent, const_reference val)
			{
				if (position == this->end() || this->_comp(val, *position)) {
					iterator prev = position;
					if (prev == this->begin() || this->_comp(*(--prev), val)) {
						if (position.base()->left == this->_leaf) {
							parent = position.base();
							return parent->left;
						} else {
							parent = prev.base();
							return parent->right;
						}
					}
					return find_pos(parent, val);
				} else if (this->_comp(*position, val)) {
					iterator next = position;
					++next;
					if (next == this->end() || this->_comp(val, *next)) {
						if (position.base()->right == this->_leaf) {
							parent = position.base();
							return parent->right;
						} else {
							parent = next.base();
							return parent->left;
						}
					}
					return find_pos(parent, val);
				}
				parent = position.base();
				return parent;
			}

			ERROR_CASE check_tree(ERROR_CASE error_case)
			{
				node_pointer node = error_case.node;

				if (node == this->root() && node->color == RED) {
					error_case.flag = ROOT_IS_NOT_BLACK;
					return error_case;
				}
				if (node == u_nullptr || error_case.flag != NONE)
					return error_case;

				if (node->color == BLACK)
					error_case.black_count++;
				if (node->color == RED && (node->left->color == RED || node->right->color == RED)) {
					error_case.flag = DOUBLE_RED;
					return error_case;
				}

				error_case.node = node->left;
				ERROR_CASE left = check_tree(error_case);
				error_case.node = node->right;
				ERROR_CASE right = check_tree(error_case);
				error_case.node = node;

				if (node->left != u_nullptr && node->right != u_nullptr \
					&& left.black_count != right.black_count)
					error_case.flag = BLACK_COUNT_NOT_VALID;

				if (left.flag != NONE)
					error_case = left;
				if (right.flag != NONE)
					error_case = right;

				return error_case;
			}

			// Insert Function

			node_pointer insert_node(node_pointer parent, node_pointer &dest, node_pointer new_node)
			{
				if (dest == this->_leaf) {
					dest = new_node;
					dest->parent = parent;
					if (dest == this->root()) {
						dest->type = NODE;
						this->_root = dest;
					}
					this->_size++;
				}
				return dest;
			}

			void rotate_right(node_pointer node)
			{
				node_pointer left_child = node->left;
				node->left = left_child->right;
				if (node->left != this->_leaf)
					node->left->parent = node;
				left_child->parent = node->parent;
				if (is_left_node(node))
					node->parent->left = left_child;
				else
					node->parent->right = left_child;
				left_child->right = node;
				node->parent = left_child;
			}

			void rotate_left(node_pointer node)
			{
				node_pointer right_child = node->right;
				node->right = right_child->left;
				if (node->right != this->_leaf)
					node->right->parent = node;
				right_child->parent = node->parent;
				if (is_left_node(node))
					node->parent->left = right_child;
				else
					node->parent->right = right_child;
				right_child->left = node;
				node->parent = right_child;
			}

			void rebuild_tree(node_pointer pos)
			{
				while (pos != this->root() && pos->parent->color == RED) {
					if (pos->parent == pos->parent->parent->left) {
						node_pointer uncle = pos->parent->parent->right;
						if (uncle != this->_leaf && uncle->color == RED) {
							pos->parent->color = BLACK;
							uncle->color = BLACK;
							pos->parent->parent->color = RED;
							pos = pos->parent->parent;
						} else {
							if (pos == pos->parent->right) {
								pos = pos->parent;
								rotate_left(pos);
							}
							pos->parent->color = BLACK;
							pos->parent->parent->color = RED;
							rotate_right(pos->parent->parent);
							break;
						}
					} else {
						node_pointer uncle = pos->parent->parent->left;
						if (uncle != this->_leaf &&  uncle->color == RED) {
							pos->parent->color = BLACK;
							uncle->color = BLACK;
							pos->parent->parent->color = RED;
							pos = pos->parent->parent;
						} else {
							if (pos == pos->parent->left) {
								pos = pos->parent;
								rotate_right(pos);
							}
							pos->parent->color = BLACK;
							pos->parent->parent->color = RED;
							rotate_left(pos->parent->parent);
							break;
						}
					}
				}
				this->root()->color = BLACK;
			}

			void remove_node(node_pointer node)
			{
				iterator iter(node);
				++iter;
				if (node == this->begin().base())
					this->begin() = iter.base();
				--this->_size;
				this->_root = this->root();
				remove_and_rebuild_tree(node);
			}

			void remove_and_rebuild_tree(node_pointer node)
			{
				node_pointer remove = (node->left == this->_leaf || node->right == this->_leaf) ?
								node : tree_next(node);
				node_pointer successor = remove->left != this->_leaf ? remove->left : remove->right;
				node_pointer sibling = this->_leaf;
				if (successor != this->_leaf)
					successor->parent = remove->parent;
				if (is_left_node(remove))
				{
					remove->parent->left = successor;
					if (remove != this->_root)
						sibling = remove->parent->right;
					else
						this->_root = successor;
				}
				else
				{
					remove->parent->right = successor;
					sibling = remove->parent->left;
				}
				Color removed_black = remove->color;
				if (remove != node)
				{
					remove->parent = node->parent;
					if (is_left_node(node))
						remove->parent->left = remove;
					else
						remove->parent->right = remove;
					remove->left = node->left;
					remove->left->parent = remove;
					remove->right = node->right;
					if (remove->right != this->_leaf)
						remove->right->parent = remove;
					remove->color = node->color;
					if (this->_root == node)
						this->_root = remove;
				}
				if (removed_black == BLACK && this->_root != this->_leaf)
				{
					if (successor != this->_leaf)
						successor->color = BLACK;
					else
					{
						while (true)
						{
							if (!is_left_node(sibling))
							{
								if (sibling->color == RED)
								{
									sibling->color = BLACK;
									sibling->parent->color = RED;
									rotate_left(sibling->parent);
									if (this->_root == sibling->left)
										this->_root = sibling;
									sibling = sibling->left->right;
								}
								if ((sibling->left  == this->_leaf || sibling->left->color == BLACK) &&
									(sibling->right == this->_leaf || sibling->right->color == BLACK))
								{
									sibling->color = RED;
									successor = sibling->parent;
									if (successor == this->_root || successor->color == RED)
									{
										successor->color = BLACK;
										break;
									}
									sibling = is_left_node(successor) ?
												successor->parent->right :
												successor->parent->left;
								}
								else
								{
									if (sibling->right == this->_leaf || sibling->right->color == BLACK)
									{
										sibling->left->color = BLACK;
										sibling->color = RED;
										rotate_right(sibling);
										sibling = sibling->parent;
									}
									sibling->color = sibling->parent->color;
									sibling->parent->color = BLACK;
									sibling->right->color = BLACK;
									rotate_left(sibling->parent);
									break;
								}
							}
							else
							{
								if (sibling->color == RED)
								{
									sibling->color = BLACK;
									sibling->parent->color = RED;
									rotate_right(sibling->parent);
									if (this->_root == sibling->right)
										this->_root = sibling;
									sibling = sibling->right->left;
								}
								if ((sibling->left  == this->_leaf || sibling->left->color == BLACK) &&
									(sibling->right == this->_leaf || sibling->right->color == BLACK))
								{
									sibling->color = RED;
									successor = sibling->parent;
									if (successor->color == RED || successor == this->_root)
									{
										successor->color = BLACK;
										break;
									}
									sibling = is_left_node(successor) ?
												successor->parent->right :
												successor->parent->left;
								}
								{
									if (sibling->left == this->_leaf || sibling->left->color == BLACK)
									{
										sibling->right->color = BLACK;
										sibling->color = RED;
										rotate_left(sibling);
										sibling = sibling->parent;
									}
									sibling->color = sibling->parent->color;
									sibling->parent->color = BLACK;
									sibling->left->color = BLACK;
									rotate_right(sibling->parent);
									break;
								}
							}
						}
					}
				}
			}

			node_pointer tree_min(node_pointer node)
			{
				if (this->_root == this->_end || this->_root == this->_leaf)
					return this->_end;
				while (node->left != this->_leaf)
					node = node->left;
				return node;
			}

			node_pointer tree_min(node_pointer node) const
			{
				if (this->_root == this->_end || this->_root == this->_leaf)
					return this->_end;
				while (node->left != this->_leaf)
					node = node->left;
				return node;
			}

			node_pointer tree_next(node_pointer node)
			{
				if (node->right != this->_leaf)
					return tree_min(node->right);
				while (node != node->parent->left)
					node = node->parent;
				return node->parent;
			}

			bool is_left_node(node_pointer node) { return node == node->parent->left; }

			bool is_right_node(node_pointer node) { return node == node->parent->right; }

			bool is_leaf_node(node_pointer node) { return node == this->_leaf; }
			
			void clear_tree(node_pointer node)
			{
				if (node != this->_leaf) {
					clear_tree(node->left);
					clear_tree(node->right);
					this->_alloc.destroy(node);
					this->_alloc.deallocate(node, 1);
				}
			}
	};
}

#endif