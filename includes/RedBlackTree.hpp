/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 04:19:05 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/03 18:41:30 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <memory>
# include <stddef.h>
# include "utility.hpp"
# include "iterators/type_traits.hpp"
# include "iterators/reverseIterator.hpp"

namespace ft
{
	typedef enum e_node_color {Black, Red}	node_color;

	template<class T>
	class Node
	{
	public:
		typedef T				value_type;
		typedef	Node*			pointer;
		typedef	Node&			reference;
		typedef	Node<T>*		link_type;


		value_type	data;
		node_color	color;
		pointer		left;
		pointer		right;
		pointer		parent;


		Node(): data(NULL), color(Black), left(NULL), right(NULL), parent(NULL) {}

		Node(const value_type &x): data(x), color(Black), left(NULL), right(NULL), parent(NULL) {}

		~Node() {}

		reference	operator=(const reference rhs)
		{
			if (this != &rhs)
			{
				this->data = rhs.data;
				this->color = rhs.color;
				this->left = rhs.left;
				this->right = rhs.right;
				this->parent = rhs.parent;
			}
			return (*this);
		}


		T	*operator->()
		{
			return (&this->data);
		}
	};






	template<class T>
	class RedBlackTree_iterator
	{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;
		typedef	RedBlackTree_iterator<T>*		link_type;


		pointer		current;


		RedBlackTree_iterator(): current(NULL) {}

		RedBlackTree_iterator(pointer ptr): current(ptr) {}

		RedBlackTree_iterator(const RedBlackTree_iterator &copy)
		{
			*this = copy;
		}

		~RedBlackTree_iterator() {}



		RedBlackTree_iterator	&operator=(const RedBlackTree_iterator &other)
		{
			if (this != &other)
				this->current = other.current;
			return (*this);
		}

		reference	operator*(void) const
		{
			return (*this->current);
		}

		value_type	operator->(void)
		{
			return (*this->current);
		}

		RedBlackTree_iterator	operator++(int)
		{
			//! implement post-increment
			return (RedBlackTree_iterator());
		}

		RedBlackTree_iterator	&operator++(void)
		{
			//! implement pre-increment
			return (*this);
		}

		RedBlackTree_iterator	operator--(int)
		{
			//! implement post-decrement
			return (RedBlackTree_iterator());
		}

		RedBlackTree_iterator	&operator--(void)
		{
			//! implement pre-decrement
			return (*this);
		}

		operator RedBlackTree_iterator<const T>() const {
			return (RedBlackTree_iterator<const T>(this->current));
		}
	};


	template<class Tx, class Ty>
	bool	operator==(const RedBlackTree_iterator<Tx> &x, const RedBlackTree_iterator<Ty> &y)
	{
		if (x.current == y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator!=(const RedBlackTree_iterator<Tx> &x, const RedBlackTree_iterator<Ty> &y)
	{
		if (x.current != y.current)
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
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;


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

		
		
		
		
		
		
		//*	iterators:
		iterator	begin()
		{

		}

		const_iterator	begin() const
		{
			
		}
		
		iterator	end(void)
		{
			return (this->sentry());
		}

		const_iterator	end(void) const
		{
			return (this->sentry());
		}

		const_reverse_iterator	rbegin() const
		{

		}

		reverse_iterator	rend()
		{

		}

		const_reverse_iterator	rend() const
		{
			
		}






		//*	capacity:
		size_type	size() const
		{
			return (this->_size);
		}






		//* modifier:
		ft::pair<iterator, bool>	insert(const value_type &x)
		{
			return (this->_insert(this->root(), x));
		}

		iterator	insert(iterator hint, const value_type &x)
		{
			pointer						node;
			ft::pair<iterator, bool>	ret;

			node = hint.current;
			if (node->parent != NULL && this->_comp(node->parent->data, x))
				ret = this->_insert(node, x);
			else
				ret = this->_insert(this->root(), x);
			return (ret.first);
		}

		void	erase(const value_type &x)
		{
			
		}






		//* observers:
		pointer	root(void) const
		{
			return (this->_root);
		}

		pointer	sentry(void) const
		{
			return (this->_sentry);
		}






		//* operations:
		iterator	search(const value_type &x)
		{
			return (this->_search(this->root(), x));
		}

		const_iterator	search(const value_type &x) const
		{
			return (this->_search(this->root(), x));
		}







		void	print(pointer node)
		{
			std::stringstream	buffer;

			this->_print(node, buffer, true, "");
			std::cout << buffer.str();
		}

		void	print(void)
		{
			std::stringstream	buffer;

			this->_print(this->root(), buffer, true, "");
			std::cout << buffer.str();
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

		ft::pair<iterator, bool>	_insert(pointer current, const value_type &x)
		{
			pointer	parent = NULL;
			pointer	node = this->_allocNode(x, this->sentry(), this->sentry(), Red);

			while (current != this->sentry())
			{
				parent = current;
				if (this->_comp(node->data, current->data))
					current = current->left;
				else if (this->_comp(current->data, node->data))
					current = current->right;
				else
				{
					this->_alloc.deallocate(node, 1);
					return (ft::make_pair(current, false));
				}
			}
			this->_size++;
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
				return (ft::make_pair(node, true));
			}
			if (node->parent->parent == NULL)
				return (ft::make_pair(node, true));
			this->_insertFix(node);
			return (ft::make_pair(node, true));
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
			if (child->right != this->sentry())
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

		iterator	_search(const pointer node, const value_type &x)
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

		const_iterator	_search(const pointer node, const value_type &x) const
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






		void	_print(pointer node, std::stringstream &buffer, bool isTail, std::string prefix)
		{
			if (node->right != this->sentry())
				this->_print(node->right, buffer, false, std::string(prefix).append(isTail ? "│   " : "    "));
			buffer << prefix << (isTail ? "└── " : "┌── ");
			if (node->color == Red)
				buffer << "\033[31m";
			buffer << node->data << "\033[0m" << std::endl;
			if (node->left != this->sentry())
				this->_print(node->left, buffer, true, std::string(prefix).append(isTail ? "    " : "│   "));
		}
	};
} // namespace ft
