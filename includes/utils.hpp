/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:58:27 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/16 23:53:31 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template<class Iterator>
	struct iterator_traits
	{
	   typedef typename Iterator::iterator_category	iterator_category;
	   typedef typename Iterator::value_type		value_type;
	   typedef typename Iterator::difference_type	difference_type;
	   typedef difference_type						distance_type;
	   typedef typename Iterator::pointer			pointer;
	   typedef typename Iterator::reference			reference;
	};

	template<bool B, class T = void>
	struct enable_if {};
 
	template<class T>
	struct enable_if<true, T> {
		typedef T type;
	};
}
