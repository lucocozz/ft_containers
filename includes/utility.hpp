/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:23:36 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/22 00:37:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template<class T1, class T2>
	struct pair
	{
		typedef	T1	first_type;
		typedef T2	second_type;

		first_type	first;
		second_type	second;

		pair(): first(first_type()), second(second_type()) {}

		pair(const T1 &x, const T2 &y): first(x, y) {}

		template<class U1, class U2>
		pair(const pair<U1, U2> &p): first(p.first), second(p.second) {}

		pair	&operator=(const pair &other)
		{
			this->first = other.first;
			this->first = other.second;
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
}
