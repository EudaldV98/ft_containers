/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseBidirectionalIterator.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:12:48 by jvaquer           #+#    #+#             */
/*   Updated: 2021/06/25 00:11:58 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEBIDIRECTIONALITERATOR
# define REVERSEBIDIRECTIONALITERATOR

# include <cstdlib>
# include <cstddef>
# include <memory>
# include <limits>
# include <sstream>
# include <iostream>
# include "../srcs/List/node.hpp"
# include "../srcs/List/List.hpp"

namespace ft
{
	template <typename T>
	class reverseBidirectionalIterator
	{
		public:

			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T								&reference;
			typedef const T							&const_reference;
			typedef T								*pointer;
			typedef ptrdiff_t						difference_type;
			typedef size_t							size_type;

		private:

			typedef node<T>							value_node;
			value_node								*_ptr;
			typedef	reverseBidirectionalIterator	Bi_iterator;

		public:

			reverseBidirectionalIterator (): _ptr(nullptr)
			{
			}

			reverseBidirectionalIterator(value_node *nod): _ptr(nod)
			{
			}

			reverseBidirectionalIterator(Bi_iterator *other)
			{
				_ptr = other->_ptr;
			}

			~reverseBidirectionalIterator()
			{
			}

			//INCREMENTS
			Bi_iterator		operator++()
			{
				_ptr = _ptr->_previous;
				return	*this;
			}

			Bi_iterator		operator++(int)
			{
				Bi_iterator	it = *this;

				_ptr = _ptr->_previous;
				return	it;
			}

			Bi_iterator		operator--()
			{
				_ptr = _ptr->_next;
				return	*this;
			}

			Bi_iterator		operator--(int)
			{
				Bi_iterator	it = *this;

				_ptr = _ptr->_next;
				return	it;
			}

			//BOOL
			bool	operator==(Bi_iterator const &other)
			{
				return	_ptr == other._ptr;
			}

			bool	operator!=(Bi_iterator const &other)
			{
				return	_ptr != other._ptr;
			}

			//DIFFERENCING && ADDRESS
			reference		operator*()
			{
				return	_ptr->_value;
			}

			const_reference	operator*() const
			{
				return	_ptr->_value;
			}

			pointer			operator->()
			{
				return	&(_ptr->value);
			}
	};
}

#endif
