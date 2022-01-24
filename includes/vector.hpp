/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:41:16 by lucocozz          #+#    #+#             */
/*   Updated: 2022/01/24 20:43:13 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <memory>
# include <iostream>
# include <sstream>
# include <string>
# include <limits>
# include <stddef.h>
# include "iterator.hpp"
# include "algorithm.hpp"


namespace ft
{
	template<class T>
	class vector_iterator
	{
	public:
		typedef T								value_type;
		typedef std::ptrdiff_t					difference_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;

		pointer			current;

		vector_iterator(): current(NULL) {}

		vector_iterator(pointer ptr): current(ptr) {}

		vector_iterator(const vector_iterator<T> &copy)
		{
			*this = copy;
		}

		~vector_iterator() {}




		vector_iterator<T>	&operator=(const vector_iterator<T> &copy)
		{
			if (this != &copy)
				this->current = copy.current;
			return (*this);
		}

		reference	operator*(void) const
		{
			return (*this->current);
		}

		pointer	operator->(void) const
		{
			return (this->current);
		}

		reference	operator[](int index)
		{
			return (this->current[index]);
		}

		vector_iterator<T>	operator++(int)
		{
			vector_iterator<T>	tmp(*this);
		
			this->current++;
			return (tmp);
		}

		vector_iterator<T>	&operator++(void)
		{
			this->current++;
			return (*this);
		}

		vector_iterator<T>	operator--(int)
		{
			vector_iterator<T>	tmp(*this);
		
			this->current--;
			return (tmp);
		}

		vector_iterator<T>	&operator--(void)
		{
			this->current--;
			return (*this);
		}

		vector_iterator<T>	&operator+=(difference_type value)
		{
			this->current += value;
			return (*this);
		}

		vector_iterator<T>	operator+(difference_type value)
		{
			vector_iterator<T>	tmp(this->current + value);

			return (tmp);
		}

		vector_iterator<T>	&operator-=(difference_type value)
		{
			this->current -= value;
			return (*this);
		}

		vector_iterator<T>	operator-(difference_type value)
		{
			vector_iterator<T>	tmp(this->current - value);
		
			return (tmp);
		}

		difference_type		operator-(const vector_iterator<T> &object) const
		{
			return (this->current - object.current);
		}

		difference_type		operator+(const vector_iterator<T> &object) const
		{
			return (this->current + object.current);
		}

		operator vector_iterator<const T>() const 
		{
			return (vector_iterator<const T>(this->current));
		}
	};

	


	template<class Tx, class Ty>
	bool	operator==(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current == y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator!=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current != y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator>=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current >= y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator<=(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current <= y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator<(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current < y.current)
			return (true);
		return (false);
	}

	template<class Tx, class Ty>
	bool	operator>(const vector_iterator<Tx> &x, const vector_iterator<Ty> &y)
	{
		if (x.current > y.current)
			return (true);
		return (false);
	}

















	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef typename Allocator::reference				reference;
		typedef typename Allocator::const_reference			const_reference;
		typedef typename ft::vector_iterator<T>				iterator;
		typedef typename ft::vector_iterator<const T>		const_iterator;
		typedef size_t										size_type;
		typedef std::ptrdiff_t								difference_type;					
		typedef	T											value_type;
		typedef Allocator									allocator_type;
		typedef typename Allocator::pointer					pointer;
		typedef typename Allocator::const_pointer			const_pointer;
		typedef ft::reverse_iterator<iterator>				reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	private:
		size_type		_capacity;
		size_type		_size;
		pointer			_data;
		allocator_type	_alloc;

	public:
		//* constructor/copy/destructor:
		explicit vector(const Allocator& = Allocator()): _capacity(0), _size(0), _data(NULL) {}

		explicit vector(size_type n, const T &value = T(), const Allocator& = Allocator()):
			_capacity(0), _size(0), _data(NULL)
		{
			this->assign(n, value);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last, const Allocator& = Allocator(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = NULL):
			_capacity(0), _size(0), _data(NULL)
		{
			this->assign(first, last);
		}

		vector(const vector &x):
			_capacity(0), _size(0), _data(NULL)
		{
			*this = x;
		}

		~vector()
		{
			if (this->_data != NULL)
			{
				this->clear();
				this->_alloc.deallocate(this->_data, this->_capacity);
			}
		}

		vector	&operator=(const vector &x)
		{
			if (this != &x)
				this->assign(x.begin(), x.end());
			return (*this);
		}

		template<class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		assign(InputIterator first, InputIterator last)
		{
			this->clear();
			this->insert(this->begin(), first, last);
		}

		void	assign(size_type n, const T &u)
		{
			this->clear();
			this->insert(this->begin(), n, u);
		}

		allocator_type	get_allocator() const
		{
			return (this->_alloc);
		}






		//* iterators:
		iterator	begin()
		{
			return (iterator(this->_data));
		}

		const_iterator	begin() const
		{
			return (const_iterator(this->_data));
		}

		iterator	end()
		{
			return (iterator(&this->_data[this->_size]));
		}

		const_iterator	end() const
		{
			return (const_iterator(&this->_data[this->_size]));
		}

		reverse_iterator	rbegin()
		{
			return (reverse_iterator(&this->_data[this->_size]));
		}

		const_reverse_iterator	rbegin() const
		{
			return (const_reverse_iterator(&this->_data[this->_size]));
		}

		reverse_iterator	rend()
		{
			return (reverse_iterator(this->_data));
		}

		const_reverse_iterator	rend() const
		{
			return (const_reverse_iterator(this->_data));
		}






		//* capacity:
		size_type	size() const
		{
			return	(this->_size);
		}

		size_type	max_size() const
		{
			return (this->_alloc.max_size());
		}

		void	resize(size_type size, T val = T())
		{
			if (size < this->size())
				this->erase(this->begin() + size, this->end());
			else if (size > this->size())
				this->insert(this->end(), size - this->size(), val);
		}

		size_type	capacity() const
		{
			return (this->_capacity);
		}

		bool	empty() const
		{
			if (this->_size == 0)
				return (true);
			return (false);
		}

		void	reserve(size_type n)
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






		//* element access:
		reference	operator[](size_type n)
		{
			return (this->_data[n]);
		}

		const_reference	operator[](size_type n) const
		{
			return (this->_data[n]);
		}

		const_reference	at(size_type n) const
		{
			std::ostringstream ostring;

			if (n < this->size())
				return (this->_data[n]);
			ostring << "vector::at: n (which is " << n << ") >= this->size() (which is " << this->size() << ")";
			throw (std::out_of_range(ostring.str()));
		}

		reference	at(size_type n)
		{
			std::ostringstream ostring;

			if (n < this->size())
				return (this->_data[n]);
			ostring << "vector::at: n (which is " << n << ") >= this->size() (which is " << this->size() << ")";
			throw (std::out_of_range(ostring.str()));
		}

		reference	front()
		{
			return (*this->_data);
		}

		const_reference	front() const
		{
			return (*this->_data);
		}

		reference	back()
		{
			return (this->_data[this->size() - 1]);
		}

		const_reference	back() const
		{
			return (this->_data[this->size() - 1]);
		}






		//* modifiers:
		void	push_back(const T &x)
		{
			this->insert(this->end(), x);
		}

		void	pop_back()
		{
			this->erase(this->end() - 1);
		}

		iterator	insert(iterator position, const T &x)
		{
			difference_type	i = position - this->begin();

			this->insert(position, 1, x);
			return (&this->_data[i]);
		}

		void	insert(iterator position, size_type n, const T &x)
		{
			iterator		pos;
			iterator		oldEnd;
			difference_type	index = position - this->begin();

			this->reserve(this->_newCapacity(this->size() + n));
			oldEnd = this->end();
			this->_size += n;
			pos = iterator(&this->_data[index]);
			if (pos != oldEnd)
				for (int i = 0; this->end() - i != pos; i++)
					this->_alloc.construct(&(*(this->end() - i - 1)), *(oldEnd - i - 1));
			for (size_type i = 0; i < n; i++, pos++)
				this->_alloc.construct(pos.current, x);
		}

		template<class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		insert(iterator position, InputIterator first, InputIterator last)
		{
			iterator		pos;
			iterator		oldEnd;
			difference_type	index = position - this->begin();
			difference_type	size = ft::distance(first, last);
		
			this->reserve(this->_newCapacity(this->size() + size));
			oldEnd = this->end();
			this->_size = this->size() + size;
			pos = iterator(&this->_data[index]);
			if (pos != oldEnd)
				for (int i = 0; this->end() - i != pos; i++)
					this->_alloc.construct(&(*(this->end() - i - 1)), *(oldEnd - i - 1));
			for (; first != last; first++, pos++)
				this->_alloc.construct(pos.current, *first);
		}

		iterator	erase(iterator position)
		{
			return (this->erase(position, position + 1));
		}

		iterator	erase(iterator first, iterator last)
		{
			iterator		it = first;
			size_type		size = this->_size;

			if (first != last)
			{
				for (; last != this->end(); last++, it++)
					this->_alloc.construct(it.current, *last);
				for (; it != this->end(); it++, size--)
					this->_alloc.destroy(it.current);
				this->_size = size;
			}
			return (first);
		}

		void	swap(vector &x)
		{
			std::swap(this->_capacity, x._capacity);
			std::swap(this->_data, x._data);
			std::swap(this->_size, x._size);
		}

		void	clear()
		{
			erase(this->begin(), this->end());
		}






	private:

		size_type	_newCapacity(size_type n)
		{
			size_type	newCapacity;

			newCapacity = this->capacity();
			while (n >= newCapacity)
			{
				if (newCapacity == 0)
					newCapacity = 1;
				else
					newCapacity *= 2;
			}
			return (newCapacity);
		}
	};






	//* operator:
	template<class T, class Alloc>
	bool operator==(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		if (lhs.size() != rhs.size())
			return (false);
		return (ft::equal(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool operator!=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (!(lhs == rhs));
	}

	template<class T, class Alloc>
	bool operator<(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	}

	template<class T, class Alloc>
	bool operator<=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (lhs == rhs || lhs < rhs);
	}

	template<class T, class Alloc>
	bool operator>(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (rhs < lhs);
	}

	template<class T, class Alloc>
	bool operator>=(const ft::vector<T, Alloc> &lhs, const ft::vector<T, Alloc> &rhs)
	{
		return (lhs == rhs || rhs < lhs);
	}



	//* specialized algorithms:
	template<class T>
	void	swap(vector<T> &x, vector<T> &y)
	{
		x.swap(y);
	}

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
