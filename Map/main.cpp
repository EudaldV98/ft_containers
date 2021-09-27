/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:32:08 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/27 17:55:52 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <map>
# include <iostream>
# include "map.hpp"

int main(void)
{
    // ft::map<char, int> map;
	
	// map.insert(ft::make_pair('a', 1));
	// //map['b'] = 2;
	// ft::map<char, int>::iterator it = map.begin();
	// //it++;
	// std::cout << map.begin()->first << std::endl;
	ft::map<char, int> m;
	m.insert(ft::make_pair('m', 1));
	m.insert(ft::make_pair('b', 2));
	m.insert(ft::make_pair('p', 3));
	m.insert(ft::make_pair('j', 4));
	m.insert(ft::make_pair('q', 5));
	m.insert(ft::make_pair('l', 6));
	m.insert(ft::make_pair('o', 7));

	m.erase('l');
	m.erase('j');
	m.erase('b');
	m.erase('q');
	m.erase('o');
	m.erase('p');
	m.erase('m');

	for (ft::map<char, int>::iterator it = m.begin(); it != m.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}

	// ft::map<char, int>::iterator it = m.end();
	// it--;
	// std::cout << it->first << std::endl;
    return 0;
}

