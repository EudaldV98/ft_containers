/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 00:14:48 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/09 22:10:56 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

#include "iterator.hpp"

namespace ft
{
	template <typename T>
	class	const_iterator
	{
		public:

			static const bool					is_iterator = true;

			typedef const T						value_type;
			typedef value_type					&reference;
			typedef const value_type			&const_reference;
			typedef value_type					*pointer;
			typedef typename std::ptrdiff_t		diff_type;

		private:
			pointer	_ptr;

		public:

			//Constructors

			const_iterator(void)
			{				
			}

			const_iterator(pointer ptr)
			{
				ptr = _ptr;
			}
			
			const_iterator(iterator<T> const &x)
			{
				_ptr = x.operator->();
			}

			const_iterator(const_iterator const &x)
			{
				*this = x;
			}

			//Destructor

			virtual ~const_iterator()
			{
			}
			
			const_iterator &operator=(const_iterator const &x)
			{
				_ptr = x.operator->();
				return *this;
			}

			//Binary Ops

			bool	operator==(const_iterator const &it) const
			{
				return _ptr == it._ptr;
			}

			bool	operator!=(const_iterator const &it) const
			{
				return _ptr != it._ptr;
			}

			bool	operator>(const_iterator const &it) const
			{
				return _ptr > it._ptr;
			}

			bool	operator<(const_iterator const &it) const
			{
				return _ptr < it._ptr;
			} 

			bool	operator>=(const_iterator const &it) const
			{
				return _ptr >= it._ptr;
			}

			bool	operator<=(const_iterator const &it) const
			{
				return _ptr <= it._ptr;
			}

			//Arithmetics

			const_iterator operator+(diff_type it)
			{
				return const_iterator(_ptr + it);
			}

			const_iterator operator-(diff_type it)
			{
				return const_iterator(_ptr - it);
			}

			diff_type operator+(const_iterator it)
			{
				return _ptr + it;
			}

			diff_type operator-(const_iterator it)
			{
				return _ptr - it;
			}

			const_iterator operator++()
			{
				_ptr++;
				return *this;
			}

			const_iterator operator++(int)
			{
				_ptr++;
				return const_iterator(_ptr - 1);
			}
			
			const_iterator operator--()
			{
				_ptr--;
				return *this;
			}

			const_iterator operator--(int)
			{
				_ptr--;
				return const_iterator(_ptr + 1);
			}
			
			void operator+=(diff_type it)
			{
				_ptr += it;
			}

			void operator-=(diff_type it)
			{
				_ptr -= it;
			}

			//Deferencing & Address
			const_reference	operator*() const
			{
				return *_ptr;
			}

			const_reference operator[](diff_type it) const
			{
				return (*(_ptr + it));
			}

			pointer	operator->()
			{
				return	_ptr;
			}

			pointer	operator->() const
			{
				return _ptr;
			}

			static const bool	input_iter = true;
	};
}

#endif