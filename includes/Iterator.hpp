/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:44:01 by jvaquer           #+#    #+#             */
/*   Updated: 2021/02/05 11:06:59 by jvaquer          ###   ########.fr       */
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
	class Iterator
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
			typedef Iterator						self;

		public:

			Iterator ()
			{
			}

			Iterator(pointer other): _ptr(other)
			{
			}

			Iterator(Iterator *it)
			{
				_ptr = it->ptr;
			}

			~Iterator()
			{
			}

			reference	operator=(self const &it)
			{
				_ptr = it._ptr;
				return	*this;
			}

			//INCREMENTS - DECREMENTS
			self		operator++()
			{
				++_ptr;
				return	*this;
			}

			self		operator++(int)
			{
				self	it = *this;
				++_ptr;
				return	it;
			}

			self		operator+=(size_type nb)
			{
				_ptr += nb;
				return	*this;
			}

			self		operator--()
			{
				--_ptr;
				return	*this;
			}

			self		operator--(int)
			{
				self	it = *this;
				
				--_ptr;
				return	it;
			};

			self		operator-=(size_type nb)
			{
				_ptr -= nb;
				return	*this;
			}

			//ARITHMETICS
			self		operator+(difference_type x)
			{
				return	_ptr + x;
			}

			self		operator-(difference_type x)
			{
				return	_ptr - x;
			}

			self		operator+(self &other)
			{
				return _ptr - other.ptr;
			}

			self		operator-(self &other)
			{
				return 	_ptr - other._ptr;
			}

			//BINARY OPS
			bool		operator==(self const &it)
			{
				return	_ptr == it._ptr;
			}

			bool		operator!=(self const &it)
			{
				return	_ptr != it._ptr;
			}

			bool		operator>=(self const &it)
			{
				return	_ptr >= it._ptr;
			}

			bool		operator>(self const &it)
			{
				return	_ptr > it._ptr;
			}

			bool		operator<=(self const &it)
			{
				return	_ptr <= it._ptr;
			}

			bool		operator<(self const &it)
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
