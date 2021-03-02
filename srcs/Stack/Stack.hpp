/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 14:36:34 by jvaquer           #+#    #+#             */
/*   Updated: 2021/03/02 14:38:16 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef QUEUE_HPP
# define QUEUE_HPP

# include "../List/List.hpp"

namespace ft
{
	template <class T, class Container = list<T> >
	class stack
	{
		public:

			typedef T			value_type;
			typedef Container	container_type;
			typedef	size_t		size_type;

		private:

			container_type _container;

		public:

		explicit stack(const container_type &ctnr = container_type())
		{
			_container = ctnr;
		}

		bool				empty() const
		{
			return	_container.empty();
		}

		value_type			&top()
		{
			return	_container.back();
		}

		const value_type	&top() const
		{
			return	_container.back();
		}
	};
}

#endif
