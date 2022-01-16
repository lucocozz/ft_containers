/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/16 13:19:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"

#define NAMESPACE ft

int		main(void)
{
	NAMESPACE::vector<int> vec;
	NAMESPACE::vector<int>::iterator it;

	for (int i = 0; i < 1000000; i++)
	{
		vec.insert(vec.end(), i);
		vec.capacity();
	}
	it = vec.begin();
	for (int i = 0; i < 500000; i++)
		it++;
	vec.insert(it, 42);
	vec.erase(vec.begin(), it);
	return (0);
}
