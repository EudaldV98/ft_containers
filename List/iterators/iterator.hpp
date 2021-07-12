/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:03:16 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/12 11:04:47 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include "../../utils.hpp"

namespace ft
{
	template <typename T, typename Node>
	class	iterator
	{
		public:

			static const bool						is_iterator = true;

			typedef std::random_access_iterator_tag	iterator_category;
			typedef T								value_type;
			typedef T								&reference;
			typedef const T							&const_reference;
			typedef T								*pointer;
			typedef typename std::ptrdiff_t			difference_type;
			typedef size_t							size_type;

		private:

			pointer		_ptr;
			Node		*_node;

		public:
		
			//Constructors/Destructor
			iterator(void)
			{
			}

			iterator(Node *src)
			{
				_node = src;
			}

			iterator(iterator const &src)
			{
				*this = src;
			}

			virtual ~iterator()
			{
			}

			iterator &operator=(iterator const &src)
			{
				_node = src._node;
				return	*this;
			}

			//Binary Ops
			bool	operator==(iterator const &src)
			{
				return	_node == src._node;
			}

			bool	operator!=(iterator const &src)
			{
				return	_node != src._node;
			}

			//Arithmetics
			iterator	operator++()
			{
				_node = _node->next;
				return	*this;
			}

			iterator	operator++(int)
			{
				iterator tmp = *this;

				++(*this);
				return tmp;
			}

			iterator	operator--()
			{
				_node = _node->prev;
				return	*this;
			}

			iterator	operator--(int)
			{
				iterator tmp = *this;

				--(*this);
				return	*tmp;
			}

			//Deferencing
			const_reference	operator*() const
			{
				return	_node->value;
			}

			reference		operator*()
			{
				return	_node->value;
			}

			Node*			operator->() const()
			{
				return	_node;
			}

			Node*			operator->()
			{
				return	_node;
			}
	};
}

#endif
