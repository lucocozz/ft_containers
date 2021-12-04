/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:41:16 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/04 22:14:41 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <memory>
# include <iostream>
# include <string>
# include  "Iterator.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T>>
	class Vector:
	{
	private:
		size_t	_capacity;
		size_t	_size;
		T		*_data;
	public:
		typedef typename Allocator::reference				reference;
		typedef typename Allocator::const_reference			const_reference;
		typedef typename vector_iterator<T>					iterator;
		typedef typename vector_iterator<const T>			const_iterator;
		typedef typename size_t								size_type;
		typedef typename ptrdiff_t							difference_type;					
		typedef	T											value_type;
		typedef Allocator									allocator_type;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;


		template <class Category = std::random_access_iterator_tag, class T,
			class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
		struct vector_iterator {
		  typedef T         value_type;
		  typedef Distance  difference_type;
		  typedef Pointer   pointer;
		  typedef Reference reference;
		  typedef Category  iterator_category;
		};

		// explicit vector (const allocator_type &alloc = allocator_type());
		// explicit vector (size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type());
		Vector(const Vector &copy);
		~Vector();
		Vector	&operator=(const Vector &object);
	};

	#include "Vector.ipp"
}
