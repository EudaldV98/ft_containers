/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator_m.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 12:25:14 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/24 15:22:04 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_ITERATOR_M_HPP
# define CONST_ITERATOR_M_HPP

# include "../../Utils/utils.hpp"
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
		
			node_type	*_ptr;
		
		public:

			const_iterator_m(void): _ptr(NULL)
			{
			}

			const_iterator_m(node_type *src)
			{
				_ptr = src;
			}

			const_iterator_m(const const_iterator_m &src)
			{
				_ptr = src._ptr;
			}

			const_iterator_m(const iterator_m<T, node_type> &src)
			{
				_ptr = src.get_ptr();
			}

			virtual	~const_iterator_m()
			{
			}

			const_iterator_m &operator=(const_iterator_m const &src)
			{
				_ptr = src._ptr;
				return	*this;
			}

			//BOOL OPERATOR
			bool	operator==(const_iterator_m const &src) const
			{
				return 	_ptr == src._ptr;
			}

			bool	operator!=(const_iterator_m const &src) const
			{
				return	_ptr != src._ptr;
			}

			//ARITHMETICS OPERATOR
			const_iterator_m	operator++()
			{
				if (_ptr->right != NULL)
				{
					_ptr = _ptr->right;
					while (_ptr->left != NULL)
						_ptr = _ptr->left;
				}
				else
				{
					node_type	*ptr = _ptr;

					_ptr = _ptr->parent;
					while (_ptr->right == ptr)
					{
						ptr = _ptr;
						_ptr = _ptr->parent;
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

		};
}

#endif
