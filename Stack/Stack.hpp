/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:48:23 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/12 11:32:20 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "../List/list.hpp"


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

		size_type			size() const
		{
			return	_container.size();
		}

		value_type			&top()
		{
			return	_container.back();
		}

		const value_type	&top() const
		{
			return	_container.back();
		}

		void				push(const value_type &val)
		{
			_container.push_back(val);
		}

		void				pop()
		{
			_container.pop_back();
		}

		template <class T2, class Cntr>
		friend bool	operator==(const stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);
		
		template <class T2, class Cntr>
		friend bool operator<(const	stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);
	};

	template <class T, class Container>
	bool	operator==(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return	lhs._container == rhs._container;
	}

	template <class T, class Container>
	bool	operator!=(const stack<T, Container> &lhs, const stack<T, Container> &rhs)
	{
		return	!(lhs == rhs);
	}

	template <class T, class Container>
	bool	operator<(const stack<T, Container> &lhs, const	stack<T, Container> &rhs)
	{
		if (lhs == rhs)
			return	false;
		return	lhs._container < rhs._container;
	}

	template <class T, class Container>
	bool	operator<=(const stack<T, Container> &lhs, const	stack<T, Container> &rhs)
	{
		if (lhs == rhs)
			return	true;
		return	lhs < rhs;
	}
	
	template <class T, class Container>
	bool	operator>(const stack<T, Container> &lhs, const	stack<T, Container> &rhs)
	{
		if (lhs == rhs)
			return	false;
		return	!(lhs < rhs);
	}

	template <class T, class Container>
	bool	operator>=(const stack<T, Container> &lhs, const	stack<T, Container> &rhs)
	{
		if (lhs == rhs)
			return	true;
		return	!(lhs < rhs);
	}
}

#endif
