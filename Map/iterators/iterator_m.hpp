/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_m.hpp                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 15:41:54 by jvaquer           #+#    #+#             */
/*   Updated: 2021/06/24 18:19:31 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BIDIRECTIONAL_ITERATOR_M_HPP
# define BIDIRECTIONAL_ITERATOR_M_HPP

# include <cstddef>
# include <memory>
# include <iostream>
# include <limits>
# include "../map.hpp"

namespace ft
{
	template <class T, typename node_type>
	class iterator_m
	{
		public:

			static const bool						is_iterator = true;
			typedef	std::bidirectional_iterator_tag iterator_category;
			typedef	T								value_type;
			typedef	value_type						&reference;
			typedef	const	value_type				&const_reference;
			typedef	value_type						*pointer;
			typedef	std::ptrdiff_t					difference_type;

		private:

			node_type		*_map;

		public:

			iterator_m(): _map(NULL)
			{
			}

			iterator_m(node *src):
			{
				_map = src;
			}

			iterator_m(const iterator_m &src):
			{
				_map = src._map;
			}

			virtual	~iterator_m()
			{
			}

			iterator_m	&operator=(iterator_m const &src)
			{
				_map = src._map;
				return	*this;
			}

			//INC/DEC
			//
			_self	operator++(int)
			{
				if (_ptr->right)
				{
					_ptr = _ptr->right;
					while (_ptr->left)
						_ptr = _ptr->left;
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
