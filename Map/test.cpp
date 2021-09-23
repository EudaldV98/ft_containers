#include <map>
#include "map.hpp"
#include <vector>
#include <iostream>
#include "../utils.hpp"

int main () 
{
	srand(time(NULL));
{
	ft::map<char, int> map;
	ft::map<char, int> map2;
	ft::pair<char, int> p;

	//INSERT
	std::cout << "Map Test" << std::endl;
	std::cout << "Test Insert" << std::endl;
	char c = 'a';

	for (int i = 1; i < 11; i++)
	{
		p.first = c++;
		p.second = i;
		std::cout << "map.insert(" << p << ")" << std::endl;
		map.insert(p);
	}
	std::cout << "map.size() = " << map.size() << std::endl;
	std::cout << "Print data in map via iterator:" << std::endl;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}

	ft::map<char, int>::iterator it = map.begin();
	it++;
	it++;
	it++;
	std::cout << "\nAdd values in map2 with range iterator:" << std::endl;
	map2.insert(it, map.end());
	std::cout << "Print data in map2 via iterator:" << std::endl;
	for (ft::map<char, int>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map2.size() << std::endl;

	std::cout << "\nAdd three first values of map into map2 with hint:" <<std::endl;
	it = map.begin();
	ft::map<char, int>::iterator it2 = map2.begin();
	for (int i = 0; i < 3; i++)
	{
		map2.insert(it2, *it);
		it++;
		it2 = map2.begin();
		it2++;
	}
	std::cout << "Print data in map2 via iterator:" << std::endl;
	for (ft::map<char, int>::iterator it = map2.begin(); it != map2.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map2.size() << std::endl;
}
{
	ft::map<char, int> map;
	ft::map<char, int> map2;
	ft::map<char, int>::iterator it;
	ft::pair<char, int> p;

	char tab[] = "zhmegfncsxd";
	std::cout << "Insert 11 elements into map" << std::endl;
	for (int i = 0; i < 11; i++)
	{
		p.first = tab[i];
		p.second = i + 1;
		std::cout << "map.insert(" << p << ")" << std::endl;
		map.insert(p);
	}
	std::cout << "map.size() = " << map.size() << std::endl;

	std::cout << "\nErase node with one child at head. Value 'z'" << std::endl;
	map.erase('z');
	std::cout << "Print data in map via iterator:" << std::endl;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map.size() << std::endl;

	std::cout << "Erase leaf (No children) value 'd'" << std::endl;
	map.erase('d');
	std::cout << "Print data in map via iterator:" << std::endl;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map.size() << std::endl;

	std::cout << "Erase node with 2 children value 'e'" << std::endl;
	map.erase('e');
	std::cout << "Print data in map via iterator:" << std::endl;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}
	std::cout << "map.size() = " << map.size() << std::endl;
}
	return 0;
}