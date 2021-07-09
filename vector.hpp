/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:36:35 by jvaquer           #+#    #+#             */
/*   Updated: 2021/06/24 14:04:23 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <cstddef>
# include <cstdlib>
# include <memory>
# include <limits>
# include <iostream>
# include <sstream>
# include "includes/Iterator.hpp"
# include "includes/ReverseIterator.hpp"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

			typedef T									value_type;
			typedef Allocator							allocator_type;
			typedef	typename std::size_t				size_type;
			typedef	typename std::ptrdiff_t				difference_type;

			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer			pointer;
			
			typedef Iterator<value_type>				iterator;
			typedef const Iterator<value_type>			const_iterator;
			typedef	ReverseIterator<value_type>			reverse_iterator;
			typedef const ReverseIterator<value_type>	const_reverse_iterator;

		private:

			allocator_type		_alloc;
			pointer				_array;
			size_type			_size;
			size_type			_size_alloc;

		public:

			//DEFAULT
			explicit vector(const Allocator  &alloc = Allocator()):
				_alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
			{
			}

			//FILL
			explicit vector(size_type n, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()): _alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				this->reserve(n);
				for (size_type i = 0; i < n; i++)
					push_back(value);
				_size_alloc = n;
			}

			//COPY
			vector(const vector &x): _alloc(x._alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				*this = x;
			}

			//RANGE
			template <class InputIt>
			vector(InputIt first, InputIt last, const Allocator &alloc = Allocator(), typename InputIt::difference_type * = nullptr):
					_alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				while (first != last)
				{
					this->push_back(*first);
					first++;
				}
			}

			//DESTRUCTOR
			~vector()
			{
				clear();
				if (_size_alloc > 0)
					_alloc.deallocate(_array, _size_alloc);
				_size_alloc = 0;
			}

			vector	&operator=(vector &x)
			{
				clear();
				for (iterator it = x.begin(); it != x.end(); it++)
					push_back(*it);
				return *this;
			}

			vector	&operator=(const vector &x)
			{
				clear();
				for (iterator it = x.begin(); it != x.end(); it++)
					push_back(*it);
				return *this;
			}

			template <class InputIt>
			void			assign(InputIt first, InputIt last, typename InputIt::difference_type * = nullptr)
			{
				clear();
				for (iterator it = first; it != last; it++)
					push_back(*it);
			}

			void			assign(size_type n, const value_type &val)
			{
				clear();
				for (size_type i = 0; i < n; i++)
					push_back(val);
			}


			//ITERATORS
			iterator				begin()
			{
				return	iterator(_array);
			}

			const_iterator			begin() const
			{
				return	const_iterator(_array);
			}

			iterator				end()
			{
				return	iterator(_array + _size);
			}

			const_iterator			end() const
			{
				return	const_iterator(_array + _size);
			}

			reverse_iterator		rbegin()
			{
				return	reverse_iterator(_array + _size);
			}

			const_reverse_iterator	rbegin() const
			{
				return	const_reverse_iterator(_array + _size);
			}

			reverse_iterator		rend()
			{
				return	reverse_iterator(_array);
			}

			const_reverse_iterator	rend() const
			{
				return	const_reverse_iterator(_array);
			}

			//CAPACITY
			size_type		size(void) const
			{
				return	(_size);
			}

			size_type		max_size(void) const
			{
				return (std::numeric_limits<size_type>::max());
			}

			void			resize(size_type n, value_type val = value_type())
			{
				std::cout << "val = " << val << std::endl;
				if (n > _size)
					for (size_type i = n - _size; i > 0; i--)
						push_back(val);
				else if (n < _size)
					for (size_type i = _size - n; i > 0; i--)
						pop_back();
				_size = n;
			}

			size_type		capacity() const
			{
				return	_size_alloc;
			}

			bool			empty() const
			{
				return	_size == 0 ? true : false;
			}

			void			reserve(size_type n)
			{
				pointer		new_arr;

				if (n <= _size_alloc)
					return	;
				new_arr = _alloc.allocate(n);
				for (size_type i = 0; i < size(); i++)
					_alloc.construct(&new_arr[i], _array[i]);
				_alloc.destroy(_array);
				_alloc.deallocate(_array, _size_alloc);
				_size_alloc = n;
				_array = new_arr;
			}

			//ELEMENT ACCESS
			reference		operator[] (size_type i)
			{
				return	_array[i];
			}

			const_reference	operator[] (size_type i) const
			{
				return	_array[i];
			}


			reference		at(size_type i)
			{
				if (i >= _size_alloc)
				{
					std::stringstream ss;
					ss << "Trying to access index " << i << " in vector of size_alloc " << _size_alloc << std::endl;
					throw std::out_of_range(ss.str());
				}
				return _array[i];
			}

			const_reference	at(size_type i) const
			{
				if (i >= _size_alloc)
				{
					std::stringstream ss;
					ss << "Trying to access index " << i << " in vector of size_alloc " << _size_alloc << std::endl;
					throw std::out_of_range(ss.str());
				}
				return _array[i];
			}

			reference		front()
			{
				return	_array[0];
			}

			const_reference	front() const
			{
				return	_array[0];
			}

			reference		back()
			{
				return	_array[_size];
			}

			const_reference	back() const
			{
				return	_array[_size];
			}

			//MODIFIERS
			void			push_back(const_reference val)
			{
				if (_size == _size_alloc)
					reserve((_size_alloc == 0 ? 1 : _size_alloc) * 2);
				_alloc.construct(&_array[_size], val);
				_size++;
			}

			void			pop_back()
			{
				_alloc.destroy(&back());
				_size--;
			}

			iterator		insert(iterator position, const value_type &val)
			{
				push_back(*end());
				for (iterator it = end() - 1; it != position - 1; it--)
					*(it + 1) = *it;
				*position = val;
				return	position;
			}

			void			insert(iterator position, size_type n, const value_type &val)
			{
				for (size_type i = 0; i < n; i++)
					insert(position, val);
			}

			template <class InputIt>
			void			insert(iterator position, InputIt first, InputIt last)
			{
				for (InputIt it = last - 1; it != first; it--)
					insert(position, *it);
				insert(position, *first);
			}

			iterator		erase(iterator position)
			{
				for (iterator it = position; it + 1 != end(); it++)
					*it = *(it + 1);
				_size -= 1;
				return	position;
			}

			iterator		erase(iterator first, iterator last)
			{
				iterator f = first;
				iterator l = last;
				size_type n = 0;

				for (iterator it = first; it != last; it++)
					n++;
				for (iterator e = end(); f != e && l != e; f++, l++)
					*f = *l;
				_size -= n;
				return l;
			}

			void			swap(vector &x)
			{
				std::swap(x._array, this->_array);
				std::swap(x._size, this->_size);
				std::swap(x._size_alloc, this->_size_alloc);
			}

			void			clear()
			{
				if (_size > 0)
				{
					for (iterator it = this->begin(); it != this->end(); it++)
						_alloc.destroy(&(*it));
					_size = 0;
				}
			}
			
		};
		
		template <class T, class Alloc>
		bool	operator==(const vector<T, Alloc>& lhs, const vector<T, Alloc>& rhs)
		{
			if (lhs.size() != rhs.size())
				return	false;
			for (typename ft::vector<T>::iterator l = lhs.begin(), r = rhs.begin(); l != lhs.end(); l++, r++)
				if (*l != *r)
					return	false;
			return	true;
		}

		template <class T, class Alloc>
		bool	operator!=(const vector <T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return !(lhs == rhs);
		}

		template <class T, class Alloc>
		bool	operator>(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			if (lhs == rhs)
				return	false;
			for (typename ft::vector<T>::iterator l = lhs.begin(), r = rhs.begin(); l != lhs.end(); l++, r++)
				if (*l < *r)
					return	false;
			return	true;
		}

		template <class T, class Alloc>
		bool	operator<(const vector<T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return (rhs > lhs);
		}

		template <class T, class Alloc>
		bool		operator<=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(rhs < lhs));
		}

		template <class T, class Alloc>
		bool		operator>=(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (!(lhs < rhs));
		}

		template <class T, class Alloc>
		void		swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
}

#endif