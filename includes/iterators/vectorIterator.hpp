/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:05:00 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/05 19:21:44 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <stddef.h>
# include "type_traits.hpp"

namespace ft
{
	template<class T>
	class vector_iterator
	{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;

		pointer			current;

	public:
		vector_iterator(): current(NULL) {}

		vector_iterator(pointer ptr): current(ptr) {}

		vector_iterator(const vector_iterator<T> &copy)
		{
			*this = copy;
		}

		~vector_iterator() {}




		vector_iterator<T>	&operator=(const vector_iterator<T> &copy)
		{
			if (this != &copy)
				this->current = copy.current;
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

		reference	operator[](int index)
		{
			return (this->current[index]);
		}

		vector_iterator<T>	operator++(int)
		{
			vector_iterator<T>	tmp(*this);
		
			this->current++;
			return (tmp);
		}

		vector_iterator<T>	&operator++(void)
		{
			this->current++;
			return (*this);
		}

		vector_iterator<T>	operator--(int)
		{
			vector_iterator<T>	tmp(*this);
		
			this->current--;
			return (tmp);
		}

		vector_iterator<T>	&operator--(void)
		{
			this->current--;
			return (*this);
		}

		vector_iterator<T>	&operator+=(difference_type value)
		{
			this->current += value;
			return (*this);
		}

		vector_iterator<T>	operator+(difference_type value)
		{
			vector_iterator<T>	tmp(this->current + value);

			return (tmp);
		}

		vector_iterator<T>	&operator-=(difference_type value)
		{
			this->current -= value;
			return (*this);
		}

		vector_iterator<T>	operator-(difference_type value)
		{
			vector_iterator<T>	tmp(this->current - value);
		
			return (tmp);
		}

		difference_type		operator-(const vector_iterator<T> &object) const
		{
			return (this->current - object.current);
		}

		difference_type		operator+(const vector_iterator<T> &object) const
		{
			return (this->current + object.current);
		}

		operator vector_iterator<const T>() const {
			return (vector_iterator<const T>(this->current));
		}
	};

	


	template<class Tx, class Ty>
	bool	operator==(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current == y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator!=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current != y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator>=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current >= y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator<=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current <= y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator<(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current < y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator>(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current > y.current)
			return (true);
		return (false);
	}
}




template<class T>
ft::vector_iterator<T>	operator+(int value, const ft::vector_iterator<T> &object)
{
	return (object.current + value);	
}

template<class T>
ft::vector_iterator<T>	operator-(int value, const ft::vector_iterator<T> &object)
{
	return (object.current - value);	
}
