/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/29 12:36:35 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/24 15:19:13 by jvaquer          ###   ########.fr       */
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
//# include "iterators/iterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include "../Utils/utils.hpp"
# include "../Utils/iterator_traits.hpp"

namespace ft
{
	template <typename T, class Allocator = std::allocator<T> >
	class vector
	{
		public:

			typedef T									value_type;
			typedef Allocator							allocator_type;
			typedef	size_t								size_type;
			typedef	typename std::ptrdiff_t				difference_type;

			typedef typename Allocator::reference		reference;
			typedef typename Allocator::const_reference	const_reference;
			typedef typename Allocator::pointer			pointer;
			
			typedef pointer												iterator;
			typedef const pointer										const_iterator;
			typedef	typename ft::reverse_iterator<iterator>				reverse_iterator;
			typedef typename ft::reverse_iterator<const_iterator>		const_reverse_iterator;

		private:

			allocator_type		_alloc;
			pointer				_array;
			size_type			_size;
			size_type			_size_alloc;

		public:

			//DEFAULT
			explicit vector(const allocator_type  &alloc = allocator_type()):
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
			vector(const vector &x)
			{
				_array = NULL;
				_size = 0;
				_size_alloc = 0;
				_alloc = allocator_type();
				for (size_type i = 0; i < x.capacity(); i++)
					push_back(x[i]);
			}

			//RANGE
			template <class InputIt>
			vector(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last, const Allocator &alloc = Allocator()):
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
				for (const_iterator it = x.begin(); it != x.end(); it++)
					push_back(*it);
				return *this;
			}

			template <class InputIt>
			void			assign(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)
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
				return	reverse_iterator(_array + _size - 1);
			}

			const_reverse_iterator	rbegin() const
			{
				return	const_reverse_iterator(_array + _size - 1);
			}

			reverse_iterator		rend()
			{
				return	reverse_iterator(begin() - 1);
			}

			const_reverse_iterator	rend() const
			{
				return	const_reverse_iterator(begin() - 1);
			}

			//CAPACITY
			size_type		size(void) const
			{
				return	(_size);
			}

			size_type		max_size(void) const
			{
				return (_alloc.max_size());
			}

			void			resize(size_type n, value_type val = value_type())
			{
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
				return	_array[_size - 1];
			}

			const_reference	back() const
			{
				return	_array[_size - 1];
			}

			//MODIFIERS
			void			push_back(const value_type &val)
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
				ft::vector<T>	tmp(position, end());
				for (size_type i = 0; i < tmp.size(); i++)
					pop_back();
				push_back(val);
				iterator it = tmp.begin();
				for (size_type i = 0; i < tmp.size(); i++, it++)
					push_back(*it);
				return	position;
			}

			void			insert(iterator position, size_type n, const value_type &val)
			{
				ft::vector<T>	tmp(position, end());
				for (size_type i = 0; i < tmp.size(); i++)
					pop_back();
				for (size_type i = 0; i < n; i++)
					push_back(val);
				iterator it = tmp.begin();
				for (size_type i = 0; i < tmp.size(); i++, it++)
					push_back(*it);
			}

			template <class InputIt>
			void			insert(iterator position, InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)
			{
				difference_type	pos = position - this->begin();
				size_type		count = 0;

				while (first != last)
				{
					first++;
					count++;
				}
				first -= count;
				if (_size_alloc - _size <= count)
				{
					if (_size == 0)
						reserve(1);
					else
						reserve(_size_alloc * 2);
				}
				
				ft::vector<T>	tmp(begin() + pos, end());
				for (size_type i = 0; i < tmp.size(); i++)
					pop_back();
				while (first != last)
				{
					push_back(*first);
					first++;
				}
				iterator it = tmp.begin();
				for (size_type i = 0; i < tmp.size(); i++, it++)
					push_back(*it);
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
		bool operator== (const vector<T, Alloc> & lhs, const vector<T, Alloc> & rhs)
		{
			if (lhs.size() != rhs.size())
				return false;
			for (typename vector<T, Alloc>::size_type i = 0; i < lhs.size(); i++)
			{
				if (rhs[i] != lhs[i])
					return false;
			}
			return true;
		};

		template <class T, class Alloc>
		bool	operator!=(const vector <T, Alloc> &lhs, const vector<T, Alloc> &rhs)
		{
			return !(lhs == rhs);
		}

		template <class T, class Alloc>
		bool operator< (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			typename vector<T, Alloc>::iterator it1 = lhs.begin(); 
			typename vector<T, Alloc>::iterator ite1 = lhs.end();

			typename vector<T, Alloc>::iterator it2 = rhs.begin();
			typename vector<T, Alloc>::iterator ite2 = rhs.end();

			for(;it1 != ite1; it1++)
			{
				if (it2 == ite2)
					return false;
				if (*it1 != *it2)
					return (*it1 < *it2);
				else
					it2++;
			}
			if (it2 != ite2)
				return true;
			return false;
		};

		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return (lhs < rhs || lhs == rhs);
		};

		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs < rhs || lhs == rhs);
		};


		template <class T, class Alloc>
		bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(lhs < rhs);
		};

		template <class T, class Alloc>
		void		swap(vector<T,Alloc>& x, vector<T,Alloc>& y)
		{
			x.swap(y);
		}
}

#endif
