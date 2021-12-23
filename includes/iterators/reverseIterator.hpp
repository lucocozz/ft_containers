/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseIterator.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:51:36 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/20 09:33:29 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "type_traits.hpp"

namespace ft
{
	template <class Iter>
	class reverse_iterator
	{
	public:
		typedef Iter													iterator_type;
		typedef typename ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename ft::iterator_traits<Iter>::value_type			value_type;
		typedef typename ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename ft::iterator_traits<Iter>::reference			reference;
		
		iterator_type		_base;

		reverse_iterator(): _base() {}

		explicit reverse_iterator(iterator_type x): _base(x) {}

		template<class U>
		reverse_iterator(const reverse_iterator<U> &other)
		{
			*this = other;
		}

		~reverse_iterator() {}



		iterator_type		base(void) const
		{
			return (this->_base);
		}

		template<class U>
		reverse_iterator &operator=(const reverse_iterator<U> &other)
		{
			this->_base = other.base();
			return (*this);
		}

		reference	operator*(void) const
		{
			iterator_type	tmp = this->base();

			--tmp;
			return (*tmp);
		}

		pointer	operator->(void) const
		{
			return (&(this->operator*()));
		}

		reference	operator[](int index)
		{
			return (this->_base[-index - 1]);
		}

		reverse_iterator	operator++(int)
		{
			return (reverse_iterator(this->_base.operator--(0)));
		}

		reverse_iterator	&operator++()
		{
			this->_base.operator--();
			return (*this);
		}

		reverse_iterator	operator--(int)
		{
			return (reverse_iterator(this->_base.operator++(0)));
		}

		reverse_iterator	&operator--()
		{
			this->_base.operator++();
			return (*this);
		}

		reverse_iterator	&operator+=(difference_type n)
		{
			this->_base.operator-=(n);
			return (*this);
		}

		reverse_iterator	operator+(difference_type n) const
		{
			return (reverse_iterator(this->base() - n));
		}

		reverse_iterator	&operator-=(difference_type n)
		{
			this->_base.operator+=(n);
			return (*this);
		}

		reverse_iterator	operator-(difference_type n) const
		{
			return (reverse_iterator(this->base() + n));
		}

		difference_type	operator-(const reverse_iterator<Iter> &other)
		{
			return (other.base() - this->base());
		}

		difference_type	operator+(const reverse_iterator<Iter> &other)
		{
			return (other.base() + this->base());
		}

		operator reverse_iterator<const Iter>() const {
			return (reverse_iterator<const Iter>(this->base()));
		}
	};

	


	template<class Iterator1, class Iterator2>
	bool operator==(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	}

	template<class Iterator1, class Iterator2>
	bool	operator!=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	}

	template<class Iterator1, class Iterator2>
	bool	operator>=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() <= rhs.base())
			return (true);
		return (false);
	}

	template<class Iterator1, class Iterator2>
	bool	operator<=(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() >= rhs.base())
			return (true);
		return (false);
	}

	template<class Iterator1, class Iterator2>
	bool	operator<(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() > rhs.base())
			return (true);
		return (false);
	}

	template<class Iterator1, class Iterator2>
	bool	operator>(const reverse_iterator<Iterator1> &lhs, const reverse_iterator<Iterator2> &rhs)
	{
		if (lhs.base() < rhs.base())
			return (true);
		return (false);
	}
}



template<class Iter>
ft::reverse_iterator<Iter>	operator+(int n, const ft::reverse_iterator<Iter> &it)
{
	return (it + n);	
}

template<class Iter>
ft::reverse_iterator<Iter>	operator-(int n, const ft::reverse_iterator<Iter> &it)
{
	return (it - n);	
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type
operator-(const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs)
{
	return (rhs.base() - lhs.base());
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>::difference_type
operator+(const ft::reverse_iterator<Iterator> &lhs, const ft::reverse_iterator<Iterator> &rhs)
{
	return (rhs.base() + lhs.base());
}
