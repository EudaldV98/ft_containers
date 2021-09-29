#include <iostream>
#include <stdlib.h> //srand
#if 0 //CREATE A REAL STL EXAMPLE
	#include <map>
	namespace ft = std;
#else
	#include "map.hpp"
#endif

void init_map(ft::map<char, int> &m)
{
	m['f'] = 1;
	m['b'] = 2;
	m['a'] = 3;
	m['d'] = 4;
	m['c'] = 5;
	m['e'] = 6;
	m['g'] = 7;
	m['i'] = 8;
	m['h'] = 9;
}

int main () 
{
	srand(time(NULL));

	ft::map<char, int> map;
	ft::map<char, int> map2;
	ft::pair<char, int> p;

	//INSERT
	std::cout << "Map Test" << std::endl;
	std::cout << "Test Insert" << std::endl;

	init_map(map);
	std::cout << "map.size() = " << map.size() << " |TOP = " << map.rbegin()->first << " |LOWER = " << map.begin()->first << std::endl;
	std::cout << "Print data in map via iterator:" << std::endl;
	for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
	{
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
	}

	{
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
	}

	{
		std::cout << "\nAdd three first values of map into map2 with hint:" <<std::endl;
		ft::map<char, int>::iterator it = map.begin();
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
		std::cout << "Erase begin() and last member of map being: " << map.begin()->first << " and " << map.rbegin()->first << std::endl;
		map.erase(map.begin());
		map.erase(--(map.end()));
		std::cout << "Print data in map via iterator:" << std::endl;
		for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << "[" << it->first << "] = " << it->second << std::endl;
		}
		std::cout << "map.size() = " << map.size() << std::endl;
	}

	{
		ft::map<char, int>::iterator m_end = map.end();
		ft::map<char, int>::iterator it = map.begin();
		it++; it++;
		m_end--; m_end--; m_end--;
		std::cout << "Erase begin()+2 to end()-3 from map: " << it->first << " to " << m_end->first << std::endl;
		map.erase(it, m_end);
		std::cout << "Print data in map via iterator:" << std::endl;
		for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << "[" << it->first << "] = " << it->second << std::endl;
		}
		// return 0;
	}

	{
		std::cout << "Erasing " << "g" << " via key" << std::endl;
		map.erase('g');
		std::cout << "Print data in map via iterator:" << std::endl;
		for (ft::map<char, int>::iterator it = map.begin(); it != map.end(); it++)
		{
			std::cout << "[" << it->first << "] = " << it->second << std::endl;
		}
	}

	{
		std::cout << "Testing all iterator type:" << std::endl;
		ft::map<char, int>::iterator it = map.begin();
		ft::map<char, int>::const_iterator it2 = map.begin();
		ft::map<char, int>::reverse_iterator it3 = map.rbegin();
		ft::map<char, int>::const_reverse_iterator it4 = map.rbegin();
		++it; ++it2; ++it3; ++it4;
		std::cout << "[" << it->first << "] = " << it->second << std::endl;
		std::cout << "[" << it2->first << "] = " << it2->second << std::endl;
		std::cout << "[" << it3->first << "] = " << it3->second << std::endl;
		std::cout << "[" << it4->first << "] = " << it4->second << std::endl;
	}

	{
		std::cout << "Testing empty, size & clear" << std::endl;
		std::cout << "map size: " << map.size() << " empty ? " << map.empty() << std::endl;
		map.clear();
		std::cout << "map size: " << map.size() << " empty ? " << map.empty()  << std::endl;
	}
	std::cout << std::endl;

	{
		std::cout << "Testing swap & clear" << std::endl;
		init_map(map);
		ft::map<char, int> map2;
		std::cout << "Map1 size: " << map.size() << " Map2 size: " << map2.size() << std::endl;
		map.swap(map2);
		std::cout << "After swap:\n" << "Map1 size: " << map.size() << " Map2 size: " << map2.size() << std::endl << std::endl;

		init_map(map);
		map.erase('a');
		map.erase('c');
		map.erase('h');
		std::cout << "Map1 size: " << map.size() << " Map2 size: " << map2.size() << std::endl;
		map.swap(map2);
		std::cout << "After swap:\n" << "Map1 size: " << map.size() << " Map2 size: " << map2.size() << std::endl << std::endl;

		map.clear();
		map2.erase(map2.begin(), map2.end());
		std::cout << "After clear:\n" << "Map1 size: " << map.size() << " Map2 size: " << map2.size() << std::endl;
	}
	std::cout << std::endl;

	{
		init_map(map);
		std::cout << "Testing key_comp & value_comp" << std::endl;

		std::cout << "Different key: " <<  map.key_comp()('a', 'b') << ":" << map.key_comp()('b', 'a') << std::endl;
		std::cout << "Same key: " << map.key_comp()('a', 'a') << std::endl;

		ft::pair<char,int> highest = *map.rbegin();          // last element
		ft::map<char,int>::iterator it = map.begin();
		do {
			std::cout << it->first << " => " << it->second << '\n';
		} while ( map.value_comp()(*it++, highest) );
	}
	std::cout << std::endl;

	{
		std::cout << "Testing find()" << std::endl;

		ft::map<char, int>::iterator it = map.find('a');
		ft::map<char, int>::const_iterator itc = map.find('a');
		std::cout << "a " << it->second << ":" << itc->second << std::endl;

		it = map.find('c');
		itc = map.find('c');
		std::cout << "c " << it->second << ":" << itc->second << std::endl;

		it = map.find('o');
		itc = map.find('o');
		std::cout << "o " << (it == map.end()) << ":" << (itc == map.end()) << std::endl;
	}

	{
		std::cout << "Testing count()" << std::endl;

		ft::map<char, int>::size_type it = map.count('a');
		ft::map<char, int>::size_type itc = map.count('a');
		std::cout << "a " << it << ":" << itc << std::endl;

		it = map.count('c');
		itc = map.count('c');
		std::cout << "c " << it << ":" << itc << std::endl;

		it = map.count('o');
		itc = map.count('o');
		std::cout << "o " << it << ":" << itc << std::endl;
	}

	{
		std::cout << "Testing upper&lower_bound()" << std::endl;
		ft::map<char, int>::iterator itlow, itup;

		map.clear();
		map['a']=20;
		map['b']=40;
		map['c']=60;
		map['d']=80;
		map['e']=100;

		itlow = map.lower_bound('b');
		itup = map.upper_bound('d');
		std::cout << "Erase lower_bound(b) && upper_bound(d)" << std::endl;
		std::cout << "Values: " << itlow->first << " | " << itup->first << std::endl;
		map.erase(itlow,itup);
		for (ft::map<char,int>::iterator it = map.begin(); it != map.end(); ++it)
			std::cout << it->first << " => " << it->second << '\n';

		map.clear();
	}

	{
		std::cout << "Testing equal_range()" << std::endl;

		map.clear();
		map['a']=10;
		map['b']=20;
		map['c']=30;

		ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
		ret = map.equal_range('b');

		std::cout << "lower bound points to: ";
		std::cout << ret.first->first << " => " << ret.first->second << '\n';

		std::cout << "upper bound points to: ";
		std::cout << ret.second->first << " => " << ret.second->second << '\n';
	}

	{
		ft::pair<const char, int> *p;

		p = map.get_allocator().allocate(12);

		std::cout << "The allocated array has a size of " << sizeof(ft::map<char,int>::value_type)*5 << " bytes.\n";

		map.get_allocator().deallocate(p,5);
	}
	return 0;
}