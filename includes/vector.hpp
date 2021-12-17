/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucocozz <lucocozz@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 15:41:16 by lucocozz          #+#    #+#             */
/*   Updated: 2021/12/17 18:30:49 by lucocozz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <memory>
# include <iostream>
# include <sstream>
# include <string>
# include <limits>
# include <stddef.h>
# include "reverseIterator.hpp"
# include "vectorIterator.hpp"
# include "type_traits.hpp"

namespace ft
{
	template<class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef typename Allocator::reference				reference;
		typedef typename Allocator::const_reference			const_reference;
		typedef typename ft::vector_iterator<T>				iterator;
		typedef typename ft::vector_iterator<const T>		const_iterator;
		typedef size_t										size_type;
		typedef ptrdiff_t									difference_type;					
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
		//* constructor/copy/destructor
		explicit vector(const Allocator& = Allocator()): _capacity(0), _size(0), _data(NULL) {}

		explicit vector(size_type n, const T &value = T(), const Allocator& = Allocator()): _capacity(0), _size(0), _data(NULL)
		{
			this->assign(n, value);
		}

		template<class InputIterator>
		vector(InputIterator first, InputIterator last, const Allocator& = Allocator(),
		typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = NULL): _capacity(0), _size(0), _data(NULL)
		{
			this->assign(first, last);
		}

		vector(const vector<T> &x): _capacity(0), _size(0), _data(NULL)
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

		vector<T>	&operator=(const vector<T> &x)
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






		//* iterators
		iterator	begin()
		{
			return (this->_data);
		}

		const_iterator	begin() const
		{
			return (this->_data);
		}

		iterator	end()
		{
			return (&this->_data[this->_size]);
		}

		const_iterator	end() const
		{
			return (&this->_data[this->_size]);
		}

		reverse_iterator	rbegin()
		{
			return (&this->_data[this->_size]);
		}

		const_reverse_iterator	rbegin() const
		{
			return (&this->_data[this->_size]);
		}

		reverse_iterator	rend()
		{
			return (this->_data);
		}

		const_reverse_iterator	rend() const
		{
			return (this->_data);
		}






		//* capacity
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






		//* element access
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






		//* modifiers
		void	push_back(const T &x)
		{
			if (this->size() == this->capacity())
				this->reserve(this->capacity() * 2);
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

		template<class InputIterator>
		typename ft::enable_if<!ft::is_integral<InputIterator>::value, void>::type
		insert(iterator position, InputIterator first, InputIterator last)
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
					this->_alloc.construct(&(*it), *last);
				for (; it != this->end(); it++, size--)
					this->_alloc.destroy(&(*it));
				this->_size = size;
			}
			return (first);
		}

		void	swap(vector<T> &x)
		{
			std::swap(this->_capacity, x._capacity);
			std::swap(this->_data, x._data);
			std::swap(this->_size, x._size);
		}

		void	clear()
		{
			erase(this->begin(), this->end());
		}
		
		bool	operator==(const vector<T> &object) const
		{
			(void)object;
			return (true);
		}
	};






	//* operator
	template<class T>
	bool	operator!=(const vector<T> &x, const vector<T> &y)
	{
		(void)(x && y);
		return (true);
	}

	template<class T>
	bool	operator<(const vector<T> &x, const vector<T> &y)
	{
		(void)(x && y);
		return (true);
	}

	template<class T>
	bool	operator>(const vector<T> &x, const vector<T> &y)
	{
		(void)(x && y);
		return (true);
	}

	template<class T>
	bool	operator<=(const vector<T> &x, const vector<T> &y)
	{
		(void)(x && y);
		return (true);
	}

	template<class T>
	bool	operator>=(const vector<T> &x, const vector<T> &y)
	{
		(void)(x && y);
		return (true);
	}




	//* specialized algorithms
	template<class T>
	void	swap(vector<T> &x, vector<T> &y)
	{
		x.swap(y);
	}

}
