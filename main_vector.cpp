/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:53:09 by jvaquer           #+#    #+#             */
/*   Updated: 2021/02/11 13:18:37 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
  
#include "srcs/Vector/Vector.hpp"
#include <vector>
#include <iostream>

int main(int argc, const char *argv[])
{
	(void)argc;
	(void) argv;

	ft::Vector<int>		v1(12, 15);
	ft::Vector<int>::iterator	begin = v1.begin() + 3;
	ft::Vector<int>::iterator	end = v1.end();
	ft::Vector<int>	v2(begin, end);
//	std::vector<int>		v1(12, 15);
//	std::vector<int>::iterator	begin = v1.begin() + 3;
//	std::vector<int>::iterator	end = v1.end();
//	std::vector<int>	v2(begin, end);

	v1.push_back(29);
	std::cout << "\t\tV1 :" << std::endl << std::endl;

	std::cout << "v1 size : " << v1.size() << std::endl;
	std::cout << "v1 value with i\n";
	for (size_t i = 0; i < v1.size(); i++)
		std::cout << "v1[" << i << "] = " << v1[i] << std::endl;
	std::cout << "v1 value with ite\n";
	for (ft::Vector<int>::iterator ite = v1.begin(); ite != v1.end(); ite++)
		std::cout << *ite << std::endl;

	v1.clear();
	std::cout << "v1 capacity : " << v1.capacity() << std::endl;
	std::cout << "v1 size : " << v1.size() << std::endl;


	std::cout << "\t\tV2 :" << std::endl << std::endl;

	std::cout << "v2 size : " << v2.size() << std::endl;
	std::cout << "v2 value with i\n";
	for (size_t i = 0; i < v2.size(); i++)
		std::cout << "v2[" << i << "] = " << v2[i] << std::endl;
	std::cout << "v2 value with ite\n";
	for (ft::Vector<int>::iterator ite = v2.begin() ;ite != v2.end(); ite++)
		std::cout << *ite << std::endl;

	std::cout << std::endl << std::endl;


	ft::Vector<int>	v3;
	ft::Vector<int> v4(12, 1);

	for (int i = 1; i <= 10 ; i++)
		v3.push_back(i);

//	v3.push_back(15);
	v3.resize(10, 100);
	v4.swap(v3);
	for (ft::Vector<int>::iterator i = v3.begin(); i != v3.end(); i++)
		std::cout  << *i << "\t";
	std::cout << "size end : " << v3.size() << std::endl;

{
  ft::Vector<int> foo (3,100);   // three ints with a value of 100
  ft::Vector<int> bar (2,200);   // two ints with a value of 200

  if (foo==bar) std::cout << "foo and bar are equal\n";
  if (foo!=bar) std::cout << "foo and bar are not equal\n";
  if (foo< bar) std::cout << "foo is less than bar\n";
  if (foo> bar) std::cout << "foo is greater than bar\n";
  if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
}

{
  ft::Vector<int> foo (3,100);   // three ints with a value of 100
  ft::Vector<int> bar (5,200);   // five ints with a value of 200

  foo.swap(bar);

  std::cout << "foo contains:";
  for (ft::Vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';

  std::cout << "bar contains:";
  for (ft::Vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
    std::cout << ' ' << *it;
  std::cout << '\n';
}
	return (0);
}
