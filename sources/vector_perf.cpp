/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_perf.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/22 17:03:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include "vector.hpp"

#define NAMESPACE ft
#define INSERT 1000000

int		main(void)
{
	NAMESPACE::vector<int>				vec;
	NAMESPACE::vector<int>::iterator	it;

	for (int i = 0; i < INSERT; i++)
		vec.insert(vec.end(), i);
	it = vec.begin();
	for (int i = 0; i < INSERT / 2; i++)
		it++;
	vec.insert(it, 42);
	vec.erase(vec.begin(), it);
	return (0);
}
