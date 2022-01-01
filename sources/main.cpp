/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/01 15:49:42 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <vector>
#include "map.hpp"
#include "vector.hpp"

int	main()
{
	std::map<int, int> titi;

	titi.insert(std::make_pair(6, 6));
	titi.insert(std::make_pair(2, 2));
	titi.insert(std::make_pair(1, 1));
	titi.insert(std::make_pair(3, 3));
	titi.insert(std::make_pair(5, 5));


	std::cout << titi.size() << std::endl;
	return (0);
}

