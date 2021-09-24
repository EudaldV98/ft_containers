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

# include "../../Utils/utils.hpp"
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

			iterator_m(void): _map(NULL)
			{
			}

			iterator_m(node_type *src)
			{
				_map = src;
			}

			iterator_m(const iterator_m &src)
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

			//ARITHMETICS OPERATORS
			//

			iterator_m	operator++()
			{
				if (_map->right != NULL)
				{
					_map = _map->right;
					while (_map->left != NULL)
						_map = _map->left;
				}
				else
				{
					node_type *tmp = _map;

					_map = _map->parent;
					while (_map->parent && _map->right == tmp)
					{
						tmp = _map;
						_map = _map->parent;
					}
				}
				return *this;
			}

			iterator_m	operator++(int)
			{
				iterator_m	tmp = *this;

				++(*this);
				return	tmp;
			}

			iterator_m	operator--()
			{
				if (_map->left != NULL)
				{
					_map = _map->left;
					while (_map->right != NULL)
						_map = _map->right;
				}
				else
				{
					node_type *tmp = _map;

					_map = _map->parent;
					while (_map->parent && _map->left == tmp)
					{
						tmp = _map;
						_map = _map->parent;
					}
				}
				return	*this;
			}

			iterator_m	operator--(int)
			{
				iterator_m	tmp = *this;

				--(*this);
				return	tmp;
			}

			//BOOL OPERATORS
			//
			bool	operator==(iterator_m const &src)
			{
				return	_map == src._map;
			}

			bool	operator!=(iterator_m const &src) const
			{
				return	_map != src._map;
			}

			//DEFERENCING OPERATORS
			pointer			operator->()
			{
				return	&_map->value;
			}

			pointer			operator->() const
			{
				return &_map->value;
			}

			reference		operator*()
			{
				return	_map->value;
			}

			const_reference	operator*() const
			{
				return	_map->value;
			}

			//GETTER FNCT
			node_type		*get_map(void) const
			{
				return	_map;
			}
	};
}

#endif
