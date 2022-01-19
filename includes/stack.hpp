/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 22:46:18 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/20 00:42:23 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include "vector.hpp"

namespace ft
{
	template<class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef typename Container::value_type	value_type;
		typedef typename Container::size_type	size_type;
		typedef Container						container_type;
	
	protected:
		Container	c;
	
	public:
		explicit stack(const Container &c = Container()): c(c) {}

		~stack() {}

		stack	&operator=(const stack &other)
		{
			if (this != &other)
				c = other.c;
			return (*this);
		}

		bool	empty() const
		{
			return (c.empty());
		}

		size_type	size() const
		{
			return (c.size());
		}

		value_type	&top()
		{
			return (c.back());
		}

		value_type	&top() const
		{
			return (c.back());
		}

		void	push(const value_type &x)
		{
			c.push_back(x);
		}

		void	pop()
		{
			c.pop_back();
		}

		template<class T1, class Container1>
		friend bool	operator==(const stack<T1, Container1>&, const stack<T1, Container1>&);

		template<class T1, class Container1>
		friend bool	operator<(const stack<T1, Container1>&, const stack<T1, Container1>&);
	};




	template<class T, class Container>
	bool	operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c == rhs.c);
	}

	template<class T, class Container>
	bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Container>
	bool	operator<(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs.c < rhs.c);
	}
	
	template<class T, class Container>
	bool	operator>(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Container>
	bool	operator<=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs == rhs || lhs < rhs);
	}

	template<class T, class Container>
	bool	operator>=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return (lhs == rhs || rhs < lhs);
	}
}
