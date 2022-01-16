/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTree.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 04:19:05 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/16 17:55:52 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <memory>
# include <stddef.h>
# include "utility.hpp"
# include "type_traits.hpp"
# include "iterator.hpp"

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


		value_type	data;
		node_color	color;
		pointer		left;
		pointer		right;
		pointer		parent;


		Node(): data(NULL), color(Black), left(NULL), right(NULL), parent(NULL) {}

		Node(const value_type &x): data(x), color(Black), left(NULL), right(NULL), parent(NULL) {}

		~Node() {}

		reference	operator=(reference rhs)
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
	};

	template<class Tx, class Ty>
	bool	operator==(const Node<Tx> &x, const Node<Ty> &y)
	{
		if (x.data == y.data)
			return (true);
		return (false);
	}
















	template<class Node_type, class Value_type>
	class RedBlackTree_iterator
	{
	public:
		typedef Node_type						node_type;
		typedef Value_type						value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef value_type*						pointer;
		typedef value_type&						reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;


		node_type		*current;


		RedBlackTree_iterator():
			current(NULL), _end(NULL) {}

		RedBlackTree_iterator(node_type *ptr):
			current(ptr), _end(NULL) {}

		RedBlackTree_iterator(node_type *ptr, node_type *sentry):
			current(ptr), _end(sentry) {}


		RedBlackTree_iterator(const RedBlackTree_iterator &copy)
		{
			*this = copy;
		}

		~RedBlackTree_iterator() {}



		RedBlackTree_iterator	&operator=(const RedBlackTree_iterator &other)
		{
			if (this != &other)
			{
				this->current = other.current;
				this->_end = other._end;
			}
			return (*this);
		}

		value_type	&operator*(void)
		{
			return (this->current->data);
		}

		const value_type	&operator*(void) const
		{
			return (this->current->data);
		}

		value_type	*operator->(void)
		{
			return (&this->operator*());
		}

		const value_type	*operator->(void) const
		{
			return (&this->operator*());
		}

		RedBlackTree_iterator	operator++(int)
		{
			RedBlackTree_iterator	it(*this);

			this->current = this->_increase();
			return (it);
		}

		RedBlackTree_iterator	&operator++(void)
		{
			this->current = this->_increase();
			return (*this);
		}

		RedBlackTree_iterator	operator--(int)
		{
			RedBlackTree_iterator	it(*this);

			this->current = this->_decrease();
			return (it);
		}

		RedBlackTree_iterator	&operator--(void)
		{
			this->current = this->_decrease();
			return (*this);
		}

		operator RedBlackTree_iterator<const Node_type, const Value_type>(void) const
		{
			return (RedBlackTree_iterator<const Node_type, const Value_type>(this->current, this->_end));
		}





	private:
		node_type			*_end;

		node_type	*_minimum(node_type *node)
		{
			node_type	*current = node;

			while (current->left != this->_end)
				current = current->left;
			return (current);
		}

		node_type	*_maximum(node_type *node)
		{
			node_type	*current = node;

			while (current->right != this->_end)
				current = current->right;
			return (current);
		}

		node_type	*_topIncrease(node_type *node)
		{
			node_type	*current = node;
			node_type	*parent = current->parent;

			while (parent != NULL && current == parent->right)
			{
				current = parent;
				parent = parent->parent;
			}
			if (parent == NULL)
				current = this->_end;
			else
				current = parent;
			return (current);
		}

		node_type	*_topDecrease(node_type *node)
		{
			node_type	*current = node;
			node_type	*parent = current->parent;

			while (parent != NULL && current == parent->left)
			{
				current = parent;
				parent = parent->parent;
			}
			if (parent == NULL)
				current = this->_end;
			else
				current = parent;
			return (current);
		}

		node_type	*_increase(void)
		{
			if (this->current == this->_end && this->_end->parent != NULL)
				return (this->_minimum(this->current->parent));
			if (this->current->right == this->_end)
				return (this->_topIncrease(this->current));
			return (this->_minimum(this->current->right));
		}

		node_type	*_decrease(void)
		{
			if (this->current == this->_end && this->_end->parent != NULL)
				return (this->_maximum(this->current->parent));
			if (this->current->left == this->_end)
				return (this->_topDecrease(this->current));
			return (this->_maximum(this->current->left));
		}
	};



	template<class Tx, class Ux, class Ty, class Uy>
	bool	operator==(const RedBlackTree_iterator<Tx, Ux> &x, const RedBlackTree_iterator<Ty, Uy> &y)
	{
		if (x.current == y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ux, class Ty, class Uy>
	bool	operator!=(const RedBlackTree_iterator<Tx, Ux> &x, const RedBlackTree_iterator<Ty, Uy> &y)
	{
		if (x.current != y.current)
			return (true);
		return (false);
	}
















	template<class T, class Compare = std::less<T>, class Allocator = std::allocator<ft::Node<T> > >
	class RedBlackTree
	{
	public:
		typedef T																		value_type;
		typedef Node<value_type>														node_type;
		typedef Compare																	key_compare;
		typedef Allocator																allocator_type;
		typedef node_type*																pointer;
		typedef	typename ft::RedBlackTree_iterator<node_type, value_type>				iterator;
		typedef typename ft::RedBlackTree_iterator<const node_type, const value_type>	const_iterator;
		typedef	size_t																	size_type;
		typedef ft::reverse_iterator<iterator>											reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>									const_reverse_iterator;


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
			this->_sentry = this->_allocNode(value_type(), NULL, NULL, Black);
			this->_root = this->_sentry;
			*this = copy;
		}

		~RedBlackTree()
		{
			this->clear();
			this->_deallocNode(this->_sentry);
		}

		RedBlackTree	&operator=(const RedBlackTree &other)
		{
			node_type const	*node = NULL;

			if (this != &other)
			{
				this->clear();
				for (const_iterator it = other.begin(); it != other.end(); it++)
				{
					node = it.current;
					this->insert(node->data);
				}
			}
			return (*this);
		}

		
		
		
		
		
		
		//*	iterators:
		iterator	begin()
		{
			return (iterator(this->_minimum(this->root()), this->sentry()));
		}

		const_iterator	begin() const
		{
			return (const_iterator(this->_minimum(this->root()), this->sentry()));
		}
		
		iterator	end(void)
		{
			return (iterator(this->sentry(), this->sentry()));
		}

		const_iterator	end(void) const
		{
			return (const_iterator(this->sentry(), this->sentry()));
		}

		reverse_iterator	rbegin()
		{
			return (reverse_iterator(iterator(this->_maximum(this->root()), this->sentry())));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(const_iterator(this->_maximum(this->root()), this->sentry())));
		}

		reverse_iterator	rend()
		{
			return (reverse_iterator(iterator(this->sentry(), this->sentry())));
		}

		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(const_iterator(this->sentry(), this->sentry())));
		}






		//*	capacity:
		size_type	size() const
		{
			return (this->_size);
		}

		size_type	max_size() const
		{
			return (this->_alloc.max_size());
		}





		//* modifier:
		ft::pair<iterator, bool>	insert(const value_type &x)
		{
			pointer						node;
			ft::pair<iterator, bool>	ret;

			node = this->_allocNode(x, this->sentry(), this->sentry(), Red);
			ret = this->_insert(this->root(), node);
			if (ret.second == false)
				this->_deallocNode(node);
			return (ret);
		}

		iterator	insert(iterator hint, const value_type &x)
		{
			ft::pair<iterator, bool>	ret;
			pointer						node;
			pointer						current = hint.current;
			pointer						parent = current->parent;

			node = this->_allocNode(x, this->sentry(), this->sentry(), Red);
			while (parent != NULL && this->_comp(parent->data, x))
			{
				current = current->parent;
				parent = parent->parent;
			}
			if (hint.current == this->sentry() || parent == NULL)
				current = this->root();
			ret = this->_insert(current, node);
			if (ret.second == false)
				this->_deallocNode(node);
			return (ret.first);
		}

		size_type	erase(const value_type &x)
		{
			iterator	it = this->search(x);
			
			if (it == this->end())
				return (0);
			this->_erase(it.current);
			return (1);
		}

		void	erase(iterator position)
		{
			if (position != this->end())
				this->_erase(position.current);
		}

		void	clear()
		{
			while (this->root() != this->sentry())
				this->_erase(this->root());
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
			const_iterator	it = this->_search(this->root(), x);

			return (it);
		}

		iterator	lower_bound(const value_type &x)
		{
			iterator	it = this->begin();

			while (it != this->end() && this->_comp(x, it.current->data))
				it++;
			return (it);
		}

		const_iterator	 lower_bound(const value_type &x) const
		{
			const_iterator	it = this->begin();

			while (it != this->end() && this->_comp(x, it.current->data))
				it++;
			return (it.current);
		}

		iterator	upper_bound(const value_type &x)
		{
			iterator	it = this->begin();

			while (it != this->end() && !this->_comp(x, it.current->data))
				it++;
			return (it);
		}

		const_iterator	upper_bound(const value_type &x) const
		{
			const_iterator	it = this->begin();

			while (it != this->end() && !this->_comp(x, it.current->data))
				it++;
			return (it.current);
		}

		ft::pair<iterator, iterator>	equal_range(const value_type &x)
		{
			ft::pair<iterator, iterator>	range;

			range.first = this->lower_bound(x);
			range.second = this->upper_bound(x);
			return (range);
		}

		ft::pair<const_iterator, const_iterator>	equal_range(const value_type &x) const
		{
			ft::pair<const_iterator, const_iterator>	range;

			range.first = this->lower_bound(x);
			range.second = this->upper_bound(x);
			return (range);
		}







		void	print(pointer node)
		{
			std::stringstream	buffer;

			std::cout << "size: " << this->size() << std::endl;
			if (node != this->sentry())
			{
				this->_print(node, buffer, true, "");
				std::cout << buffer.str();
			}
		}

		void	print(void)
		{
			std::stringstream	buffer;

			std::cout <<  "size: " << this->size() << std::endl;
			if (this->root() != this->sentry())
			{
				this->_print(this->root(), buffer, true, "");
				std::cout << buffer.str();
			}
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

		void	_deallocNode(pointer node)
		{
			this->_alloc.destroy(node);
			this->_alloc.deallocate(node, 1);
		}

		void	_relinkSentry(void)
		{
			if (this->sentry() != this->root())
				this->_sentry->parent = this->root();
			else
				this->_sentry->parent = NULL;
		}






		ft::pair<iterator, bool>	_insert(pointer current, pointer node)
		{
			pointer	parent = NULL;

			while (current != this->sentry())
			{
				parent = current;
				if (this->_comp(node->data, current->data))
					current = current->left;
				else if (this->_comp(current->data, node->data))
					current = current->right;
				else
					return (ft::make_pair(current, false));
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
				this->_relinkSentry();
				return (ft::make_pair(node, true));
			}
			if (node->parent->parent == NULL)
			{
				this->_relinkSentry();
				return (ft::make_pair(node, true));
			}
			this->_insertFix(node);
			this->_relinkSentry();
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

		
		
		
		
		
		void	_erase(pointer node)
		{
			pointer		x;
			pointer		y = node;
			node_color	originalColor = node->color;

			if (node->left == this->sentry())
			{
				x = node->right;
				this->_transplant(node, node->right);
			}
			else if (node->right == this->sentry())
			{
				x = node->left;
				this->_transplant(node, node->left);
			}
			else
			{
				y = this->_minimum(node->right);
				originalColor = y->color;
				x = y->right;
				if (y->parent == node)
					x->parent = y;
				else
				{
					this->_transplant(y, y->right);
					y->right = node->right;
					y->right->parent = y;
				}
				this->_transplant(node, y);
				y->left = node->left;
				y->left->parent = y;
				y->color = node->color;
			}
			this->_deallocNode(node);
			if (originalColor == Black)
				this->_eraseFix(x);
			this->_size--;
			this->_relinkSentry();
		}

		void	_eraseFix(pointer node)
		{
			pointer	uncle;

			while (node != this->root() && node->color == Black)
			{
				if (node == node->parent->left)
				{
					uncle = node->parent->right;
					if (uncle->color == Red)
					{
						uncle->color = Black;
						node->parent->color = Red;
						this->_leftRotate(node->parent);
						uncle = node->parent->right;
					}
					if (uncle->left->color == Black && uncle->right->color == Black)
					{
						uncle->color = Red;
						node = node->parent;
					}
					else
					{
						if (uncle->right->color == Black)
						{
							uncle->left->color = Black;
							uncle->color = Red;
							this->_rightRotate(uncle);
							uncle = node->parent->right;
						}
						uncle->color = node->parent->color;
						node->parent->color = Black;
						uncle->right->color = Black;
						this->_leftRotate(node->parent);
						node = this->root();
					}
				}
				else
				{
					uncle = node->parent->left;
					if (uncle->color == Red)
					{
						uncle->color = Black;
						node->parent->color = Red;
						this->_rightRotate(node->parent);
						uncle = node->parent->left;
					}
					if (uncle->right->color == Black && uncle->left->color == Black)
					{
						uncle->color = Red;
						node = node->parent;
					}
					else
					{
						if (uncle->left->color == Black)
						{
							uncle->right->color = Black;
							uncle->color = Red;
							this->_leftRotate(uncle);
							uncle = node->parent->left;
						}
						uncle->color = node->parent->color;
						node->parent->color = Black;
						uncle->left->color = Black;
						this->_rightRotate(node->parent);
						node = this->root();
					}
				}
			}
			node->color = Black;
		}






		void	_transplant(pointer node, pointer transplanted)
		{
			if (node->parent == NULL)
				this->_root = transplanted;
			else if (node == node->parent->left)
				node->parent->left = transplanted;
			else
				node->parent->right = transplanted;
			transplanted->parent = node->parent;
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






		pointer	_minimum(pointer node)
		{
			pointer	current = node;

			if (current != this->sentry())
			{
				while (current->left != this->sentry())
					current = current->left;
			}
			return (current);
		}

		pointer	_minimum(pointer node) const
		{
			pointer	current = node;

			if (current != this->sentry())
			{
				while (current->left != this->sentry())
					current = current->left;
			}
			return (current);
		}

		pointer	_maximum(pointer node)
		{
			pointer	current = node;

			if (current != this->sentry())
			{
				while (current->right != this->sentry())
					current = current->right;
			}
			return (current);
		}

		pointer	_maximum(pointer node) const
		{
			pointer	current = node;

			if (current != this->sentry())
			{
				while (current->right != this->sentry())
					current = current->right;
			}
			return (current);
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
