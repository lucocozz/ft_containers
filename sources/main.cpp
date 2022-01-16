/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:27:42 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/16 18:44:18 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
#include "vector.hpp"
#include "map.hpp"
#include <list>

#define TESTED_NAMESPACE ft

#define T1 int
#define T2 std::string
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
	std::list<T3> lst;
	unsigned int lst_size = 10;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, std::string((lst_size - i), i + 65)));
	TESTED_NAMESPACE::map<T1, T2> mp(lst.begin(), lst.end());

	mp.erase(++mp.begin());

	mp.erase(mp.begin());
	mp.erase(--mp.end());

	mp.erase(mp.begin(), ++(++(++mp.begin())));
	mp.erase(--(--(--mp.end())), --mp.end());
	printMap(mp);

	mp[10] = "Hello";
	mp[11] = "Hi there";
	mp.erase(--(--(--mp.end())), mp.end());

	mp[12] = "ONE";
	mp[13] = "TWO";
	mp[14] = "THREE";
	mp[15] = "FOUR";
	mp.erase(mp.begin(), mp.end());
	return (0);
}
