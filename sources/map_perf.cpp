/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_perf.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:27:42 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/19 23:28:18 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include "map.hpp"


#define NAMESPACE ft
#define INSERT 1000000
#define MAP	NAMESPACE::map<int, int>

int		main(void)
{
	MAP				map;
	MAP				cpy;
	MAP::iterator	it;

	for (int i = 0; i < INSERT; i++)
		map.insert(NAMESPACE::make_pair(i, i));
	map.find(42);
	map.find(34);
	map.find(435);
	map.find(232);
	map.find(5756);
	map.find(904242);
	map.find(575645346);
	map.find(0);
	cpy = map;
	it = map.begin();
	for (int i = 0; i < INSERT / 2; i++)
		it++;
	map.erase(map.begin(), it);
	return (0);
}
