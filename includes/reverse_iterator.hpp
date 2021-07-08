/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:50:12 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/08 09:46:34 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <limits>
# include <sstream>
# include <iostream>

namespace ft
{
	template <typename T>
	class reverse_iterator
	{
		public:

			typedef	std::random_access_iterator_tag	iterator_category;
			typedef	T								&value_type;
			typedef	T								&reference;
			typedef const T							&const_reference;
			typedef	T								*pointer;
			typedef ptrdiff_t						difference_type;
			typedef	size_t							size_type;

		private:

			pointer					_ptr;
			typedef	reverse_iterator self;
		
		public:

			reverse_iterator(void)
			{
			}

			reverse_iterator(T*	src)
			{
				_ptr = src;
			}

			reverse_iterator(reverse_iterator const &src)
			{
				*this = src;
			}

			reverse_iterator(iterator<T> const  &src)
			{
				_ptr = src.operator->();
			}

			virtual ~reverse_iterator()
			{
			}

			reverse_iterator	&operator=(reverse_iterator const &r_it)
			{
				_ptr = r_it.operator->();
				return	*this;
			}

			//INCREMENTS
			self		operator++()
			{
				--_ptr;
				return	*this;
			}

			self		operator++(int)
			{
				self	r_it = *this;

				--_ptr;
				return	r_it;
			}

			self		operator+=(size_type nb)
			{
				_ptr -= nb;
				return	*this;
			}

			self		operator--()
			{
				++_ptr;
				return	*this;
			}

			self		operator--(int)
			{
				self	r_it = *this;

				++_ptr;
				return	r_it;
			}

			self		operator-=(size_type nb)
			{
				_ptr += nb;
				return	*this;
			}

			//ARITHMETICS
			self		operator+(difference_type n)
			{
				return	_ptr - n;
			}

			self		operator-(difference_type n)
			{
				return	_ptr + n;
			}

			self		operator+(self &r_it)
			{
				return	_ptr - r_it._ptr;
			}

			self		operator-(self	&r_it)
			{
				return	_ptr + r_it._ptr;
			}

			//BOOLEANS
			bool		operator==(self const &r_it)
			{
				return	_ptr == r_it._ptr;
			}

			bool		operator!=(self const &r_it)
			{
				return	_ptr != r_it._ptr;
			}

			bool		operator>=(self const &r_it)
			{
				return	_ptr >= r_it._ptr;
			}

			bool		operator>(self const &r_it)
			{
				return	_ptr > r_it._ptr;
			}

			bool		operator<=(self const &r_it)
			{
				return	_ptr <= r_it._ptr;
			}

			bool		operator<(self const &r_it)
			{
				return	_ptr < r_it._ptr;
			}

			//DIFFERENCING & ADDRESS
			reference		operator*()
			{
				return	*_ptr;
			}

			const_reference	operator*() const
			{
				return	*_ptr;
			}

			pointer			operator->()
			{
				return	_ptr;
			}

			pointer			operator->() const
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
