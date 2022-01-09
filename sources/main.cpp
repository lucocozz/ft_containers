/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/09 17:46:22 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <list>
#include <vector>
#include "map.hpp"
#include "vector.hpp"

#define NAMESPACE std

template <typename T>
void	printPair(const T &iterator)
{
	std::cout << "key: " << iterator->first << " | value: " << iterator->second;
}

template <typename T_MAP>
void	printSize(T_MAP const &mp)
{
	std::cout << "size: " << mp.size() << std::endl;
	std::cout << "max_size: " << mp.max_size() << std::endl;
	typename T_MAP::const_iterator it = mp.begin(), ite = mp.end();
	std::cout << std::endl << "Content is:" << std::endl;
	for (; it != ite; ++it)
	{
		std::cout << "- ";
		printPair(it);
		std::cout << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

void	ft_comp(const NAMESPACE::map<char, float> &mp, const NAMESPACE::map<char, float>::const_iterator &it1, const NAMESPACE::map<char, float>::const_iterator &it2)
{
	bool res[2];
	static unsigned int i = 0;


	std::cout << "\t-- [" << ++i << "] --" << std::endl;
	res[0] = mp.key_comp()(it1->first, it2->first);
	res[1] = mp.value_comp()(*it1, *it2);
	std::cout << "with [" << it1->first << " and " << it2->first << "]: ";
	std::cout << "key_comp: " << res[0] << " | " << "value_comp: " << res[1] << std::endl;
}

int	main()
{
	NAMESPACE::map<char, float>	mp;

	mp['a'] = 2.3;
	mp['b'] = 1.4;
	mp['c'] = 0.3;
	mp['d'] = 4.2;

	printSize(mp);
	for (NAMESPACE::map<char, float>::const_iterator it1 = mp.begin(); it1 != mp.end(); ++it1)
		for (NAMESPACE::map<char, float>::const_iterator it2 = mp.begin(); it2 != mp.end(); ++it2)
			ft_comp(mp, it1, it2);
	printSize(mp);
	return (0);
}
