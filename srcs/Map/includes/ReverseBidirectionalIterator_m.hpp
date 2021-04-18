/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ReverseBidirectionalIterator_m.hpp                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/14 18:42:37 by jvaquer           #+#    #+#             */
/*   Updated: 2021/03/15 11:57:03 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSEBIDIRECTIONAL_ITERATOR_M_HPP
# define REVERSEBIDIRECTIONAL_ITERATOR_M_HPP

# include <cstddef>
# include <memory>
# include <iostream>
# include <limits>
# include "node_m.hpp"

namespace ft
{
	template <class T>
	class ReverseBidirectionalIterator_m
	{
		public:

			typedef	std::reverse_bidirectional_iterator_tag iterator_category;
			typedef	T								value_type;
			typedef	T								&reference;
			typedef	const	T						&const_reference;
			typedef	T								*pointer;
			typedef	ptrdiff_t						difference_type;
			typedef	size_t							size_type;

		private:

			typedef	node_m<T>				node;
			node							*_ptr;
			typedef	ReverseBidirectionalIterator_m	_self;

		public:

			ReverseBidirectionalIterator_m():
				_ptr(NULL)
			{
			}

			ReverseBidirectionalIterator_m(node *n):
				_ptr(n)
			{
			}

			ReverseBidirectionalIterator_m(_self *it):
				_ptr(it->_ptr)
			{
			}

			_self	&operator=(_self const &it)
			{
				_ptr = it._ptr;
				return	*this;
			}

			//INC/DEC
			//
			_self	operator++(int)
			{
				if (_ptr->left)
				{
					_ptr = _ptr->left;
					while (_ptr->right)
						_ptr = _ptr->right;
				}
				else
				{
					node	*tmp = _ptr;
					_ptr = _ptr->parent;
					while (_ptr->parent && tmp == _ptr->right)
					{
						tmp = _ptr;
						_ptr = _ptr->parent;
					}
				}
				return	*this;
			}

			_self	operator++()
			{
				if (_ptr->right)
				{
					_ptr = _ptr->right;
					while (_ptr->left)
						_ptr = _ptr->left;
				}
				else if (_ptr->parent)
					_ptr = _ptr->parent;
				return	*this;
			}

			_self	operator--()
			{
				if (_ptr->left)
				{
					_ptr = _ptr->left;
					while (_ptr->right)
						_ptr = _ptr->right;
				}
				else if (_ptr->parent)
					_ptr = _ptr->parent;
				return	*this;
			}

			_self	operator--(int)
			{
				if (_ptr->left)
				{
					_ptr = _ptr->left;
					while (_ptr->right)
						_ptr = _ptr->right;
				}
			}

			//OPERATORS
			//
			bool	operator==(_self const &it)
			{
				return	_ptr == it._ptr;
			}

			bool	operator!=(_self const &it) const
			{
				return	_ptr != it._ptr;
			}

			bool	operator->()
			{
				return	&_ptr->_value;
			}

			bool	operator*()
			{
				return	_ptr->_value;
			}
	};
}

#endif
