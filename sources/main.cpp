/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:10:48 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/15 21:00:38 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"
#include <vector>
#include <algorithm>

int	main()
{
	std::cout << "FT:" << std::endl;
	{
		ft::vector<int> vct(5);
		ft::vector<int> vct2;
		const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = i;

		vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);

		vct2.insert(vct2.end(), 42);

		ft::vector<int>::iterator	it = vct2.begin();
		ft::vector<int>::iterator	ite = vct2.end();

		std::cout << "before: ";
		for (; it != ite; it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		vct2.insert(vct2.begin() + 5, 84);

		it = vct2.begin();
		ite = vct2.end();

		std::cout << "after:  ";
		for (; it != ite; it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	std::cout << "\nSTD:" << std::endl;
	{
		std::vector<int> vct(5);
		std::vector<int> vct2;
		const int cut = 3;

		for (unsigned long int i = 0; i < vct.size(); ++i)
			vct[i] = i;

		vct2.insert(vct2.begin(), vct.begin(), vct.begin() + cut);
		vct2.insert(vct2.begin(), vct.begin() + cut, vct.end());
		vct2.insert(vct2.end(), vct.begin(), vct.begin() + cut);

		vct2.insert(vct2.end(), 42);

		std::vector<int>::iterator	it = vct2.begin();
		std::vector<int>::iterator	ite = vct2.end();

		std::cout << "before: ";
		for (; it != ite; it++)
			std::cout << *it << " ";
		std::cout << std::endl;

		vct2.insert(vct2.begin() + 5, 84);

		it = vct2.begin();
		ite = vct2.end();

		std::cout << "after:  ";
		for (; it != ite; it++)
			std::cout << *it << " ";
		std::cout << std::endl;
	}
	return (0);
}