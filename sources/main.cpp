/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/15 01:00:25 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <list>
#include <vector>
#include "map.hpp"
#include "vector.hpp"
#include <iterator>

#define TESTED_NAMESPACE std

#define T1 int
#define T2 int

int		main(void)
{
	TESTED_NAMESPACE::map<char, int>::iterator it;
	TESTED_NAMESPACE::map<char, float>::const_iterator ite;

	std::cout << (it != ite) << std::endl;
	return (0);
}
