/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.ipp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:41:46 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/17 01:14:58 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//* constructor/copy/destructor
template<class T, class Allocator>
ft::vector<T, Allocator>::vector(const Allocator&): _capacity(0), _size(0), _data(NULL) {}

template<class T, class Allocator>
ft::vector<T, Allocator>::vector(size_type n, const T &value, const Allocator&): _capacity(0), _size(0), _data(NULL)
{
	this->assign(n, value);
}

template<class T, class Allocator>
template<class InputIterator>
ft::enable_if<!std::is_integral<InputIterator>, void>::type ft::vector<T, Allocator>::vector(InputIterator first, InputIterator last, const Allocator&): _capacity(0), _size(0), _data(NULL)
{
	this->assign(first, last);
}

template<class T, class Allocator>
ft::vector<T, Allocator>::vector(const ft::vector<T, Allocator> &x)
{
	*this = x;
}

template<class T, class Allocator>
ft::vector<T, Allocator>::~vector()
{
	if (this->_data != NULL)
	{
		this->clear();
		this->_alloc.deallocate(this->_data, this->_capacity);
	}
}

template<class T, class Allocator>
ft::vector<T, Allocator>	&ft::vector<T, Allocator>::operator=(const ft::vector<T, Allocator> &x)
{
	if (this != &x)
		this->assign(x.begin(), x.end());
	return (*this);
}

template<class T, class Allocator>
template<class InputIterator>
ft::enable_if<!std::is_integral<InputIterator>, void>::type	ft::vector<T, Allocator>::assign(InputIterator first, InputIterator last)
{
	this->clear();
	this->insert(this->begin(), first, last);
}

template<class T, class Allocator>
void	ft::vector<T, Allocator>::assign(size_type n, const T &u)
{
	this->clear();
	this->insert(this->begin(), n, u);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::allocator_type	ft::vector<T, Allocator>::get_allocator() const
{
	return (this->_alloc);
}






//* iterators
template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::begin()
{
	return (this->_data);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::begin() const
{
	return (this->_data);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::end()
{
	return (&this->_data[this->_size]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_iterator	ft::vector<T, Allocator>::end() const
{
	return (&this->_data[this->_size]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator	ft::vector<T, Allocator>::rbegin()
{
	return (&this->_data[this->_size]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rbegin() const
{
	return (&this->_data[this->_size]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reverse_iterator	ft::vector<T, Allocator>::rend()
{
	return (this->_data);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reverse_iterator	ft::vector<T, Allocator>::rend() const
{
	return (this->_data);
}






//* capacity
template<class T, class Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::size() const
{
	return	(this->_size);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::max_size() const
{
	return (this->_alloc.max_size());
}

template<class T, class Allocator>
void	ft::vector<T, Allocator>::resize(size_type size, T val)
{
	if (size < this->size())
		this->erase(this->begin() + size, this->end());
	else if (size > this->size())
		this->insert(this->end(), size - this->size(), val);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::size_type	ft::vector<T, Allocator>::capacity() const
{
	return (this->_capacity);
}

template<class T, class Allocator>
bool	ft::vector<T, Allocator>::empty() const
{
	if (this->_size == 0)
		return (true);
	return (false);
}

template<class T, class Allocator>
void	ft::vector<T, Allocator>::reserve(size_type n)
{
	pointer		data = NULL;

	if (n > this->max_size())
		throw (std::length_error("vector::reserve"));
	if (n > this->capacity())
	{
		data = this->_alloc.allocate(n);
		if (this->_data != NULL)
		{
			for (size_type i = 0; i < this->size(); i++)
				this->_alloc.construct(&data[i], this->_data[i]);
			this->_alloc.deallocate(this->_data, this->capacity());
		}
		this->_capacity = n;
		this->_data = data;
	}
}






//* element access
template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::operator[](size_type n)
{
	return (this->_data[n]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::operator[](size_type n) const
{
	return (this->_data[n]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::at(size_type n) const
{
	return (this->_data[n]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::at(size_type n)
{
	return (this->_data[n]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::front()
{
	return (*this->_data);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::front() const
{
	return (*this->_data);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::reference	ft::vector<T, Allocator>::back()
{
	return (this->_data[this->size() - 1]);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::const_reference	ft::vector<T, Allocator>::back() const
{
	return (this->_data[this->size() - 1]);
}






//* modifiers
template<class T, class Allocator>
void	ft::vector<T, Allocator>::push_back(const T &x)
{
	if (this->size() == this->capacity())
		this->reserve(this->capacity() * 2);
	this->insert(this->end(), x);
}

template<class T, class Allocator>
void	ft::vector<T, Allocator>::pop_back()
{
	this->erase(this->end() - 1);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::insert(iterator position, const T &x)
{
	difference_type	i = position - this->begin();

	this->insert(position, 1, x);
	return (&this->_data[i]);
}

template<class T, class Allocator>
void	ft::vector<T, Allocator>::insert(iterator position, size_type n, const T &x)
{
	iterator		pos;
	iterator		oldEnd;
	difference_type	index = position - this->begin();

	this->reserve(this->size() + n);
	oldEnd = this->end();
	this->_size += n;
	pos = iterator(&this->_data[index]);
	if (pos != oldEnd)
		for (int i = 0; this->end() - i != pos; i++)
			this->_alloc.construct(&(*(this->end() - i - 1)), *(oldEnd - i - 1));
	for (size_type i = 0; i < n; i++, pos++)
		this->_alloc.construct(&(*pos), x);
}

template<class T, class Allocator>
template<class InputIterator>
ft::enable_if<!std::is_integral<InputIterator>, void>::type	ft::vector<T, Allocator>::insert(iterator position, InputIterator first, InputIterator last)
{
	iterator		pos;
	iterator		oldEnd;
	difference_type	index = position - this->begin();

	this->reserve(this->size() + (last - first));
	oldEnd = this->end();
	this->_size = this->size() + (last - first);
	pos = iterator(&this->_data[index]);
	if (pos != oldEnd)
		for (int i = 0; this->end() - i != pos; i++)
			this->_alloc.construct(&(*(this->end() - i - 1)), *(oldEnd - i - 1));
	for (; first < last; first++, pos++)
		this->_alloc.construct(&(*pos), *first);
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::erase(iterator position)
{
	return (this->erase(position, position + 1));
}

template<class T, class Allocator>
typename ft::vector<T, Allocator>::iterator	ft::vector<T, Allocator>::erase(iterator first, iterator last)
{
	iterator	it = first;
	size_type	size = this->_size;

	if (first != last)
	{
		for (; last != this->end(); last++, it++)
			this->_alloc.construct(&(*it), *last);
		for (; it != this->end(); it++, size--)
			this->_alloc.destroy(&(*it));
		this->_size = size;
	}
	return (first);
}

template<class T, class Allocator>
void	ft::vector<T, Allocator>::swap(vector<T, Allocator> &x)
{
	std::swap(this->_capacity, x._capacity);
	std::swap(this->_data, x._data);
	std::swap(this->_size, x._size);
}

template<class T, class Allocator>
void	ft::vector<T, Allocator>::clear()
{
	erase(this->begin(), this->end());
}







//* operator
template<class T, class Allocator>
bool	ft::vector<T, Allocator>::operator==(const vector<T, Allocator> &object) const
{
	if (this == &object)
		return (true);
	return (false);
}

template<class T, class Allocator>
bool	ft::operator!=(const ft::vector<T, Allocator> &x, const ft::vector<T, Allocator> &y)
{
	(void)(x && y);
	return (true);
}

template<class T, class Allocator>
bool	ft::operator<(const ft::vector<T, Allocator> &x, const ft::vector<T, Allocator> &y)
{
	(void)(x && y);
	return (true);
}

template<class T, class Allocator>
bool	ft::operator>(const ft::vector<T, Allocator> &x, const ft::vector<T, Allocator> &y)
{
	(void)(x && y);
	return (true);
}

template<class T, class Allocator>
bool	ft::operator<=(const ft::vector<T, Allocator> &x, const ft::vector<T, Allocator> &y)
{
	(void)(x && y);
	return (true);
}

template<class T, class Allocator>
bool	ft::operator>=(const ft::vector<T, Allocator> &x, const ft::vector<T, Allocator> &y)
{
	(void)(x && y);
	return (true);
}





//* specialized algorithms
template<class T, class Allocator>
void	ft::swap(ft::vector<T, Allocator> &x, ft::vector<T, Allocator> &y)
{
	x.swap(y);
}
