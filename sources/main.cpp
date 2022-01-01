/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/01 22:08:45 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include "map.hpp"
#include "vector.hpp"

int	main()
{
	ft::map<int, int> titi;

	titi.insert(ft::make_pair(6, 6));
	titi.insert(ft::make_pair(2, 2));
	titi.insert(ft::make_pair(1, 1));
	titi.insert(ft::make_pair(3, 3));
	titi.insert(ft::make_pair(5, 5));
	titi.insert(ft::make_pair(7, 7));
	titi.insert(ft::make_pair(4, 4));
	titi.insert(ft::make_pair(0, 0));
	titi.insert(ft::make_pair(-1, -1));
	titi.insert(ft::make_pair(-2, -2));

	return (0);
}

