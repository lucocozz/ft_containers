/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:38:36 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/14 17:47:12 by lucocozz         ###   ########.fr       */
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
		typedef	typename ft::RedBlackTree<value_type>::iterator			iterator;
		typedef typename ft::RedBlackTree<value_type>::const_iterator	const_iterator;
		typedef typename Allocator::reference							reference;
		typedef typename Allocator::const_reference						const_reference;
		typedef	std::size_t												size_type;
		typedef std::ptrdiff_t											difference_type;
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
			_comp(comp), _alloc(alloc)
		{
			this->insert(first, last);
		}

		map(const map &x)
		{
			*this = x;
		}

		~map()
		{
			// this->_tree.print();
		}

		map	&operator=(const map &other)
		{
			if (this != &other)
			{
				this->_comp = other._comp;
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
			return (this->_tree.begin());
		}

		const_iterator	begin() const
		{
			return (this->_tree.begin());
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
			return (this->_tree.rbegin());
		}

		const_reverse_iterator	rbegin() const
		{
			return (this->_tree.rbegin());
		}

		reverse_iterator	rend()
		{
			return (this->_tree.rend());
		}

		const_reverse_iterator	rend() const
		{
			return (this->_tree.rend());
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
			return (this->_tree.max_size());
		}






		//*	element access:
		mapped_type	&operator[](const key_type &key)
		{
			ft::pair<iterator, bool>	it;

			it = this->insert(ft::make_pair(key, mapped_type()));
			return (it.first->second);
		}

		//*	modifiers:
		ft::pair<iterator, bool>	insert(const value_type &x)
		{
			return (this->_tree.insert(x));
		}

		iterator	insert(iterator hint, const value_type &x)
		{
			return (this->_tree.insert(hint, x));
		}

		template<class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		insert(InputIterator first, InputIterator last)
		{
			while (first != last)
			{
				this->_tree.insert(*first);
				first++;
			}
		}

		size_type	erase(const key_type &x)
		{
			return (this->_tree.erase(ft::make_pair(x, mapped_type())));
		}
		
		void	erase(iterator position)
		{
			this->_tree.erase(position);
		}

		void	erase(iterator first, iterator last)
		{
			while (first != last)
			{
				this->_tree.erase(first);
				first++;
			}
		}

		void	swap(map &x)
		{
			std::swap(this->_tree, x._tree);
			std::swap(this->_comp, x._comp);
		}

		void	clear()
		{
			this->_tree.clear();
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
		iterator	find(const key_type &key)
		{
			return (this->_tree.search(ft::make_pair(key, mapped_type())));
		}

		const_iterator	find(const key_type &key) const
		{
			return (this->_tree.search(ft::make_pair(key, mapped_type())));
		}

		size_type	count(const key_type &key) const
		{
			const_iterator	it = this->find(key);

			if (it == this->end())
				return (0);
			return (1);
		}

		iterator	lower_bound(const key_type &x)
		{
			return (this->_tree.lower_bound(ft::make_pair(x, mapped_type())));
		}

		const_iterator	 lower_bound(const key_type &x) const
		{
			return (this->_tree.lower_bound(ft::make_pair(x, mapped_type())));
		}

		iterator	upper_bound(const key_type &x)
		{
			return (this->_tree.upper_bound(ft::make_pair(x, mapped_type())));
		}

		const_iterator	upper_bound(const key_type &x) const
		{
			return (this->_tree.upper_bound(ft::make_pair(x, mapped_type())));
		}

		ft::pair<iterator, iterator>	equal_range(const key_type &x)
		{
			return (this->_tree.equal_range(ft::make_pair(x, mapped_type())));
		}

		ft::pair<const_iterator, const_iterator>	equal_range(const key_type &x) const
		{
			return (this->_tree.equal_range(ft::make_pair(x, mapped_type())));			
		}
	};



	template<class Key, class T, class Compare, class Allocator>
	bool	operator==(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		if (lhs == rhs)
			return (false);
		return (true);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator<(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return (!(rhs < lhs));
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator>(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return (rhs < lhs);
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		return (!(lhs < rhs));
	}





	//*	specialized algorithms:
	template<class Key, class T, class Compare, class Allocator>
	void	swap(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> &rhs)
	{
		lhs.swap(rhs);
	}
}
