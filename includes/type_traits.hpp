/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 00:58:27 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/17 03:03:55 by lucocozz         ###   ########.fr       */
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




	template <typename T>
    struct is_integral {
		static const bool value = false;
	};

    template <>
    struct is_integral<bool> {
		static const bool value = true;
	};
        
    template <>
    struct is_integral<char> {
		static const bool value = true;
	};

    template <>
    struct is_integral<short> {
		static const bool value = true;
	};

    template <>
    struct is_integral<int> {
		static const bool value = true;
	};

    template <>
    struct is_integral<long> {
		static const bool value = true;
	};

    template <>
    struct is_integral<long long> {
		static const bool value = true;
	};

    template <>
    struct is_integral<unsigned char> {
		static const bool value = true;
	};

    template <>
    struct is_integral<unsigned short> {
		static const bool value = true;
	};

    template <>
    struct is_integral<unsigned int> {
		static const bool value = true;
	};

    template <>
    struct is_integral<unsigned long> {
		static const bool value = true;
	};

    template <>
    struct is_integral<unsigned long long> {
		static const bool value = true;
	};
}
