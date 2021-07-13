/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 21:39:36 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/13 21:56:40 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP

# include "../utils.hpp"
# include "iterator.hpp"

namespace ft
{
	template <typename T, typename Node>
	class reverse_iterator
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
			reverse_iterator(void)
			{
			}

			reverse_iterator(Node *src)
			{
				_node = src;
			}

			reverse_iterator(iterator<T, Node> const &src)
			{
				*this = src;
			}

			reverse_iterator(const reverse_iterator &src)
			{
				_node = src.operator->();
			}

			virtual ~reverse_iterator()
			{	
			}

			reverse_iterator &operator=(reverse_iterator const &src)
			{
				_node = src._node;
				return *this;
			}

			//Binary Ops
			bool operator==(reverse_iterator const &src)
			{
				return	_node == src._node;
			}

			bool operator!=(reverse_iterator const &src)
			{
				return	_node != src._node;
			}

			//Arithmetics
			reverse_iterator	operator++()
			{
				_node = _node->prev;
				return	*this;
			}

			reverse_iterator	operator++(int)
			{
				reverse_iterator tmp = *this;

				--(*this);
				return	tmp;
			}

			reverse_iterator	operator--()
			{
				_node = _node->next;
				return	*this;
			}

			reverse_iterator	operator--(int)
			{
				reverse_iterator tmp = *this;

				++(*this);
				return	tmp;
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

			Node			*operator->() const
			{
				return	_node;
			}

			Node			*operator->()
			{
				return	_node->value;
			}

	};
}

#endif
