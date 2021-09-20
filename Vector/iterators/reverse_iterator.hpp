/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/07 10:50:12 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/20 18:34:13 by jvaquer          ###   ########.fr       */
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

# include "../../iterator_traits.hpp"

namespace ft
{
	template <class Iterator>
	struct reverse_iterator
	{
		public:

			static const bool						is_iterator = true;

			typedef Iterator iterator_type;
			typedef	typename traits::iterator_traits<Iterator>::iterator_category	iterator_category;
			typedef	typename traits::iterator_traits<Iterator>::value_type			value_type;
			typedef	typename traits::iterator_traits<Iterator>::reference			reference;
			typedef	typename traits::iterator_traits<Iterator>::pointer				pointer;
			typedef typename traits::iterator_traits<Iterator>::difference_type		difference_type;
			typedef	size_t							size_type;

		private:

			pointer					_ptr;
			typedef	reverse_iterator self;
		
		public:

			reverse_iterator(void)
			{
				_ptr = NULL;
			}

			explicit reverse_iterator(iterator_type src)
			{
				_ptr = src;
			}

			template <class Iter>
			reverse_iterator(const reverse_iterator<Iter>  &src)
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

			iterator_type		base() const
			{
				return	_ptr;
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
				reverse_iterator it(_ptr - n);
				return it;
			}

			self		operator-(difference_type n)
			{
				reverse_iterator it(_ptr + n);
				return it;
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
				return	_ptr <= r_it._ptr;
			}

			bool		operator>(self const &r_it)
			{
				return	_ptr < r_it._ptr;
			}

			bool		operator<=(self const &r_it)
			{
				return	_ptr >= r_it._ptr;
			}

			bool		operator<(self const &r_it)
			{
				return	_ptr > r_it._ptr;
			}

			//DIFFERENCING & ADDRESS
			reference		operator*()
			{
				return	*_ptr;
			}

			reference	operator*() const
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

			reference		operator[](size_type n) const
			{
				return	*(_ptr + n);
			}
	};

	template <class Iterator>
	bool operator== (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		if (lhs.base() == rhs.base())
			return true;
		return false;
	};

	template <class Iterator>
	bool operator!= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return !(lhs == rhs);
	};

	template <class Iterator>
	bool operator<  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		if (lhs.base() > rhs.base())
			return true;
		return false;
	};

	template <class Iterator>
	bool operator<= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		if (lhs < rhs || lhs == rhs)
			return true;
		return false;
	};

	template <class Iterator>
	bool operator>  (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs < lhs);
	};

	template <class Iterator>
	bool operator>= (const reverse_iterator<Iterator>& lhs, const reverse_iterator<Iterator>& rhs)
	{
		return (rhs <= lhs);
	};
}

#endif
