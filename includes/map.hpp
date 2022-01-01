/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:38:36 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/01 21:35:54 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <memory>
# include <iostream>
# include <sstream>
# include <string>
# include <limits>
# include <stddef.h>
# include "iterator.hpp"
# include "algorithm.hpp"
# include "utility.hpp"
# include "RedBlackTree.hpp"

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key														key_type;
		typedef T														mapped_type;
		typedef ft::pair<const Key, T>									value_type;
		typedef Compare													key_compare;
		typedef Allocator												allocator_type;
		typedef typename Allocator::reference							reference;
		typedef typename Allocator::const_reference						const_reference;
		typedef	typename ft::RedBlackTree<value_type>::iterator			iterator;
		typedef typename ft::RedBlackTree<value_type>::const_iterator	const_iterator;
		typedef	size_t													size_type;
		typedef ptrdiff_t												difference_type;
		typedef typename Allocator::pointer								pointer;
		typedef typename Allocator::const_pointer						const_pointer;
		typedef ft::reverse_iterator<iterator>							reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>					const_reverse_iterator;



		class value_compare: public std::binary_function<value_type, value_type, bool>
		{
		protected:
		    key_compare _comp;

		public:
			value_compare(key_compare comp = key_compare()): _comp(comp) {}
			
			bool operator()(const value_type &lhs, const value_type &rhs) const {
				return (_comp(lhs.first, rhs.first));
			}
		};



	private:
		key_compare								_comp;
		allocator_type							_alloc;
		RedBlackTree<value_type, value_compare>	_tree;


	public:
		//* construct/copy/destroy:
		map(): _comp(key_compare()), _alloc(allocator_type()) {}

		explicit map(const Compare &comp, const Allocator &alloc = Allocator()):
			_comp(comp), _alloc(alloc) {}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):
			_comp(comp), _alloc(alloc) {}

		map(const map &x)
		{
			*this = x;
		}

		~map()
		{
			this->_tree.print(this->_tree.root());
		}

		map	&operator=(const map &other)
		{
			if (this != &other)
			{
				this->_comp = other._comp;
				this->_alloc = other._alloc;
				this->_tree = other._tree;
			}
			return (*this);
		}

		allocator_type	get_allocator() const
		{
			return (this->_alloc);
		}





		//*	iterators:
		iterator	begin()
		{

		}

		const_iterator	begin() const
		{
			
		}

		iterator	end()
		{
			return (this->_tree.end());
		}

		const_iterator	end() const
		{
			return (this->_tree.end());
		}

		reverse_iterator	rbegin()
		{

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
		bool	empty() const
		{
			if (this->size() == 0)
				return (true);
			return (false);
		}

		size_type	size() const
		{
			return (this->_tree.size());
		}

		size_type	max_size() const
		{
			return (this->_alloc.max_size());
		}






		//*	element access:
		mapped_type	&operator[](const key_type &x)
		{

		}

		mapped_type	&at(const Key &key)
		{
			iterator it = this->find(key);

			if (it == this->_tree.end())
				throw (std::out_of_range("map::at"));
			else
				return (*it);
		}

		const mapped_type	&at(const Key &key) const
		{
			iterator it = this->find(key);

			if (it == this->_tree.end())
				throw (std::out_of_range("map::at"));
			else
				return (*it);
		}



		//*	modifiers:
		value_type	insert(const value_type &x)
		{
			iterator	it = this->find(x.first);

			if (it == this->_tree.end())
				this->_tree.insert(x);
			return (x);
		}

		iterator	insert(iterator position, const value_type &x)
		{

		}

		template<class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		insert(InputIterator first, InputIterator last)
		{
			
		}

		void	erase(iterator position)
		{

		}

		size_type	erase(const key_type &x)
		{
			return (size_type());
		}

		void	swap(map &x)
		{
			std::swap(this->_tree, x._tree);
			std::swap(this->_comp, x._comp);
		}

		void	clear()
		{
			
		}






		//*	observers:
		key_compare	key_comp() const
		{
			return (key_compare());
		}

		value_compare	value_comp() const
		{
			return (value_compare());
		}






		//*	map operations:
		iterator	find(const key_type &x)
		{
			return (this->_tree.search(this->_tree.root(), ft::make_pair(x, mapped_type())));
		}

		const_iterator	find(const key_type &x) const
		{
			return (this->_tree.search(this->_tree.root(), ft::make_pair(x, mapped_type())));
		}

		size_type	count(const key_type &x) const
		{
			return (this->size());
		}



		iterator	lower_bound(const key_type &x)
		{

		}

		const_iterator	 lower_bound(const key_type &x) const
		{

		}

		iterator	upper_bound(const key_type &x)
		{

		}

		const_iterator	upper_bound(const key_type &x) const
		{

		}



		pair<iterator, iterator>	equal_range(const key_type &type)
		{

		}

		pair<const_iterator, const_iterator>	equal_range(const key_type &x) const
		{
			
		}
	};



	template<class Key, class T, class Compare, class Allocator>
	bool	operator==(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		return (true);
	}


	template<class Key, class T, class Compare, class Allocator>
	bool	operator<(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator>(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		return (true);
	}





	//*	specialized algorithms:
	template<class Key, class T, class Compare, class Allocator>
	void	swap(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		lhs.swap(rhs);
	}
}
