/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:31:43 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/20 15:30:23 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS

#include <cstddef>

namespace traits
{
	// struct random_access_iterator_tag { };

	template <class Iterator>
	class iterator_traits
	{
		public:
			typedef typename Iterator::difference_type	difference_type;
			typedef typename Iterator::value_type		value_type;
			typedef typename Iterator::pointer			pointer;
			typedef typename Iterator::reference		reference;
			typedef typename Iterator::category			iterator_category;
	};

	template <class T>
	class iterator_traits<T*>
	{
		public:
			typedef ptrdiff_t	difference_type;
			typedef T			value_type;
			typedef T		*pointer;
			typedef T		&reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*>
	{
		public:
			typedef ptrdiff_t	difference_type;
			typedef T			value_type;
			typedef const T		*pointer;
			typedef const T		&reference;
			typedef std::random_access_iterator_tag	iterator_category;
	};
}

#endif
