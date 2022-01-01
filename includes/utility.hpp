/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:23:36 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/01 20:08:24 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <ostream>
namespace ft
{
	template<class T1, class T2>
	struct pair
	{
		typedef T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(): first(first_type()), second(second_type()) {}

		pair(const T1 &x, const T2 &y): first(x), second(y) {}

		template<class U1, class U2>
		pair(const pair<U1, U2> &p): first(p.first), second(p.second) {}

		pair	&operator=(const pair &other)
		{
			if (this != &other)
			{
				this->first = other.first;
				this->second = other.second;
			}
			return (*this);
		}
	};

	template<class T1, class T2>
	bool operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		if ((lhs.first == rhs.first) && (lhs.second == rhs.second))
			return (true);
		return (false);
	}

	template<class T1, class T2>
	bool operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T1, class T2>
	bool operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		if ((lhs.first < rhs.first) && (lhs.second < rhs.second))
			return (true);
		return (false);
	}

	template<class T1, class T2>
	bool operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(rhs < lhs));
	}

	template<class T1, class T2>
	bool operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T1, class T2>
	bool operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return (!(lhs < rhs));
	}

	template<class T1, class T2>
	std::ostream	&operator<<(std::ostream &out, const pair<T1, T2> &rhs)
	{
		out << rhs.second;
		return (out);
	}


	template<class T1, class T2>
	pair<T1, T2> make_pair(T1 t, T2 u)
	{
		return (pair<T1, T2>(t, u));
	}
}
