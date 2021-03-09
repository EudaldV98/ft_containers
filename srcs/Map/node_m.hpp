/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_m.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/09 13:02:44 by jvaquer           #+#    #+#             */
/*   Updated: 2021/03/09 15:37:06 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_M_HPP
# define NODE_M_HPP

#include <iostream>
#include <cstddef>

namespace ft
{
	template <class T>
	class node_m
	{
		public:

			typedef	T	value_type;

			node_m		*parent;
			node_m		*right;
			node_m		*left;
			value_type	value;

			node_m(value_type const &val = value_type()):
				value(val), parent(NULL), right(NULL), left(NULL)
			{
			}

			node_m(value_type const	&val, node_m *n):
				value(val), parent(n), right(NULL), left(NULL)
			{
			}

			node_m(node_m const	&n):
				value(n.value), parent(n.parent), right(n.right), left(n.left)
			{
			}

			node_m	&operator=(node_m const &n)
			{
				value = n.value;
				parent = n.parent;
				right = n.right;
				left = n.left;
				return	*this;
			}

			~node_m()
			{
			}

			value_type	operator->()
			{
				return	value;
			}
	};
}

#endif
