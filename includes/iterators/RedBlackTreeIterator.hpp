/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RedBlackTreeIterator.hpp                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/31 11:24:17 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/01 14:15:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <stddef.h>
# include "type_traits.hpp"

namespace ft
{
	template<class T>
	class RedBlackTree_iterator
	{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;


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

		pointer	operator->(void) const
		{
			return (this->current);
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
		if (x.current == y.current)
			return (false);
		return (true);
	}
}
