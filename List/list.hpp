/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:11:02 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/13 22:15:21 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	LIST_HPP
# define LIST_HPP

# include <algorithm>
# include <limits>
# include "iterators/iterator.hpp"
# include "iterators/reverse_iterator.hpp"
# include "iterators/const_iterator.hpp"
# include "iterators/const_reverse_iterator.hpp"
# include "../utils.hpp"

template <typename T>
struct Node
{
	Node	*prev;
	Node	*next;
	T		value;
};

namespace ft
{
	class list
	{
		public:

		private:

		public:
	};
}

#endif
