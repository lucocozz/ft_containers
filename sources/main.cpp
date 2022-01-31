/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/19 17:49:36 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/26 16:38:51 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stack>
#include <vector>
#include <map>
#include "stack.hpp"
#include "map.hpp"
#include "vector.hpp"
#include <iterator>

#define TESTED_TYPE int

int	main()
{
	std::vector<TESTED_TYPE> vct;
	std::map<TESTED_TYPE, TESTED_TYPE> mp;

	vct.push_back(1);
	vct.push_back(2);
	vct.push_back(3);
	mp.insert(vct.begin(), vct.end());
	return (0);
}
