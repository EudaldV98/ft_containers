/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Queue.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 15:27:30 by jvaquer           #+#    #+#             */
/*   Updated: 2021/03/08 10:51:55 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	QUEUE_HPP
# define QUEUE_HPP

# include "../List/List.hpp"

namespace ft
{
	template <class T, class Container = list<T> >
	class queue
	{
		public:

			typedef	T			value_type;
			typedef	Container	container_type;
			typedef	size_t		size_type;

		private:

			container_type		_container;

		public:

			explicit			queue(const container_type &ctnr = container_type())
			{
				_container = ctnr;
			}

			bool				empty() const
			{
				return	_container.empty();
			}

			size_type			size() const
			{
				return	_container.size();
			}

			value_type			&front()
			{
				return	_container.front();
			}

			const	value_type	&front() const
			{
				return	_container.front();
			}

			value_type			&back()
			{
				return	_container.back();
			}

			const	value_type	&back() const
			{
				return	_container.back();
			}

			void				push(const value_type &val)
			{
				_container.push_back(val);
			}

			void				pop()
			{
				_container.pop_front();
			}

			container_type		ctr()
			{
				return	_container;
			}


		template<class T2, class Cntr>
		friend bool operator==(const queue<T2, Cntr> &lhs, const queue<T2, Cntr> &rhs);

		template<class T2, class Cntr>
		friend bool operator<(const queue<T2, Cntr> &lhs, const queue<T2, Cntr> &rhs);
	};

	template<class T, class Container>
	bool operator==(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return	lhs._container == rhs._container;
	}

	template<class T, class Container>
	bool operator!=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		return	!(lhs == rhs);
	}

	template<class T, class Container>
	bool operator<(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		if (lhs == rhs)
			return	false;
		return	lhs._container < rhs._container;
	}

	template<class T, class Container>
	bool operator<=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		if (rhs == lhs)
			return	true;
		return	(lhs < rhs);
	}

	template<class T, class Container>
	bool operator>(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		if (rhs == lhs)
			return	false;
		return	(!(lhs < rhs));
	}

	template<class T, class Container>
	bool operator>=(const queue<T, Container> &lhs, const queue<T, Container> &rhs)
	{
		if (rhs == lhs)
			return	true;
		return	!(lhs < rhs);
	}
}
#endif
