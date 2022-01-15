/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 19:46:54 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/14 19:52:39 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <string>
# include <stddef.h>
# include "type_traits.hpp"

namespace ft
{
	struct input_iterator_tag {};
	
	struct output_iterator_tag {};

	struct forward_iterator_tag: public input_iterator_tag {};

	struct bidirectional_iterator_tag: public forward_iterator_tag {};

	struct random_access_iterator_tag: public bidirectional_iterator_tag {};


	template <class Category, class T, class Distance = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
		typedef T         value_type;
		typedef Distance  difference_type;
		typedef Pointer   pointer;
		typedef Reference reference;
		typedef Category  iterator_category;
	};


	template<class Iter>
	struct iterator_traits
	{
		typedef typename Iter::iterator_category	iterator_category;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
	};

	template<class T>
	struct iterator_traits<T*>
	{
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
	};
	
	template<class T>
	struct iterator_traits<const T*>
	{
		typedef ft::random_access_iterator_tag	iterator_category;
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef const T*						pointer;
		typedef const T&						reference;
	};


	template<class InputIt>
	typename iterator_traits<InputIt>::difference_type distance(InputIt first, InputIt last)
	{
		typename iterator_traits<InputIt>::difference_type	dist;

		dist = 0;
		while (first != last)
			first++, dist++;
		return (dist);
	}







template <class Iter>
	class reverse_iterator: public ft::iterator<typename ft::iterator_traits<Iter>::iterator_category,
		typename ft::iterator_traits<Iter>::value_type,
		typename ft::iterator_traits<Iter>::difference_type,
		typename ft::iterator_traits<Iter>::pointer,
		typename ft::iterator_traits<Iter>::reference>
	{
	protected:
		Iter	_current;

		typedef iterator_traits<Iter>	_traits_type;

	public:
		typedef Iter										iterator_type;
		typedef typename _traits_type::iterator_category	iterator_category;
		typedef typename _traits_type::value_type			value_type;
		typedef typename _traits_type::difference_type		difference_type;
		typedef typename _traits_type::pointer				pointer;
		typedef typename _traits_type::reference			reference;
		
		reverse_iterator(): _current() {}

		explicit reverse_iterator(iterator_type x): _current(x) {}

		template<class U>
		reverse_iterator(const reverse_iterator<U> &x): _current(x.base()) {}

		~reverse_iterator() {}

		iterator_type		base(void) const
		{
			return (this->_current);
		}

		template<class U>
		reverse_iterator &operator=(const reverse_iterator<U> &other)
		{
			this->_current = other.base();
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
			return (this->_current[-index - 1]);
		}

		reverse_iterator	operator++(int)
		{
			return (reverse_iterator(this->_current.operator--(0)));
		}

		reverse_iterator	&operator++()
		{
			this->_current.operator--();
			return (*this);
		}

		reverse_iterator	operator--(int)
		{
			return (reverse_iterator(this->_current.operator++(0)));
		}

		reverse_iterator	&operator--()
		{
			this->_current.operator++();
			return (*this);
		}

		reverse_iterator	&operator+=(difference_type n)
		{
			this->_current.operator-=(n);
			return (*this);
		}

		reverse_iterator	operator+(difference_type n) const
		{
			return (reverse_iterator(this->base() - n));
		}

		reverse_iterator	&operator-=(difference_type n)
		{
			this->_current.operator+=(n);
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

	template<class Iter>
	reverse_iterator<Iter>	operator+(int n, const reverse_iterator<Iter> &it)
	{
		return (it + n);	
	}

	template<class Iter>
	reverse_iterator<Iter>	operator-(int n, const reverse_iterator<Iter> &it)
	{
		return (it - n);	
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type
	operator-(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() - lhs.base());
	}

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type
	operator+(const reverse_iterator<Iterator> &lhs, const reverse_iterator<Iterator> &rhs)
	{
		return (rhs.base() + lhs.base());
	}
} // namespace ft
