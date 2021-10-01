/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/01 09:10:58 by jvaquer           #+#    #+#             */
/*   Updated: 2021/10/01 09:13:27 by jvaquer          ###   ########.fr       */
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

		protected:

			container_type c;

		public:

			explicit stack(const container_type &ctnr = container_type()): c(ctnr)
			{
			}

			stack(stack const &src)
			{
				c = src.c;
			}
			
			stack &operator=(stack const &src)
			{
				c = src.c;
				return *this;
			}

			virtual ~stack()
			{
			}

			bool				empty() const
			{
				return	c.empty();
			}

			size_type			size() const
			{
				return	c.size();
			}

			value_type			&top()
			{
				return	c.back();
			}

			const value_type	&top() const
			{
				return	c.back();
			}

			void				push(const value_type &val)
			{
				c.push_back(val);
			}

			void				pop()
			{
				c.pop_back();
			}

			template <class T2, class Cntr>
			friend bool	operator==(const stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);

			template <class T2, class Cntr>
			friend bool operator<(const	stack<T2, Cntr> &lhs, const stack<T2, Cntr> &rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	
	template <class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (!(lhs == rhs));
	}
	
	template <class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	
	template <class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		if (lhs == rhs)
			return true;
		return (lhs < rhs);
	}
	
	template <class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (rhs < lhs);
	}
	
	template <class T, class Container>
  	bool operator>=(const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	  {
		  if (lhs == rhs)
		  	return true;
		  return (rhs < lhs);
	  }
}

#endif