/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 04:19:05 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/01 22:16:32 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <memory>
# include "utility.hpp"

# define SPACE 5

namespace ft
{
	typedef enum e_node_color {Black, Red}	node_color;

	template<class T>
	class Node
	{
	public:
		T			data;
		node_color	color;
		Node		*left;
		Node		*right;
		Node		*parent;

		Node(): data(NULL), color(Black), left(NULL), right(NULL), parent(NULL) {}

		Node(const T &x): data(x), color(Black), left(NULL), right(NULL), parent(NULL) {}

		~Node() {}
	};

	template<class Tx, class Ty>
	bool	operator==(const Node<Tx> &x, const Node<Ty> &y)
	{
		if (&x == &y)
			return (true);
		return (false);
	}






	template<class T, class Compare = std::less<T>, class Allocator = std::allocator<Node<T> > >
	class RedBlackTree
	{
	public:
		typedef T														value_type;
		typedef Node<value_type>										node_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef node_type*												pointer;
		typedef	typename ft::RedBlackTree_iterator<node_type>			iterator;
		typedef typename ft::RedBlackTree_iterator<const node_type>		const_iterator;
		typedef	size_t													size_type;


	private:
		pointer						_root;
		pointer						_sentry;
		allocator_type				_alloc;
		key_compare					_comp;
		size_type					_size;


	public:
		RedBlackTree(): _alloc(allocator_type()), _comp(key_compare()), _size(0)
		{
			this->_sentry = this->_allocNode(value_type(), NULL, NULL, Black);
			this->_root = this->_sentry;
		}

		explicit RedBlackTree(const Compare	&comp, const Allocator &alloc = Allocator()):
			_alloc(alloc), _comp(comp), _size(0)
		{
			this->_sentry = this->_allocNode(value_type(), NULL, NULL, Black);
			this->_root = this->_sentry;
		}

		RedBlackTree(const RedBlackTree &copy): _root(NULL), _size(0)
		{
			*this = copy;
		}

		~RedBlackTree()
		{
			this->_alloc.deallocate(this->_sentry, 1); //? probably free at end
		}

		RedBlackTree	&operator=(const RedBlackTree &other)
		{
			if (*this != &other)
			{
				
			}
			return (*this);
		}






		pointer	root(void) const
		{
			return (this->_root);
		}

		pointer	sentry(void) const
		{
			return (this->_sentry);
		}

		size_type	size() const
		{
			return (this->_size);
		}







		iterator	search(const pointer node, const value_type &x)
		{
			pointer	current = node;

			while (current != this->sentry())
			{
				if (this->_comp(x, current->data))
					current = current->left;
				else if (this->_comp(current->data, x))
					current = current->right;
				else
					return (current);
			}
			return (this->end());
		}

		void	insert(const value_type &x)
		{
			pointer	parent = NULL;
			pointer	current = this->root();
			pointer	node = this->_allocNode(x, this->_sentry, this->_sentry, Red);

			this->_size++;
			while (current != this->_sentry)
			{
				parent = current;
				if (this->_comp(node->data, current->data))
					current = current->left;
				else
					current = current->right;
			}
			node->parent = parent;
			if (parent == NULL)
				this->_root = node;
			else if (this->_comp(node->data, parent->data))
				parent->left = node;
			else
				parent->right = node;
			if (node->parent == NULL)
			{
				node->color = Black;
				return;
			}
			if (node->parent->parent == NULL)
				return;
			this->_insertFix(node);
		}






		iterator	end()
		{
			return (this->sentry());
		}

		const_iterator	end() const
		{
			return (this->sentry());
		}





		void	print(pointer node) const
		{
			this->_print(node, 0);
		}






	private:
		pointer	_allocNode(const value_type &x, pointer left, pointer right, node_color color)
		{
			pointer	node = this->_alloc.allocate(1);

			this->_alloc.construct(node, x);
			node->left = left;
			node->right = right;
			node->color = color;
			return (node);
		}

		void	_insertFix(pointer node)
		{
			pointer	uncle = NULL;

			while (node->parent->color == Red)
			{
				if (node->parent == node->parent->parent->right)
				{
					uncle = node->parent->parent->left;
					if (uncle->color == Red)
					{
						uncle->color = Black;
						node->parent->color = Black;
						node->parent->parent->color = Red;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->left)
						{
							node = node->parent;
							this->_rightRotate(node);
						}
						node->parent->color = Black;
						node->parent->parent->color = Red;
						this->_leftRotate(node->parent->parent);
					}
				}
				else
				{
					uncle = node->parent->parent->right;
					if (uncle->color == Red)
					{
						uncle->color = Black;
						node->parent->color = Black;
						node->parent->parent->color = Red;
						node = node->parent->parent;
					}
					else
					{
						if (node == node->parent->right)
						{
							node = node->parent;
							this->_leftRotate(node);
						}
						node->parent->color = Black;
						node->parent->parent->color = Red;
						this->_rightRotate(node->parent->parent);
					}
				}
				if (node == this->root())
					break;
			}
			this->_root->color = Black;
		}

		void	_leftRotate(pointer node)
		{
			pointer	child = node->right;

			node->right = child->left;
			if (child->left != this->sentry())
				child->left->parent = node;
			child->parent = node->parent;
			if (node->parent == NULL)
				this->_root = child;
			else if (node == node->parent->left)
				node->parent->left = child;
			else
				node->parent->right = child;
			child->left = node;
			node->parent = child;
		}

		void	_rightRotate(pointer node)
		{
			pointer	child = node->left;

			node->left = child->right;
			if (child->right != this->_sentry)
				child->right->parent = node;
			child->parent = node->parent;
			if (node->parent == NULL)
				this->_root = child;
			else if (node == node->parent->right)
				node->parent->right = child;
			else
				node->parent->left = child;
			child->right = node;
			node->parent = child;
		}

		void	_print(pointer node, int space) const
		{
			if (node == this->_sentry)
				return;
			space += SPACE;
			this->_print(node->right, space);
			if (node->color == Red)
				std::cout << "\033[31m";
			std::cout << std::string(space, ' ') << node->data << "\033[0m" << std::endl;
			this->_print(node->left, space);
		}
	};
} // namespace ft
