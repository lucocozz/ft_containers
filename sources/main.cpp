/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:27:42 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/18 22:50:09 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vector>
#include <map>
#include "vector.hpp"
#include "map.hpp"
#include <list>

#define TESTED_NAMESPACE ft

#define T1 int
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
	std::list<T3> lst;

	unsigned int lst_size = 7;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i, i));
	TESTED_NAMESPACE::map<T1, T2> foo(lst.begin(), lst.end());

	lst.clear(); lst_size = 4;
	for (unsigned int i = 0; i < lst_size; ++i)
		lst.push_back(T3(i + 1, i + 1));
	TESTED_NAMESPACE::map<T1, T2> bar(lst.begin(), lst.end());

	TESTED_NAMESPACE::map<T1, T2>::const_iterator it_foo = foo.begin();
	TESTED_NAMESPACE::map<T1, T2>::const_iterator it_bar = bar.begin();

	foo.swap(bar);

	std::cout << "Iterator validity:" << std::endl;
	std::cout << (it_foo == bar.begin()) << std::endl;
	std::cout << (it_bar == foo.begin()) << std::endl;
	return (0);
}
