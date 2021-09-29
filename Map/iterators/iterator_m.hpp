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

		public:

			node_type		*_ptr;

		public:

			iterator_m(void): _ptr(NULL)
			{
			}

			iterator_m(node_type *src)
			{
				_ptr = src;
			}

			iterator_m(const iterator_m &src)
			{
				_ptr = src._ptr;
			}

			virtual	~iterator_m()
			{
			}

			iterator_m	&operator=(iterator_m const &src)
			{
				_ptr = src._ptr;
				return	*this;
			}

			//ARITHMETICS OPERATORS
			//

			iterator_m	operator++()
			{
				if (_ptr->right != NULL)
				{
					_ptr = _ptr->right;
					while (_ptr->left != NULL)
						_ptr = _ptr->left;
				}
				else
				{
					node_type *tmp = _ptr;

					_ptr = _ptr->parent;
					while (_ptr->parent && _ptr->right == tmp)
					{
						tmp = _ptr;
						_ptr = _ptr->parent;
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
				if (_ptr->left != NULL)
				{
					_ptr = _ptr->left;
					while (_ptr->right != NULL)
						_ptr = _ptr->right;
				}
				else
				{
					node_type *tmp = _ptr;

					_ptr = _ptr->parent;
					while (_ptr->parent && _ptr->left == tmp)
					{
						tmp = _ptr;
						_ptr = _ptr->parent;
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
				return	_ptr == src._ptr;
			}

			bool	operator!=(iterator_m const &src) const
			{
				return	_ptr != src._ptr;
			}

			//DEFERENCING OPERATORS
			pointer			operator->()
			{
				return	_ptr->value;
			}

			pointer			operator->() const
			{
				return _ptr->value;
			}

			reference		operator*()
			{
				return	*(_ptr->value);
			}

			const_reference	operator*() const
			{
				return	*(_ptr->value);
			}

			//GETTER FNCT
			node_type		*get_ptr(void) const
			{
				return	_ptr;
			}
	};
}

#endif
