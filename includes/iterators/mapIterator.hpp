/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapIterator.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:40:08 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/22 19:57:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <stddef.h>
# include "type_traits.hpp"

namespace ft
{
	template<class T>
	class map_iterator
	{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::bidirectional_iterator_tag	iterator_category;


		pointer			current;


		map_iterator(): current(NULL) {}

		map_iterator(pointer ptr): current(ptr) {}

		map_iterator(const map_iterator<T> &copy)
		{
			*this = copy;
		}

		~map_iterator() {}



		map_iterator<T>	&operator=(const map_iterator<T> &other)
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

		map_iterator<T>	operator++(int)
		{
			//! implement post-increment
			return (map_iterator());
		}

		map_iterator<T>	&operator++(void)
		{
			//! implement pre-increment
			return (*this);
		}

		map_iterator<T>	operator--(int)
		{
			//! implement post-decrement
			return (map_iterator());
		}

		map_iterator<T>	&operator--(void)
		{
			//! implement pre-decrement
			return (*this);
		}
	};


	template<class Tx, class Ty>
	bool	operator==(const map_iterator<Tx> &x, const map_iterator<Ty> &y)
	{
		if (x.current == y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator!=(const map_iterator<Tx> &x, const map_iterator<Ty> &y)
	{
		if (x.current != y.current)
			return (true);
		return (false);
	}
}
