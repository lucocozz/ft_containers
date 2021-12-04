/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 21:51:36 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/04 22:14:34 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

namespace ft
{
	template <class Iterator>
	class reverse_iterator
	{
	public:
		typedef Iterator					iterator_type;
		typedef Iterator::iterator_category	iterator_category;
		typedef Iterator::value_type		value_type;
		typedef Iterator::difference_type	difference_type;
		typedef Iterator::pointer			pointer;
		typedef Iterator::reference			reference;
	};
}
