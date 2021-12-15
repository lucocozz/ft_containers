/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectorIterator.ipp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 20:05:00 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/10 21:47:10 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


template<class T>
ft::vector_iterator<T>::vector_iterator(): current(NULL) {}

template<class T>
ft::vector_iterator<T>::vector_iterator(T *ptr): current(ptr) {}

template<class T>
ft::vector_iterator<T>::vector_iterator(const vector_iterator<T> &copy)
{
	*this = copy;
}

template<class T>
ft::vector_iterator<T>::~vector_iterator() {}

template<class T>
ft::vector_iterator<T>	&ft::vector_iterator<T>::operator=(const vector_iterator<T> &copy)
{
	if (this != &copy)
		this->current = copy.current;
	return (*this);
}

template<class T>
T	&ft::vector_iterator<T>::operator*(void) const
{
	return (*this->current);
}

template<class T>
T	*ft::vector_iterator<T>::operator->(void) const
{
	return (this->current);
}

template<class T>
T	&ft::vector_iterator<T>::operator[](int index)
{
	return (this->current[index]);
}

template<class T>
ft::vector_iterator<T>	ft::vector_iterator<T>::operator++(int)
{
	ft::vector_iterator<T>	tmp(*this);

	this->current++;
	return (tmp);
}

template<class T>
ft::vector_iterator<T>	&ft::vector_iterator<T>::operator++(void)
{
	this->current++;
	return (*this);
}

template<class T>
ft::vector_iterator<T>	ft::vector_iterator<T>::operator--(int)
{
	ft::vector_iterator<T>	tmp(*this);

	this->current--;
	return (tmp);
}

template<class T>
ft::vector_iterator<T>	&ft::vector_iterator<T>::operator--(void)
{
	this->current--;
	return (*this);
}

template<class T>
ft::vector_iterator<T>	&ft::vector_iterator<T>::operator+=(int value)
{
	this->current += value;
	return (*this);
}

template<class T>
ft::vector_iterator<T>	ft::vector_iterator<T>::operator+(int value)
{
	ft::vector_iterator<T>	tmp(this->current + value);

	return (tmp);
}

template<class T>
ft::vector_iterator<T>	&ft::vector_iterator<T>::operator-=(int value)
{
	this->current -= value;
	return (*this);
}

template<class T>
ft::vector_iterator<T>	ft::vector_iterator<T>::operator-(int value)
{
	ft::vector_iterator<T>	tmp(this->current - value);

	return (tmp);
}

template<class T>
ptrdiff_t		ft::vector_iterator<T>::operator-(const vector_iterator<T> &object) const
{
	return (this->current - object.current);
}





template<class Tx, class Ty>
bool	ft::operator==(const ft::vector_iterator<Tx> &x, const ft::vector_iterator<Ty> &y)
{
	if (x.current == y.current)
		return (true);
	return (false);
}

template<class Tx, class Ty>
bool	ft::operator!=(const ft::vector_iterator<Tx> &x, const ft::vector_iterator<Ty> &y)
{
	if (x.current != y.current)
		return (true);
	return (false);
}

template<class Tx, class Ty>
bool	ft::operator>=(const ft::vector_iterator<Tx> &x, const ft::vector_iterator<Ty> &y)
{
	if (x.current >= y.current)
		return (true);
	return (false);
}

template<class Tx, class Ty>
bool	ft::operator<=(const ft::vector_iterator<Tx> &x, const ft::vector_iterator<Ty> &y)
{
	if (x.current <= y.current)
		return (true);
	return (false);
}

template<class Tx, class Ty>
bool	ft::operator<(const ft::vector_iterator<Tx> &x, const ft::vector_iterator<Ty> &y)
{
	if (x.current < y.current)
		return (true);
	return (false);
}

template<class Tx, class Ty>
bool	ft::operator>(const ft::vector_iterator<Tx> &x, const ft::vector_iterator<Ty> &y)
{
	if (x.current > y.current)
		return (true);
	return (false);
}



template<class T>
ft::vector_iterator<T>	operator+(int value, const ft::vector_iterator<T> &object)
{
	return (object.current + value);	
}

template<class T>
ft::vector_iterator<T>	operator-(int value, const ft::vector_iterator<T> &object)
{
	return (object.current - value);	
}
