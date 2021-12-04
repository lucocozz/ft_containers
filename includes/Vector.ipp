/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.ipp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:41:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/04 21:11:11 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

template<class T, class Allocator>
ft::Vector<T>::Vector()
{
}

ft::Vector<T>::Vector(const Vector &copy)
{
	*this = copy;
}

ft::Vector<T>::~Vector()
{
}

ft::Vector<T>	&ft::Vector::operator=(const Vector &object)
{
	return (*this);
}
