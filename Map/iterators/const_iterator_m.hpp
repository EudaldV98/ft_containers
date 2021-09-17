/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator_m.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:25:14 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/17 12:23:45 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_M_HPP
# define CONST_ITERATOR_M_HPP

# include "../../utils.hpp"
# include "./iterator_m.hpp"

namespace ft
{
	template <typename T, typename node_type>
	class	const_iterator_m
	{
		public:
			
			static const bool				is_iterator = true;
			typedef T						value_type;
			typedef value_type				&reference;
			typedef const value_type 		&const_reference;
			typedef value_type				*pointer;
			typedef std::ptrdiff_t			difference_type;

		private:
		
			node_type	*_map;
		
		public:

			const_iterator_m(void): _map(NULL)
			{
			}

			const_iterator_m(node_type *src)
			{
				_map = src;
			}

			const_iterator_m(const const_iterator_m &src)
			{
				_map = src._map;
			}

			const_iterator_m(const iterator_m<T, node_type> &src)
			{
				_map = src.get_map();
			}

			virtual	~const_iterator_m()
			{
			}

			const_iterator_m &operator=(const_iterator_m const &src)
			{
				_map = src._map;
				return	*this;
			}

			//BOOL OPERATOR
			bool	operator==(const_iterator_m const &src) const
			{
				return 	_map == src._map;
			}

			bool	operator!=(const_iterator_m const &src) const
			{
				return	_map != src._map;
			}

			//ARITHMETICS OPERATOR
			const_iterator_m	operator++()
			{
				if (_map->right)
				{
					_map = _map->right;
					while (_map->left)
						_map = _map->left;
				}
				else
				{
					node_type	*child = _map;

					_map = _map->parent;
					while (_map->rigt == child)
					{
						child = _map;
						_map = _map->parent;
					}
				}
				return	*this;
			}

			const_iterator_m	operator++(int)
			{
				const_iterator_m	tmp = *this;

				++(*this);
				return	tmp;
			}
			
			const_iterator_m	operator--()
			{
				if (_map->left)
				{
					_map = _map->left;
					while (_map->right)
						_map = _map->right;
				}
				else
				{
					node_type	*child = _map;

					_map = _map->parent;
					while (_map && child == _map->left)
					{
						child = _map;
						_map = _map->parent;
					}
				}
				return	*this;
			}

			const_iterator_m	operator--(int)
			{
				const_iterator_m	tmp = *this;

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

		};
}

#endif
