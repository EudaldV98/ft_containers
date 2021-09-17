/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_traits.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:31:43 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/17 17:37:50 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef ITERATOR_TRAITS
# define ITERATOR_TRAITS

# include <iterator>

namespace traits
{
	struct	input_iterator_tag { };
	struct	output_iterator_tag { };
	struct	forward_iterator_tag { };
	struct	bidirectional_iterator_tag { };
	struct	random_access_iterator_tag { };

	template <class Iterator>
	class iterator_traits
	{
		typedef typename Iterator::difference_type	difference_type;
		typedef typename Iterator::value_type		value_type;
		typedef typename Iterator::pointer			pointer;
		typedef typename Iterator::reference		reference;
		typedef typename Iterator::category			iterator_category;
	};

}

#endif
