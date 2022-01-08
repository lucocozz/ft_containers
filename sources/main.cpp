/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/08 18:06:47 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include "map.hpp"
#include "vector.hpp"

int	main()
{
	std::map<int, int> titi;
	std::map<int, int>::iterator it;

	titi.insert(std::make_pair(1, 1));
	titi.insert(std::make_pair(2, 2));
	titi.insert(std::make_pair(3, 3));
	titi.insert(std::make_pair(4, 4));
	titi.insert(std::make_pair(5, 5));
	titi.insert(std::make_pair(6, 6));
	titi.insert(std::make_pair(7, 7));
	titi.insert(std::make_pair(8, 8));
	titi.insert(std::make_pair(9, 9));

	titi[42] = 42;
	for (it = titi.begin(); it != titi.end(); it++)
		std::cout << it->first << " ";
	std::cout << std::endl;
	((it--)--)--;
	titi.insert(it, std::make_pair(12, 12));
	return (0);
}

