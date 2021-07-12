/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_iterator.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:02:41 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/12 11:23:53 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	CONST_ITERATOR_HPP
# define CONST_ITERATOR_HPP

# include "iterator.hpp"

namespace ft
{
	template <typename T, typename Node>
	class const_iterator
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
			const_iterator(void)
			{
			}

			const_iterator(const Node *src)
			{
				_node = src;
			}

			const_iterator(iterator<T, Node> const &src)
			{
				_node = src.operator->();
			}

			const_iterator(const_iterator consrt &src)
			{
				_node = src._node;
			}

			virtual ~const_iterator()
			{
			}

			const_iterator &operator=(const_iterator const &src)
			{
				_node = src._node;
				return	*this;
			}

			//Binary Ops
			bool	operator==(const_iterator const &src)
			{
				return	_node == src._node;
			}

			bool	operator!=(const_iterator const &src)
			{
				return	_node != src._node;
			}

			//Arithmetics
			const_iterator	operator++()
			{
				_node = _node->next;
				return	*this;
			}

			const_iterator	operator++(int)
			{
				const_iterator tmp = *this;

				++(*this);
				return	tmp;
			}

			const_iterator	operator--()
			{
				_node = _node->prev;
				return	*this;
			}

			const_iterator	operator--(int)
			{
				const_iterator tmp = *this;

				--(*this);
				return	tmp;
			}

			//Deferencing
			const_reference	operator*() const
			{
				return	_node->value;
			}

			const Node*	operator->() const
			{
				return	_node;
			}
	};
}

#endif
