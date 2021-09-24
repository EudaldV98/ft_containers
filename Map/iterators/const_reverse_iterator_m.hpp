/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_reverse_iterator_m.hpp                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 19:19:49 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/24 15:21:55 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_REVERSE_ITERATOR_HPP
# define CONST_REVERSE_ITERATOR_HPP

# include   "../../Utils/utils.hpp"
# include	"./iterator_m.hpp"
//# include	"../map.hpp"

namespace ft
{
	template <typename T, typename node_type>
	class	const_reverse_iterator_m
	{
		public:

			static const bool			is_iterator = true;
			typedef T					value_type;
			typedef value_type			&reference;
			typedef const value_type	&const_reference;
			typedef value_type			*pointer;
			typedef std::ptrdiff_t		difference_type;

		private:

			const node_type		*_map;
		
		public:

			const_reverse_iterator_m(void): _map(NULL)
			{
			}

			const_reverse_iterator_m(node_type *src)
			{
				_map = src;
			}

			const_reverse_iterator_m(const const_reverse_iterator_m &src)
			{
				_map = src._map;
			}

			const_reverse_iterator_m(const iterator_m<T, node_type> &src)
			{
				_map = src.get_map();
			}

			virtual ~const_reverse_iterator_m()
			{
			}

			const_reverse_iterator_m	&operator=(const_reverse_iterator_m const &src)
			{
				_map = src._map;
				return	*this;
			}

			//OPERATOR BOOL
			bool	operator==(const_reverse_iterator_m const &src) const
			{
				return	_map == src._map;
			}

			bool	operator!=(const_reverse_iterator_m const &src) const
			{
				return	_map != src._map;
			}

			//OPERATOR ARITHMETICS
			const_reverse_iterator_m	operator++()
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
				}
				return *this;
			}

			const_reverse_iterator_m	operator++(int)
			{
				const_reverse_iterator_m	tmp = *this;
				++(*this);
				return	tmp;
			}

			const_reverse_iterator_m	operator--()
			{
				if (_map->right != NULL)
				{
					_map = _map->right;
					while (_map->left != NULL)
						_map = _map->left;
				}
				else
				{
					node_type	*ptr = _map;

					_map = _map->parent;
					while (_map->right == ptr)
					{
						ptr = _map;
						_map = _map->parent;
					}
				}
				return	*this;
			}

			const_reverse_iterator_m	operator--(int)
			{
				const_reverse_iterator_m	tmp = *this;

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