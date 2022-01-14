/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/13 23:53:06 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <list>
#include <vector>
#include "map.hpp"
#include "vector.hpp"
#include <iterator>

#define TESTED_NAMESPACE ft

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2>			mp1;
	TESTED_NAMESPACE::map<T1, T2>			mp2;
	TESTED_NAMESPACE::map<T1, T2>::const_iterator	it;

	mp1['a'] = 2; mp1['b'] = 3; mp1['c'] = 4; mp1['d'] = 5;
	mp2['a'] = 2; mp2['b'] = 3; mp2['c'] = 4; mp2['d'] = 5;

	it = mp1.begin();
	*it;
	// std::cout << "eq: " << (mp1 == mp2); // << " | ne: " << (mp1 != mp2) << std::endl;
	// std::cout << "lt: " << (mp1 <  mp2) << " | le: " << (mp1 <= mp2) << std::endl;
	// std::cout << "gt: " << (mp1 >  mp2) << " | ge: " << (mp1 >= mp2) << std::endl;
	// cmp(mp1, mp1); // 0
	// cmp(mp1, mp2); // 1

	// mp2['e'] = 6; mp2['f'] = 7; mp2['h'] = 8; mp2['h'] = 9;

	// cmp(mp1, mp2); // 2
	// cmp(mp2, mp1); // 3

	// (++(++mp1.begin()))->second = 42;

	// cmp(mp1, mp2); // 4
	// cmp(mp2, mp1); // 5

	// swap(mp1, mp2);

	// cmp(mp1, mp2); // 6
	// cmp(mp2, mp1); // 7

	return (0);
}
