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

			template <class T2>
			void _swap(T2 &a, T2 &b)
			{
				T2 c = a;
				a = b;
				b = c;
			}

		public:

			//DEFAULT
			explicit vector(const allocator_type  &alloc = allocator_type()):
				_alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
			{
			}

			//FILL
			explicit vector(size_type n, const value_type &value = value_type(), const allocator_type &alloc = allocator_type()): _alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				_array = _alloc.allocate(n);
				_size_alloc = n;
				for (size_type i = 0; i < n; i++)
					push_back(value);
			}

			//COPY
			vector(const vector &x)
			{
				_array = NULL;
				_size = 0;
				_size_alloc = 0;
				_alloc = x._alloc;
				*this = x;
			}

			//RANGE
			template <class InputIt>
			vector(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last, const Allocator &alloc = Allocator()):
					_alloc(alloc), _array(NULL), _size(0), _size_alloc(0)
			{
				_array = _alloc.allocate(std::abs(last - first));
				_size_alloc = std::abs(last - first);
				for ( ; first != last; ++first)
					push_back(*first);
			}

			//DESTRUCTOR
			~vector()
			{
				clear();
				_alloc.deallocate(_array, _size_alloc);
				_size_alloc = 0;
			}

			vector	&operator=(const vector &x)
			{
				clear();
				if (_size_alloc < x.size())
				{
					_alloc.deallocate(_array, _size_alloc);
					_array = _alloc.allocate(x.size());
					_size_alloc = x.size();
				}
				for (size_type i = 0; i < x._size; i++)
					push_back(x[i]);
				return *this;
			}

			template <class InputIt>
			void			assign(InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)
			{
				clear();
				if (static_cast<size_type> (std::abs(last - first)) > _size_alloc)
				{
					_alloc.deallocate(_array, _size_alloc);
					_array = _alloc.allocate(std::abs(last - first));
					_size_alloc = std::abs(last - first);
				}
				for ( ; first != last; ++first)
					push_back(*first);
			}

			void			assign(size_type n, const value_type &val)
			{
				clear();
				if (n > _size_alloc)
				{
					_alloc.deallocate(_array, _size_alloc);
					_array = _alloc.allocate(n);
					_size_alloc = n;
				}
				for (size_type i = 0; i < n; ++i)
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
				return	reverse_iterator(_array - 1);
			}

			const_reverse_iterator	rend() const
			{
				return	const_reverse_iterator(_array - 1);
			}

			//CAPACITY
			size_type		size(void) const
			{
				return	_size;
			}

			size_type		max_size(void) const
			{
				return (_alloc.max_size());
			}

			void			resize(size_type n, value_type val = value_type())
			{
				while (_size < n)
					push_back(val);
				while (_size < n)
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
				{
					_alloc.construct(&new_arr[i], _array[i]);
					_alloc.destroy(&_array[i]);
				}
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
				if (i < 0 || i >= _size_alloc)
				{
					std::stringstream ss;
					ss << "Trying to access index " << i << " in vector of size_alloc " << _size_alloc << std::endl;
					throw std::out_of_range(ss.str());
				}
				return _array[i];
			}

			const_reference	at(size_type i) const
			{
				if (i < 0 || i >= _size_alloc)
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
					reserve((_size_alloc == 0 ? 1 : _size_alloc * 2));
				_alloc.construct(&_array[_size], val);
				_size++;
			}

			void			pop_back()
			{
				_alloc.destroy(&(_array[_size - 1]));
				_size--;
			}

			iterator		insert(iterator position, const value_type &val)
			{
				difference_type diff = position - this->begin();
				this->insert(position, 1, val);
				return (iterator(this->begin() + diff));
			}

			void insert (iterator position, size_type n, const value_type &val)
			{
				if (n < 0)
					return ;
				difference_type diff = position - this->begin();
				if (_size + n > _size_alloc)
				{
					if (_size + n > _size_alloc * 2)
						reserve(_size_alloc * 2);
					else
						reserve(_size + n);
				}
				position = this->begin() + diff;
				for (iterator it = this->end() + n - 1; it != position + n - 1; --it)
				{
					this->_swap(*it, *(it - n));
				}
				while (n-- != 0)
				{
					_alloc.construct(position, val);
					_size++;
					position++;
				}
			}

			template <class InputIt>
			void			insert(iterator position, InputIt first, typename ft::enable_if<!ft::is_integral<InputIt>::value, InputIt>::type last)
			{
				if (std::abs(last - first) < 0)
					return ;
				size_type n = std::abs(last - first);
				difference_type diff = position - this->begin();

				if (_size + n > _size_alloc)
				{
					if (_size + n > _size_alloc * 2)
						reserve(_size_alloc * 2);
					else
						reserve(_size + n);
				}
				position = this->begin() + diff;
				for (iterator it = this->end() + n - 1; it != position + n - 1; --it)
				{
					this->_swap(*it, *(it - n));
				}
				while (n-- != 0)
				{
					_alloc.construct(position, *first);
					_size++;
					position++;
					first++;
				}
			}

			iterator		erase(iterator position)
			{
				iterator it = position;

				_alloc.destroy(position);
				for ( ; position != this->end() - 1; ++position)
					this->_swap(*position, *(position + 1));
				_size--;
				return	it;
			}

			iterator		erase(iterator first, iterator last)
			{
				for (; first != last; --last)
					first = erase(first);
				return last;
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
					for (size_type i = 0; i < _size; _size++)
						_alloc.destroy(&_array[i]);
					_size = 0;
				}
			}
			
			allocator_type get_allocator() const
			{
				return _alloc;
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
		bool operator<(const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		};

		template <class T, class Alloc>
		bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return !(rhs < lhs);
		};

		template <class T, class Alloc>
		bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
		{
			return rhs < lhs;
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
