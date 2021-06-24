/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:44:01 by jvaquer           #+#    #+#             */
/*   Updated: 2021/06/25 01:27:34 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <iostream>
# include <sstream>
# include <limits>

namespace ft
{
	template <typename T>
	class iterator
	{
		public:

			typedef std::random_access_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T								&reference;
			typedef const T							&const_reference;
			typedef T								*pointer;
			typedef ptrdiff_t						difference_type;
			typedef size_t							size_type;

		private:

			pointer									_ptr;

		public:

			iterator ()
			{
			}

			iterator(pointer other): _ptr(other)
			{
			}

			iterator(iterator *it)
			{
				_ptr = it->ptr;
			}

			~iterator()
			{
			}

			reference	operator=(iterator const &it)
			{
				_ptr = it._ptr;
				return	*this;
			}

			//INCREMENTS - DECREMENTS
			iterator		operator++()
			{
				++_ptr;
				return	*this;
			}

			iterator		operator++(int)
			{
				++_ptr;
				return	iterator(_ptr - 1);
			}

			iterator		operator+=(size_type nb)
			{
				_ptr += nb;
				return	*this;
			}

			iterator		operator--()
			{
				--_ptr;
				return	*this;
			}

			iterator		operator--(int)
			{		
				--_ptr;
				return	iterator(_ptr + 1);
			};

			iterator		operator-=(size_type nb)
			{
				_ptr -= nb;
				return	*this;
			}

			//ARITHMETICS
			iterator		operator+(difference_type x)
			{
				return	_ptr + x;
			}

			iterator		operator-(difference_type x)
			{
				return	_ptr - x;
			}

			iterator		operator+(iterator &other)
			{
				return _ptr - other.ptr;
			}

			iterator		operator-(iterator &other)
			{
				return 	_ptr - other._ptr;
			}

			//BINARY OPS
			bool		operator==(iterator const &it)
			{
				return	_ptr == it._ptr;
			}

			bool		operator!=(iterator const &it)
			{
				return	_ptr != it._ptr;
			}

			bool		operator>=(iterator const &it)
			{
				return	_ptr >= it._ptr;
			}

			bool		operator>(iterator const &it)
			{
				return	_ptr > it._ptr;
			}

			bool		operator<=(iterator const &it)
			{
				return	_ptr <= it._ptr;
			}

			bool		operator<(iterator const &it)
			{
				return	_ptr < it._ptr;
			}

			//DIFF & ADDRESS
			reference		operator*()
			{
				return	*_ptr;
			}

			const_reference	operator*()	const
			{
				return	*_ptr;
			}

			pointer			operator->()
			{
				return	_ptr;
			}

			reference		operator[](size_type n)
			{
				return	*(_ptr + n);
			}

			const_reference	operator[](size_type n) const
			{
				return	*(_ptr + n);
			}
	};
}

#endif
