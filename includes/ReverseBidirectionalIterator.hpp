/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseBidirectionalIterator.hpp                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 18:12:48 by jvaquer           #+#    #+#             */
/*   Updated: 2021/02/12 18:47:48 by jvaquer          ###   ########.fr       */
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
	class ReverseBidirectionalIterator
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
			typedef	ReverseBidirectionalIterator	Bi_iterator;

		public:

			ReverseBidirectionalIterator (): _ptr(nullptr)
			{
			}

			ReverseBidirectionalIterator(value_node *nod): _ptr(nod)
			{
			}

			ReverseBidirectionalIterator(Bi_iterator *other)
			{
				_ptr = other->_ptr;
			}

			~ReverseBidirectionalIterator()
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
