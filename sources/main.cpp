/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:27:42 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/19 16:18:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
#include "vector.hpp"
#include "map.hpp"
#include <list>

#define TESTED_NAMESPACE ft

#define T1 char
#define T2 int
typedef TESTED_NAMESPACE::pair<const T1, T2> T3;

template<class T>
void	printMap(T &mp)
{
	typename T::iterator	it;

	for (it = mp.begin(); it != mp.end(); it++)
		std::cout << it->second << std::endl;;
}

int	main()
{
	return (0);
}
