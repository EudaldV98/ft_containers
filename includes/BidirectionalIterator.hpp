/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectionaliterator.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 18:42:00 by jvaquer           #+#    #+#             */
/*   Updated: 2021/06/25 00:09:51 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONALITERATOR_HPP
# define BIDIRECTIONALITERATOR_HPP

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
	class bidirectionalIterator
	{
		public:

			typedef std::bidirectional_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T								&reference;
			typedef const T							&const_reference;
			typedef T								*pointer;
			typedef	ptrdiff_t						difference_type;
			typedef size_t							size_type;

		private:

			typedef node<T>					value_node;
			value_node							*_ptr;
			typedef	bidirectionalIterator	Bi_iterator;

		public:

			bidirectionalIterator(): _ptr(nullptr)
			{
			}

			bidirectionalIterator(value_node *nod): _ptr(nod)
			{
			}

			bidirectionalIterator(Bi_iterator *other)
			{
				_ptr = other->_ptr;
			}

			~bidirectionalIterator()
			{
			}

			bidirectionalIterator	&operator=(Bi_iterator const &it)
			{
				this->_ptr = it._ptr;
				return	*this;
			}

			//INCREMENTS
			Bi_iterator		operator++()
			{
				_ptr = _ptr->_next;
				return	*this;
			}

			Bi_iterator		operator++(int)
			{
				Bi_iterator it = *this;

				_ptr = _ptr->_next;
				return	it;
			}

			Bi_iterator		operator--()
			{
				_ptr = _ptr->_previous;
				return	*this;
			}

			Bi_iterator		operator--(int)
			{
				Bi_iterator	it = *this;

				_ptr = _ptr->_previous;
				return (it);
			}

			//BOOLEANS
			bool			operator==(Bi_iterator const &other)
			{
				return	_ptr == other._ptr;
			}

			bool			operator!=(Bi_iterator const &other)
			{
				return	_ptr != other._ptr;
			}

			//DEFERENCING & ADDRESS STUFF
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
				return	&(_ptr->_value);
			}
	};
}

#endif
