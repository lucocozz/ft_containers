/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/19 22:11:17 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/20 10:37:59 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft
{
	template<class Iter1, class Iter2>
	bool	lexicographical_compare(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
		    if (*first1 < *first2)
				return (true);
		    if (*first2 < *first1)
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template<class Iter1, class Iter2, class Compare>
	bool	lexicographical_compare(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2, Compare cmp)
	{
		for (; (first1 != last1) && (first2 != last2); ++first1, ++first2)
		{
		    if (cmp(first1, first2))
				return (true);
		    if (cmp(first2, first1))
				return (false);
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template<class Iter1, class Iter2>
	bool	equal(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
	{
		while ((first1 != last1) && (first2 != last2))
		{
			if (*first1 != *first2)
				return (false);
			first1++, first2++;
		}
		return (true);
	}
}
