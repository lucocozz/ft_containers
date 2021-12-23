/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:38:36 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/23 01:14:27 by lucocozz         ###   ########.fr       */
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

namespace ft
{
	template<class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<ft::pair<const Key, T>>>
	class map
	{
	public:
		typedef Key											key_type;
		typedef T											mapped_type;
		typedef ft::pair<const Key, T>						value_type;
		typedef Compare										key_compare;
		typedef Allocator									allocator_type;
		typedef typename Allocator::reference				reference;
		typedef typename Allocator::const_reference			const_reference;
		typedef	typename ft::map_iterator<value_type>		iterator;
		typedef typename ft::map_iterator<const value_type>	const_iterator;
		typedef	size_t										size_type;
		typedef ptrdiff_t									difference_type;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		typedef enum e_color {Black, Red}	t_color;

		typedef struct s_node
		{
			t_color			color;
			struct s_node	*parent;
			struct s_node	*left;
			struct s_node	*right;
		}					t_node;


		//*	attributes:
		key_compare			_comp;
		allocator_type		_alloc;
		size_type			_size;
		t_node				_root;



	public:
		class value_compare: public std::binary_function<value_type, value_type, bool>
		{
			friend class map;
		
		protected:
			Compare _comp;
			value_compare(Compare c): _comp(c) {}

		public:
			bool	operator()(const value_type &x, const value_type &y) const
			{
				return (cmp(x.first, y.first));
			}
		};






		//* construct/copy/destroy:
		explicit map(const Compare &comp, const Allocator &alloc = Allocator()):
			_comp(comp), _alloc(alloc), _size(0), _root(NULL)
		{
			
		}

		template <class InputIterator>
		map(InputIterator first, InputIterator last, const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()):
			_comp(comp), _alloc(alloc), _size(0), _root(NULL)
		{
			
		}

		map(const map &x)
		{
			*this = x;
		}

		~map()
		{
			
		}

		map	&operator=(const map &other)
		{
			if (this != &other)
			{
				this->_comp = other._comp;
				this->_alloc = other._alloc;
				this->clear();
				this->insert(this->begin(), other.begin(), other.end());
			}
			return (*this);
		}






		//*	iterators:
		iterator			begin()
		{

		}

		const_iterator	begin() const
		{

		}

		iterator	end()
		{

		}

		const_iterator	end() const
		{
			
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

		}

		size_type	size() const
		{

		}

		size_type	max_size() const
		{

		}






		//*	element access:
		mapped_type	&operator[](const key_type &x)
		{

		}






		//*	modifiers:
		value_type	insert(const value_type &x)
		{

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

		}

		void	swap(map &x)
		{

		}

		void	clear()
		{
			
		}






		//*	observers:
		key_compare	key_comp() const
		{

		}

		value_compare	value_comp() const
		{
			
		}






		//*	map operations:
		iterator	find(const key_type &x)
		{

		}

		const_iterator	find(const key_type &x) const
		{

		}

		size_type	count(const key_type &x) const
		{

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
		
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		
	}


	template<class Key, class T, class Compare, class Allocator>
	bool	operator<(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator>(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		
	}

	template<class Key, class T, class Compare, class Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		
	}





	//*	specialized algorithms:
	template<class Key, class T, class Compare, class Allocator>
	bool	swap(const map<Key, T, Compare, Allocator> &lhs, const map<Key, T, Compare, Allocator> & rhs)
	{
		lhs.swap(rhs);
	}
}
