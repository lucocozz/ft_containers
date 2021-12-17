/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:05:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/16 23:45:50 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <stddef.h>
# include "utils.hpp"

namespace ft
{
	template <class T>
	class vector_iterator
	{
	public:
		typedef T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef std::random_access_iterator_tag	iterator_category;
		
		pointer				current;

		vector_iterator();
		vector_iterator(pointer ptr);
		vector_iterator(const vector_iterator<T> &copy);
		~vector_iterator();
		vector_iterator<T>	&operator=(const vector_iterator<T> &copy);
		reference			operator*(void) const;
		pointer				operator->(void) const;
		reference			operator[](int index);
		vector_iterator<T>	operator++(int);
		vector_iterator<T>	&operator++(void);
		vector_iterator<T>	operator--(int);
		vector_iterator<T>	&operator--(void);
		vector_iterator<T>	&operator+=(int value);
		vector_iterator<T>	operator+(int value);
		vector_iterator<T>	&operator-=(int value);
		vector_iterator<T>	operator-(int value);
		difference_type		operator-(const vector_iterator<T> &object) const;

		operator ft::vector_iterator<const T>() const {
			return (ft::vector_iterator<const T>(this->current));
		}
	};

	template<class Tx, class Ty>
		bool	operator==(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y);
	template<class Tx, class Ty>
		bool	operator!=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y);
	template<class Tx, class Ty>
		bool	operator<=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y);
	template<class Tx, class Ty>
		bool	operator>=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y);
	template<class Tx, class Ty>
		bool	operator>(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y);
	template<class Tx, class Ty>
		bool	operator<(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y);
}

template<class T>
	ft::vector_iterator<T>	operator+(int value, const ft::vector_iterator<T> &object);
template<class T>
	ft::vector_iterator<T>	operator-(int value, const ft::vector_iterator<T> &object);


# include "vectorIterator.ipp"
