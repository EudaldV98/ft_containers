/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 22:03:16 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/09 22:11:26 by jvaquer          ###   ########.fr       */
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

			pointer									_ptr;

	};
}

#endif
