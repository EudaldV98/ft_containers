/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   capacity_vector.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/08 09:22:21 by jvaquer           #+#    #+#             */
/*   Updated: 2021/07/08 09:22:26 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../vector.hpp"
#include "constant.hpp"

void	capacity_vector()
{
	// tester size() | max_size() | resize() | capacity | reserve

	std::cout << ft_vector << std::endl;

	// FT_VECTOR
	ft::vector<int>				vec(4,42);

	std::cout << COLOR_CYAN << "Test Capacity vector" << COLOR_RESET << std::endl;
	
	std::cout << COLOR_YELLOW << "vector {";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i + 1 != vec.size())
			std::cout << ", ";
		else
			std::cout << "}" << COLOR_RESET << std::endl << std::endl;
	}
	std::cout << COLOR_CYAN << "Test ft::vector size() | max_size() | resize() | capacity | reserve" \
	<< COLOR_RESET << std::endl << std::endl;
	std::cout << "vec.size() = " << vec.size() << std::endl;
	std::cout << "vec.capacity() = " << vec.capacity() << std::endl;
	vec.push_back(43);
	std::cout << "vec.push_back(43)" << std::endl;
	std::cout << "vec.size() = " << vec.size() << std::endl;
	std::cout << "vec.capacity() = " << vec.capacity() << std::endl;
	std::cout << "vec.max_size() = " << vec.max_size() << std::endl;
	vec.resize(2);
	std::cout << "vec.resize(2) | vec.size()  = " << vec.size() << std::endl;
	std::cout << "vec.capacity() = " << vec.capacity() << std::endl;
	vec.resize(6, 24);
	std::cout << "vec.resize(6, 24) | vec.size()  = " << vec.size() << std::endl;
	
	std::cout << COLOR_YELLOW << "vector {";
	for (size_t i = 0; i < vec.size(); i++)
	{
		std::cout << vec[i];
		if (i + 1 != vec.size())
			std::cout << ", ";
		else
			std::cout << "}" << COLOR_RESET << std::endl;
	}
	std::cout << "vec.empty is " << std::boolalpha << vec.empty() << std::endl;
	vec.resize(0);
	std::cout << "vec.resize(0)" << std::endl;
	std::cout << "vec.empty is " << std::boolalpha << vec.empty() << std::endl;
	vec.reserve(12);
	std::cout << "vec.reserve(12)" << std::endl;
	std::cout << "vec.capacity() = " << vec.capacity() << std::endl << std::endl;

	// STD_VECTOR
	std::vector<int>			vec1(4, 42);

	std::cout << COLOR_CYAN << "Test std::vector size() | max_size() | resize() | capacity | reserve" \
	<< COLOR_RESET << std::endl << std::endl;
	std::cout << "vec.size() = " << vec1.size() << std::endl;
	std::cout << "vec.capacity() = " << vec1.capacity() << std::endl;
	vec1.push_back(43);
	std::cout << "vec.push_back(43)" << std::endl;
	std::cout << "vec.size() = " << vec1.size() << std::endl;
	std::cout << "vec.capacity() = " << vec1.capacity() << std::endl;
	std::cout << "vec.max_size() = " << vec1.max_size() << std::endl;
	vec1.resize(2);
	std::cout << "vec.resize(2) | vec.size() = " << vec1.size() << std::endl;
	std::cout << "vec.capacity() = " << vec1.capacity() << std::endl;
	vec1.resize(6, 24);
	std::cout << "vec.resize(6, 24) | vec.size()  = " << vec1.size() << std::endl;

	std::cout << COLOR_YELLOW << "vector {";
	for (size_t i = 0; i < vec1.size(); i++)
	{
		std::cout << vec1[i];
		if (i + 1 != vec1.size())
			std::cout << ", ";
		else
			std::cout << "}" << COLOR_RESET << std::endl;
	}
	std::cout << "vec.empty is " << std::boolalpha << vec1.empty() << std::endl;
	vec1.resize(0);
	std::cout << "vec.resize(0)" << std::endl;
	std::cout << "vec.empty is " << std::boolalpha << vec1.empty() << std::endl;
	vec1.reserve(12);
	std::cout << "vec.reserve(12)" << std::endl;
	std::cout << "vec.capacity() = " << vec1.capacity() << std::endl << std::endl;
	next_test();
}