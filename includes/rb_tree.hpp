#ifndef RB_TREE_HPP
# define RB_TREE_HPP

# include <iostream>
# include "RB_TREE_iterator.hpp"
# include "utils.hpp"

namespace ft
{
	template <class _Tp, class _Compare>
	class rb_tree
	{
		public:

			/*************************************/
			/*           Define Types            */
			/*************************************/

			typedef _Tp					value_type;
			typedef _Compare			compare_type;
			typedef _Tp&				reference;
			typedef const _Tp&			const_reference;
			typedef ft::rb_node<_Tp>	node_type;
			typedef node_type*			node_pointer;

			typedef std::allocator<node_type> 					allocator_type;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef typename ft::rb_tree_iterator<_Tp, node_pointer>	iterator;

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

			// struct ERROR_CASE {
			// 	ft::rb_tree::node_pointer	node = ;
			// 	ERROR_FLAG		flag = NONE;
			// 	int				black_count = 0;
			// };

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
				_alloc.construct(_end, node_type());
				_root = _end;
			}

			rb_tree(const rb_tree &cls)
			: _size(0), _alloc(cls._alloc), _comp(cls.comp)
			{
				_end = _alloc.allocate(1);
				_alloc.construct(_end, node_type());
				_root = _end;
				*this = cls;
			}

			/*************************************/
			/*             Destructor            */
			/*************************************/

			~rb_tree()
			{
				/* clear, deallocate, destroy */
			}

			/*************************************/
			/*              Operator             */
			/*************************************/

			rb_tree &operator=(const rb_tree &cls)
			{
				(void)cls;
				return NULL;
			}

		public:

			/*************************************/
			/*             Modifiers             */
			/*************************************/

			pair<iterator, bool> insert (const value_type &val)
			{
				node_pointer parent;
				node_pointer new_node = create_node(val);
				node_pointer &dest = find_pos(parent, val, new_node);
				node_pointer result = insert_node(parent, dest);
				

				return pair<iterator, bool>(iterator(result), dest == u_nullptr ? true : false);
			}

			iterator insert (iterator position, const value_type &val)
			{
				(void)position;
				(void)val;
			}

			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				(void)first;
				(void)last;
			}

			node_pointer root() { return this->_end->left; }

		private:


			node_pointer create_node(const value_type &val)
			{
				node_pointer node = _alloc.allocate(1);
				_alloc.construct(node, node_type(val));
				return node;
			}

			node_pointer grand_parent_node(node_pointer node)
			{
				if (node != u_nullptr && node->parent != u_nullptr)
					return node->parent->parent;
				return u_nullptr;
			}
		
			node_pointer uncle_node(node_pointer node)
			{
				node_pointer grandNode = grand_parent_node(node);

				if (grandNode != u_nullptr) {
					if (node->parent == grandNode->left)
						return grandNode->right;
					else
						return grandNode->left;
				}
				return u_nullptr;
			}

			// node_pointer find_data_pos(const_reference val)
			// {
			// 	// node_pointer
			// }

			node_pointer find_pos(node_pointer &parent, const_reference val)
			{
				node_pointer node = this->root();
				parent = this->_end;

				while (node != u_nullptr) {
					parent = node;
					if (node->data <= val)
						node = node->right;
					else
						node = node->left;
				}
				return node;
			}

			// node_pointer find_case();

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
				if (dest == u_nullptr) {
					dest = new_node;
					dest->parent = parent;
					if (this->_root->left != u_nullptr)
						this->_root = this->_root->left;
					this->_size++;
				}
				return dest;
			}

			// void rebuild_tree(node_pointer pos)
			// {
			// 	ERROR_CASE		error_case;
			// 	node_pointer	node;

			// 	while ((error_case = check_tree(error_case)).flag == NONE)
			// 	{
			// 		node = error_case.node;
			// 		if (error_case.flag == ROOT_IS_NOT_BLACK)
			// 			this->_root->color = BLACK;
			// 		if (error_case.flag == DOUBLE_RED) {

			// 		}
			// 		if (error_case.flag == BLACK_COUNT_NOT_VALID)
			// 	}
			// }
	};
}

#endif