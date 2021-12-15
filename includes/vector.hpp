/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:41:16 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/14 20:36:24 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <memory>
# include <iostream>
# include <string>
# include <limits>
# include <stddef.h>
# include "reverseIterator.hpp"
# include "vectorIterator.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef typename Allocator::reference				reference;
		typedef typename Allocator::const_reference			const_reference;
		typedef typename ft::vector_iterator<T>				iterator;
		typedef typename ft::vector_iterator<const T>		const_iterator;
		typedef size_t										size_type;
		typedef ptrdiff_t									difference_type;					
		typedef	T											value_type;
		typedef Allocator									allocator_type;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		size_type		_capacity;
		size_type		_size;
		pointer			_data;
		allocator_type	_alloc;

	public:
		//* constructor/copy/destructor
		explicit vector(const Allocator& = Allocator());
		explicit vector(size_type n, const T &value = T(), const Allocator& = Allocator());
		vector(iterator first, iterator last, const Allocator& = Allocator());
		vector(const vector<T, Allocator> &x);
		~vector();
		vector<T, Allocator>	&operator=(const vector<T, Allocator> &x);
		void					assign(iterator first, iterator last);
		void					assign(size_type n, const T &u);
		allocator_type			get_allocator() const;

		//* iterators
		iterator				begin();
		const_iterator			begin() const;
		iterator				end();
		const_iterator			end() const;
		reverse_iterator		rbegin();
		const_reverse_iterator	rbegin() const;
		reverse_iterator		rend();
		const_reverse_iterator	rend() const;

		//* capacity
		size_type				size() const;
		size_type				max_size() const;
		void					resize(size_type size, T val = T());
		size_type				capacity() const;
		bool					empty() const;
		void					reserve(size_type n);

		//* element access
		reference				operator[](size_type n);
		const_reference			operator[](size_type n) const;
		const_reference			at(size_type n) const;
		reference				at(size_type n);
		reference				front();
		const_reference			front() const;
		reference				back();
		const_reference			back() const;

		//* modifiers
		void					push_back(const T &x);
		void					pop_back();
		iterator				insert(iterator position, const T &x);
		void					insert(iterator position, size_type n, const T &x);
		void					insert(iterator position, iterator first, iterator last);
		iterator				erase(iterator position);
		iterator				erase(iterator first, iterator last);
		void					swap(vector<T, Allocator> &x);
		void					clear();
		
		bool					operator==(const vector<T, Allocator> &object) const;
	};

	//* operator
template<class T, class Allocator>
	bool					operator!=(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template<class T, class Allocator>
	bool					operator<(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template<class T, class Allocator>
	bool					operator>(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template<class T, class Allocator>
	bool					operator<=(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
template<class T, class Allocator>
	bool					operator>=(const vector<T, Allocator> &x, const vector<T, Allocator> &y);
	
//* specialized algorithms
template<class T, class Allocator>
	void	swap(vector<T, Allocator> &x, vector<T, Allocator> &y);

}

# include "vector.ipp"
