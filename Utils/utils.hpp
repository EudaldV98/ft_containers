/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:00:25 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/24 15:08:41 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <memory>
#include <stdexcept>
#include <iostream>

namespace ft
{
	//-------- ENABLE_IF --------
	
	template<bool, class T = void>
	struct enable_if
	{
	};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type; 
	};

	//-------- IS_INTEGRAL --------


	template <typename T>
	struct is_integral
	{
		static const bool value = false;
	};

	template <>
	struct is_integral <bool>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <char>
	{
		static const bool value = true;	
	};

	template <>
	struct is_integral <signed char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned char>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <long long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned short>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned int>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned long>
	{
		static const bool value = true;
	};

	template <>
	struct is_integral <unsigned long long>
	{
		static const bool value = true;
	};

	template <class T>
	struct	less
	{
		bool	operator()(const T &lhs, const T &rhs) const
		{
			return lhs < rhs;
		}
	};

	//-------- PAIR CLASS --------

	template <typename Tkey, typename Tvalue>
	class	pair
	{
		public:

			Tkey	first;
			Tvalue	second;

			pair(void)
			{
			}

			template <class X, class Y>
			pair (const pair<X, Y> &p)
			{
				this->first = p.first;
				this->second = p.second;
			}

			pair(const Tkey &k, const Tvalue &v): first(k), second(v)
			{
			}

			~pair()
			{
			}

			pair	&operator=(const pair &p)
			{
				this->first = p.first;
				this->second = p.second;				
				return	*this;
			}
	};

	template <typename T1, typename T2>
	pair<T1, T2> make_pair(T1 a, T2 b)
	{
		return pair<T1, T2>(a, b);
	}

	template <typename Tkey, typename Tvalue>
	std::ostream	&operator<<(std::ostream &o, pair <Tkey, Tvalue> const &p)
	{
		std::cout << "[" << p.first << "] = " << p.second;
		return	o;
	}

	template <class T1, class T2>
	bool			operator==(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	lhs.first == rhs.first && lhs.second == rhs.second;
	}

	template <class T1, class T2>
	bool			operator!=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	!(lhs == rhs);
	}

	template <class T1, class T2>
	bool			operator<(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	lhs.first < rhs.first || (!(lhs.first < rhs.first) && lhs.second < rhs.second);
	}

	template <class T1, class T2>
	bool			operator>(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	rhs < lhs;
	}

	template <class T1, class T2>
	bool			operator<=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	!(rhs < lhs);
	}

	template <class T1, class T2>
	bool			operator>=(const pair<T1, T2> &lhs, const pair<T1, T2> &rhs)
	{
		return	!(lhs > rhs);
	}
}

#endif