/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/11 11:14:49 by jvaquer           #+#    #+#             */
/*   Updated: 2021/06/24 18:19:16 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

# include <cstddef>

namespace ft
{
	template <class T>
	class node
	{
		public:
			typedef T	value_type;
			typedef T	reference;
			typedef T	*pointer;

			node		*_next;
			node		*_previous;
			T			_value;

		node(const value_type &val = value_type()):
			_next(nullptr), _previous(nullptr), _value(val)
		{
		}

		node(node *next, node *before, const value_type &val):
			_next(next), _previous(before), _value(val)
		{
		}

		node(const node &nod):
			_next(nod._next), _previous(nod._previous), _value(nod.value)
		{
		}

		~node()
		{
		}

		node	&operator=(const node &nod)
		{
			_next = nod._next;
			_previous = nod._previous;
			_value = nod._value;
			return	*this;
		}

		bool	operator==(const node &nod)
		{
			if (_value != nod._value || _next != nod._next || _previous != nod._previous)
				return	false;
			return	true;
		}

		bool	operator!=(const node &nod)
		{
			return	!(*this == nod);
		}

		node	*get_next()
		{
			return	this->_next;
		}

		node	*get_before()
		{
			return	this->_previous;
		}
	};
}
#endif
