/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/24 16:32:08 by jvaquer           #+#    #+#             */
/*   Updated: 2021/09/26 22:15:18 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <map>
# include <iostream>

int main(void)
{
    std::map<char, int> map;
	std::map<char, int> map2;
	std::map<char, int>::iterator it;
	std::pair<char, int> p;

	char tab[] = "zhmegfncsxd";
	std::cout << "Insert 11 elements into map" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		p.first = tab[i];
		p.second = i + 1;
		std::cout << "map.insert(" << p.first << "/" << p.second << ")" << std::endl;
		map.insert(p);
	}
	std::cout << "map.size() = " << map.size() << std::endl;

	std::cout << "\nErase node with one child at head. Value 'z'" << std::endl;
	map.erase('z');
	std::cout << "Print data in map via iterator:" << std::endl;
	for (std::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map.size() << std::endl;

	std::cout << "Erase leaf (No children) value 'd'" << std::endl;
	map.erase('d');
	std::cout << "Print data in map via iterator:" << std::endl;
	for (std::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map.size() << std::endl;

	std::cout << "Erase node with 2 children value 'e'" << std::endl;
	map.erase('e');
	std::cout << "Print data in map via iterator:" << std::endl;
	for (std::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map.size() << std::endl;

	std::cout << "Erase begin() of map being: " << map.begin()->first << std::endl;
	map.erase(map.begin());
	std::cout << "Print data in map via iterator:" << std::endl;
	for (std::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map.size() << std::endl;

	std::map<char, int>::iterator m_end = map.end();
	std::cout << "LOL: " << map.end()->second << std::endl;
	it = map.begin();
	it++; it++;
	m_end--; m_end--; m_end--;
	std::cout << "Erase begin()+2 to end()-1 from map: " << it->first << " to " << m_end->first << std::endl;
    return 0;
}

