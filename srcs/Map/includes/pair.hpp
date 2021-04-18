/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 14:47:52 by jvaquer           #+#    #+#             */
/*   Updated: 2021/04/18 15:15:22 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

template <class T1, class T2>
struct Pair
{
	typedef T1		first_type;
	typedef	T2		second_type;

	T1				first;
	T2				second;

	Pair(): first(), second() {}

	Pair(const T1 &f, const T2 &s): first(f), second(s) {}

	template <class U, class V>
	Pair(const Pair<U, V> &pr):
		first(pr.first), second(pr.second) {}

	~Pair() {}

	template <typename U1, typename U2>
	Pair<T1, T2>	&operator=(const Pair<U1, U2> &other)
	{
		first = other.first;
		second = other.second;
		return	(*this);
	}

	Pair<T1, T2>	&operator=(const Pair<T1, T2> &other)
	{
		first = other.first;
		second = other.second;
		return	(*this);
	}
};

template <class T1, class T2>
Pair<T1, T2> make_pair(T1 x, T2 y)
{
	return	(Pair<T1, T2>(x, y));
}

template <class T1, class T2>
bool	operator==(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
	return	(lhs.first == rhs.first && lhs.second == rhs.second);
}

template <class T1, class T2>
bool	operator!=(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
	return	(!(lhs == rhs));
}

template <class T1, class T2>
bool	operator<(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
	return	(lhs.first < rhs.first && lhs.second < rhs.second);
}

template <class T1, class T2>
bool	operator>(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
	return	(!(lhs.first < rhs.second));
}

template <class T1, class T2>
bool 	operator<=(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
	if (lhs == rhs)
		return true;
	return	(lhs < rhs);
}

template <class T1, class T2>
bool	operator>=(const Pair<T1, T2> &lhs, const Pair<T1, T2> &rhs)
{
	if (lhs == rhs)
		return true;
	return	(lhs > rhs);
}
#endif
