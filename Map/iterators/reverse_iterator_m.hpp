/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_m.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:54:58 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/17 12:26:11 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_M_HPP
# define REVERSE_ITERATOR_M_HPP

# include "../../utils.hpp"
# include "./iterator_m.hpp"
//# include "../map.hpp"

namespace ft
{
	template <typename T, typename node_type>
	class	reverse_iterator_m
	{
		public:

			static const bool			is_iterator = true;
			typedef T					value_type;
			typedef value_type			&reference;
			typedef const value_type	&const_reference;
			typedef value_type			*pointer;
			typedef std::ptrdiff_t		difference_type;

		private:

			node_type	*_map;
		
		public:

			reverse_iterator_m(void): _map(NULL)
			{
			}

			reverse_iterator_m(node_type *src)
			{
				_map = src;
			}

			reverse_iterator_m(const reverse_iterator_m &src)
			{
				_map = src._map;
			}

			reverse_iterator_m(const iterator_m<T, node_type> &src)
			{
				_map = src.get_map();
			}

			virtual ~reverse_iterator_m()
			{
			}

			reverse_iterator_m	&operator=(reverse_iterator_m const &src)
			{
				_map = src._map;
				return	*this;
			}

			//OPERATOR BOOL
			bool	operator==(reverse_iterator_m const &src) const
			{
				return	_map == src._map;
			}

			bool	operator!=(reverse_iterator_m const &src) const
			{
				return	_map != src._map;
			}

			//OPERATOR ARITHMETICS
			reverse_iterator_m	operator++()
			{
				if (_map->left != NULL)
				{
					_map = _map->left;
					while (_map->right != NULL)
						_map = _map->right;
				}
				else
				{
					node_type	*ptr = _map;

					_map = _map->parent;
					while (_map && ptr == _map->left)
					{
						ptr = _map;
						_map = _map->parent;
					}
					return	*this;
				}
			}

			reverse_iterator_m	operator++(int)
			{
				reverse_iterator_m	tmp = *this;
				++(*this);
				return	tmp;
			}

			reverse_iterator_m	operator--()
			{
				if (_map->right != NULL)
				{
					_map = _map->right;
					while (_map->left)
						_map = _map->left;
				}
				else
				{
					node_type	*child = _map;

					_map = _map->parent;
					while (_map->right == child)
					{
						child = _map;
						_map = _map->parent;
					}
				}
				return	*this;
			}

			reverse_iterator_m	operator--(int)
			{
				reverse_iterator_m	tmp = *this;
				--(*this);
				return	tmp;
			}
			
			//DEFERENCING OPERATORS
			reference		operator*()
			{
				return	_map->value;
			}

			const_reference	operator*() const
			{
				return	_map->value;
			}

			pointer			operator->()
			{
				return	&_map->value;
			}

			pointer			operator->() const
			{
				return	&_map->value;
			}

	};
}

#endif