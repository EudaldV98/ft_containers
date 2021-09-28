/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator_m.hpp                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:54:58 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/24 15:21:39 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_M_HPP
# define REVERSE_ITERATOR_M_HPP

# include "../../Utils/utils.hpp"
# include "./iterator_m.hpp"
# include "../map.hpp"

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

			node_type	*_ptr;
		
		public:

			reverse_iterator_m(void): _ptr(NULL)
			{
			}

			reverse_iterator_m(node_type *src)
			{
				_ptr = src;
			}

			reverse_iterator_m(const reverse_iterator_m &src)
			{
				_ptr = src._ptr;
			}

			reverse_iterator_m(const iterator_m<T, node_type> &src)
			{
				_ptr = src.get_ptr();
			}

			virtual ~reverse_iterator_m()
			{
			}

			reverse_iterator_m	&operator=(reverse_iterator_m const &src)
			{
				_ptr = src._ptr;
				return	*this;
			}

			//OPERATOR BOOL
			bool	operator==(reverse_iterator_m const &src) const
			{
				return	_ptr == src._ptr;
			}

			bool	operator!=(reverse_iterator_m const &src) const
			{
				return	_ptr != src._ptr;
			}

			//OPERATOR ARITHMETICS
			reverse_iterator_m	operator++()
			{
				if (_ptr->left != NULL)
				{
					_ptr = _ptr->left;
					while (_ptr->right != NULL)
						_ptr = _ptr->right;
				}
				else
				{
					node_type	*ptr = _ptr;

					_ptr = _ptr->parent;
					while (_ptr && ptr == _ptr->left)
					{
						ptr = _ptr;
						_ptr = _ptr->parent;
					}
				}
				return *this;
			}

			reverse_iterator_m	operator++(int)
			{
				reverse_iterator_m	tmp = *this;

				++(*this);
				return	tmp;
			}

			reverse_iterator_m	operator--()
			{
				if (_ptr->right != NULL)
				{
					_ptr = _ptr->right;
					while (_ptr->left != NULL)
						_ptr = _ptr->left;
				}
				else
				{
					node_type	*child = _ptr;

					_ptr = _ptr->parent;
					while (_ptr->right == child)
					{
						child = _ptr;
						_ptr = _ptr->parent;
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
				return	*(_ptr->value);
			}

			const_reference	operator*() const
			{
				return	*(_ptr->value);
			}

			pointer			operator->()
			{
				return	_ptr->value;
			}

			pointer			operator->() const
			{
				return	_ptr->value;
			}

			node_type		*get_ptr(void) const
			{
				return	_ptr;
			}

	};
}

#endif