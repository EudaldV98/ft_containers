/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:00:25 by jvaquer           #+#    #+#             */
/*   Updated: 2021/10/04 15:24:52 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <memory>
#include <stdexcept>
#include <iostream>

namespace ft
{
	//-------- NODE -----------

	template <class T>
	struct node
	{
		public:

			typedef T 	value_type;

			node		*parent;
			node		*left;
			node		*right;
			value_type	*value;

			node(void)
			{
				parent = NULL;
				left = NULL;
				right = NULL;
				value = NULL;
			}

			node(value_type *val)
			{
				value = val;
				parent = NULL;
				left = NULL;
				right = NULL;
			}
	};

	//-------- LEXICO -----------

	template <class InputIt, class InputIt2>
	bool lexicographical_compare(InputIt first1, InputIt last1, InputIt2 first2, InputIt2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return first2 != last2;
	}

	template <class InputIt, class InputIt2, class Compare>
	bool lexicographical_compare(InputIt first1, InputIt last1, InputIt2 first2, InputIt2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || comp(*first2, *first1))
				return false;
			else if (comp(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return first2 != last2;
	}

	//-------- EQUAL ------------

	template <class InputIt, class InputIt2>
	bool equal(InputIt first1, InputIt last1, InputIt2 first2)
	{
		while (first1 !=last1)
		{
			if (*first1 != *first2)
				return false;
			first1++;
			first2++;
		}
		return true;
	}

	template <class InputIt, class InputIt2, class BinaryPredicate>
	bool equal(InputIt first1, InputIt last1, InputIt2 first2, BinaryPredicate binary_pred)
	{
		while (first1 != last1)
		{
			if (!binary_pred(*first1, *first2))
				return false;
			first1++;
			first2++;
		}
		return true;
	}

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

	template <class Tkey, class Tvalue>
	class	pair
	{
		public:

			Tkey	first;
			Tvalue	second;

			pair(void): first(), second()
			{
			}

			template <class X, class Y>
			pair (const pair<X, Y> &p): first(p.first), second(p.second)
			{
			}

			pair(const Tkey &k, const Tvalue &v): first(k), second(v)
			{
			}

			~pair()
			{
			}

			pair	&operator=(const pair &p)
			{
				first = p.first;
				second = p.second;				
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