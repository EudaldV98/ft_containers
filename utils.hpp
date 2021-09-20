/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 10:00:25 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/20 18:10:21 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_HPP
# define UTILS_HPP

#include <memory>
#include <stdexcept>
#include <iostream>

namespace ft
{
	template<bool, class T = void>
	struct enable_if
	{
	};

	template<class T>
	struct enable_if<true, T>
	{
		typedef T type; 
	};

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
}

#endif