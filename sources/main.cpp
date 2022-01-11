/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/11 19:44:19 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <map>
#include <list>
#include <vector>
#include "map.hpp"
#include "vector.hpp"

#define NAMESPACE ft
#define TESTED_NAMESPACE NAMESPACE

#define T1 int
#define T2 std::string
typedef TESTED_NAMESPACE::map<T1, T2>::value_type T3;
typedef TESTED_NAMESPACE::map<T1, T2>::iterator iterator;
// typedef NAMESPACE::pair<const T1, T2> T3;

// int main (void)
// {
// 	std::list<T3> lst;
// 	std::map<int, int> yolo;

// 	unsigned int lst_size = 7;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(i, i));
// 	NAMESPACE::map<T1, T2> foo(lst.begin(), lst.end());

// 	lst.clear(); lst_size = 4;
// 	for (unsigned int i = 0; i < lst_size; ++i)
// 		lst.push_back(T3(i, i));
// 	NAMESPACE::map<T1, T2> bar(foo);

// 	NAMESPACE::map<T1, T2>::iterator it_foo = foo.begin();
// 	NAMESPACE::map<T1, T2>::iterator it_bar = bar.begin();

// 	foo.swap(bar);

// 	std::cout << "Iterator validity:" << std::endl;
// 	std::cout << (it_foo == bar.begin()) << std::endl;
// 	std::cout << (it_bar == foo.begin()) << std::endl;
// 	return (0);
// }

int		main(void)
{
	TESTED_NAMESPACE::map<T1, T2>	mp2;

	mp2.insert(mp2.begin(), T3(1337, "beauty"));
	mp2.insert(mp2.end(), T3(1000, "Hello"));
	mp2.insert(mp2.end(), T3(1500, "World"));

	return (0);
}
