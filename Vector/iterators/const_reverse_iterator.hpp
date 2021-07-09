/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_reverse_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 01:06:32 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/09 21:52:50 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_REVERSE_ITERATOR_HPP
# define CONST_REVERSE_ITERATOR_HPP

# include "const_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{
	template <typename T>
	class	const_reverse_iterator
	{
		public:

			typedef const T						value_type;
			typedef value_type					&reference;
			typedef const value_type			&const_reference;
			typedef value_type					*pointer;
			typedef typename std::ptrdiff_t		diff_type;

		private:
			pointer	_ptr;

		public:

			//Constructors

			const_reverse_iterator(void)
			{				
			}

			const_reverse_iterator(const T	*src)
			{
				_ptr = src;
			}

			const_reverse_iterator(iterator<T> const &x)
			{
				_ptr = x.operator->();
			}
			
			const_reverse_iterator(reverse_iterator<T> const &x)
			{
				_ptr = x.operator->();
			}

			const_reverse_iterator(const_reverse_iterator const &x)
			{
				*this = x;
			}

			//Destructor

			virtual ~const_reverse_iterator()
			{
			}
			
			const_reverse_iterator &operator=(const_reverse_iterator const &x)
			{
				_ptr = x.operator->();
				return *this;
			}

			//Binary Ops

			bool	operator==(const_reverse_iterator const &it) const
			{
				return _ptr == it._ptr;
			}

			bool	operator!=(const_reverse_iterator const &it) const
			{
				return _ptr != it._ptr;
			}

			bool	operator>=(const_reverse_iterator const &it) const
			{
				return _ptr <= it._ptr;
			}

			bool	operator>(const_reverse_iterator const &it) const
			{
				return _ptr < it._ptr;
			}

			bool	operator<=(const_reverse_iterator const &it) const
			{
				return _ptr >= it._ptr;
			}

			bool	operator<(const_reverse_iterator const &it) const
			{
				return _ptr > it._ptr;
			} 

			//Arithmetics

			const_reverse_iterator operator+(diff_type it)
			{
				return const_reverse_iterator(_ptr - it);
			}

			const_reverse_iterator operator-(diff_type it)
			{
				return const_reverse_iterator(_ptr + it);
			}

			diff_type operator+(const_reverse_iterator it)
			{
				return _ptr - it;
			}

			diff_type operator-(const_reverse_iterator it)
			{
				return _ptr + it;
			}

			const_reverse_iterator operator++()
			{
				_ptr--;
				return *this;
			}

			const_reverse_iterator operator++(int)
			{
				_ptr--;
				return const_reverse_iterator(_ptr + 1);
			}
			
			const_reverse_iterator operator--()
			{
				_ptr++;
				return *this;
			}

			const_reverse_iterator operator--(int)
			{
				_ptr++;
				return const_reverse_iterator(_ptr - 1);
			}
			
			void operator+=(diff_type it)
			{
				_ptr -= it;
			}

			void operator-=(diff_type it)
			{
				_ptr += it;
			}

			//Deferencing &address

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