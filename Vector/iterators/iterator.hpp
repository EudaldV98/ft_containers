/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/05 09:44:01 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/20 15:07:09 by jvaquer          ###   ########.fr       */
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

			static const bool						is_iterator = true;

			typedef std::random_access_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T								&reference;
			typedef const T							&const_reference;
			typedef T								*pointer;
			typedef typename std::ptrdiff_t			difference_type;
			typedef size_t							size_type;

		private:

			pointer									_ptr;

		public:

			iterator (void)
			{
			}

			iterator(T *src)
			{
				_ptr = src;
			}

			iterator(iterator const &src)
			{
				*this = src;
			}

			virtual ~iterator()
			{
			}

			iterator	&operator=(iterator const &src)
			{
				_ptr = src.operator->();
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
				return	iterator(_ptr + x);
			}

			iterator		operator-(difference_type x)
			{
				return	iterator(_ptr - x);
			}

			iterator		operator+(iterator other)
			{
				return	iterator(_ptr - other._ptr);
			}

			iterator		operator-(iterator other)
			{
				return 	iterator(_ptr - other._ptr);
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

			pointer			operator->() const
			{
				return _ptr;
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
