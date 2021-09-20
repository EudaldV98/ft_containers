/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 12:39:21 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/20 12:41:44 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STACK_HPP
# define STACK_HPP

# include "../Vector/vector.hpp"

namespace ft
{
	template <class T, class Container = vector<T> >
	class stack
	{
		public:

			typedef typename vector<T>::value_type	value_type;
			typedef	typename vector<T>::size_type	size_type;
			typedef Container	container_type;

		private:

			container_type _container;

		public:

			explicit stack(const container_type &ctnr = container_type()): _container(ctnr)
			{
			}

			stack(stack const &src)
			{
				_container = src._container;
			}
			
			stack &operator=(stack const &src)
			{
				_container = src._container;
				return *this;
			}

			virtual ~stack()
			{
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
			friend bool	operator!=(const stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);

			template <class T2, class Cntr>
			friend bool operator<(const	stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);

			template <class T2, class Cntr>
			friend bool operator<=(const stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);

			template <class T2, class Cntr>
			friend bool operator>(const	stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);

			template <class T2, class Cntr>
			friend bool operator>=(const	stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)	{
		return (lhs._container == rhs._container);
	}
	
	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container != rhs._container);
	}
	
	template <class T, class Container>
	bool operator<  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container < rhs._container);
	}
	
	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container <= rhs._container);
	}
	
	template <class T, class Container>
	bool operator>  (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs._container > rhs._container);
	}
	
	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		  return (lhs._container >= rhs._container);
	  }
}

#endif