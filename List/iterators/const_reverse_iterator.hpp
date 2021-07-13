/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   const_reverse_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:54:06 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/13 21:56:20 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONST_REVERSE_ITERATOR_HPP
# define CONST_EVERSE_ITERATOR_HPP

# include "../utils.hpp"
# include "iterator.hpp"

namespace ft
{
	template <typename T, typename Node>
	class const_reverse_iterator
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
			
			//Constructors & Destructor
			const_reverse_iterator(void)
			{
			}

			const_reverse_iterator(Node *src)
			{
				_node = src;
			}

			const_reverse_iterator(iterator<T, Node> const &src)
			{
				*this = src;
			}

			const_reverse_iterator(const const_reverse_iterator &src)
			{
				_node = src.operator->();
			}

			virtual ~const_reverse_iterator()
			{	
			}

			const_reverse_iterator &operator=(const_reverse_iterator const &src)
			{
				_node = src._node;
				return *this;
			}

			//Binary Ops
			bool operator==(const_reverse_iterator const &src)
			{
				return	_node == src._node;
			}

			bool operator!=(const_reverse_iterator const &src)
			{
				return	_node != src._node;
			}

			//Arithmetics
			const_reverse_iterator	operator++()
			{
				_node = _node->prev;
				return	*this;
			}

			const_reverse_iterator	operator++(int)
			{
				const_reverse_iterator tmp = *this;

				--(*this);
				return	tmp;
			}

			const_reverse_iterator	operator--()
			{
				_node = _node->next;
				return	*this;
			}

			const_reverse_iterator	operator--(int)
			{
				const_reverse_iterator tmp = *this;

				++(*this);
				return	tmp;
			}

			//Deferencing
			const_reference	operator*() const
			{
				return	_node->value;
			}

			Node			*operator->() const
			{
				return	_node;
			}
	};
}

#endif
