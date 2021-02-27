/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_list.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/27 12:48:55 by jvaquer           #+#    #+#             */
/*   Updated: 2021/02/27 12:52:13 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "includes/BidirectionalIterator.hpp"
# include "includes/ReverseBidirectionalIterator.hpp"
# include "srcs/List/List.hpp"
# include <list>
# include <cmath>

#ifndef MODE
# define MODE ft
#endif

// a predicate implemented as a function:
bool single_digit (const int& value) { return (value<10); }

// a predicate implemented as a class:
struct is_odd {
	bool operator() (const int& value) { return (value%2)==1; }
};

struct is_even {
	bool operator() (const int& value) { return (value%2)==0; }
};

bool compare_nocase (const std::string& first, const std::string& second)
{
	unsigned int i=0;
	while ( (i<first.length()) && (i<second.length()) )
	{
		if (tolower(first[i])<tolower(second[i])) return true;
		else if (tolower(first[i])>tolower(second[i])) return false;
		++i;
	}
	return ( first.length() < second.length() );
}

// compare only integral part:
bool mycomparison (double first, double second)
{ return ( int(first) >int(second) ); }

// a binary predicate implemented as a function:
bool same_integral_part (double first, double second)
{ return ( int(first)==int(second) ); }

// a binary predicate implemented as a class:
struct is_near {
	bool operator() (double first, double second)
	{ return (fabs(first-second)<5.0); }
};

int main(int argc, const char *argv[])
{
	(void)argv;
	(void)argc;
{
	MODE::list<int>	lst(4, 12);
	MODE::list<int>	lst2(7);
	MODE::list<int>	lst3;
	MODE::list<int>::iterator		ite = lst.begin();

	std::cout << "Lst2 = lst\n";
	lst2 = lst;
	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	std::cout << "Push 16, 24, 32, 48 in lst3\n";
	lst3.push_back(16);
	lst3.push_back(24);
	lst3.push_back(32);
	lst3.push_back(48);
	std::cout << "Front value in lst3 is " << lst3.front() << std::endl;
	std::cout << "Back value in lst3 is " << lst3.back() << std::endl;

	lst3.clear();
	std::cout << "list with four 12\n";
	std::cout << "push_back 16 in the list\n";
	lst.push_back(16);
	ite++;
	ite++;
	std::cout << "Insert three 1 after the second value\n";
	lst.insert(ite, 3, 1);


	MODE::list<int>::iterator		test = lst.begin();
	while (test != lst.end())
		test++;
	test++;
	std::cout << "\nTry to print with boucle it\n";
	while (test != lst.end())
	{
		std::cout << *test << "\t";
		test++;
	}
	std::cout << "\nsuccess\n";

	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << "\t";
	std::cout << std::endl;

	std::cout << "push 48\n";
	lst.push_back(48);
	std::cout << "back = " << lst.back() << std::endl;

	std::cout << "front = " << lst.front() << std::endl;

	std::cout << "lst size = " << lst.size() << std::endl;
	std::cout << "lst3 size = " << lst3.size() << std::endl;

	std::cout << "lst max_size = " << lst3.max_size() << std::endl;

	std::cout << (lst.empty() ? "lst is empty\n" : "lst is not empty\n");
	std::cout << (lst3.empty() ? "lst3 is empty\n" : "lst3 is not empty\n");

	std::cout << "lst size = " << lst.size() << std::endl;
	std::cout << "Clear lst\n";
	lst.clear();
	std::cout << "lst size = " << lst.size() << std::endl;
	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;
}

{
	std::cout << "Assign test\n\n";
	MODE::list<int>	lst(4, 12);

	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << std::endl;

	MODE::list<int> test(2, 600);
	MODE::list<int>::iterator start = test.begin(), end = test.end();
	for (int i = 0; i < 6; i++)
		start++;

	std::cout << "Assign two value of 600 with iterator\n";
	lst.assign(start, end);
	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "Assign eight value of 90 with size\n";
	lst.assign(8, 90);
	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nCreate list with iterator\n";
	MODE::list<int>	with_it(start, end);
	for (MODE::list<int>::iterator it = with_it.begin(); it != with_it.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;

	std::cout << "\nCreate list with copy of lst\n";
	MODE::list<int>	copy(lst);
	for (MODE::list<int>::iterator it = copy.begin(); it != copy.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

{
	std::cout << "\nErase test :\n";
	MODE::list<int>				lst;
	MODE::list<int>::iterator		it;

	std::cout << "Create list with values 0 to 9\n";
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	it = lst.begin();
	for (int i = 0; i < 7; i++)
		it++;
	std::cout << "Erase the value " << *it << std::endl;
	lst.erase(it);
	for (MODE::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << " ";
	std::cout << std::endl;

	std::cout << "Erase value 0 to 4\n";
	MODE::list<int>::iterator ite = lst.begin();
	for (int i = 0; i < 5; i++)
		ite++;
	lst.erase(lst.begin(), ite);
	for (MODE::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << " ";
	std::cout << std::endl;
}

{
	std::cout << "\nInsert test\n";
	MODE::list<int>			lst;
	MODE::list<int>::iterator	it;

	std::cout << "Create list with values 0 to 9\n";
	for (int i = 0; i < 10; i++)
		lst.push_back(i);
	it = lst.begin();
	it++;
	it++;
	std::cout << "Insert value 99 before the third value\n";
	lst.insert(it, 99);
	for (MODE::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << "\t";
	std::cout << std::endl;

	std::cout << "Insert three value of 1000 before the first value\n";
	MODE::list<int>::iterator		t = lst.begin();
	lst.insert(t, 3, 1000);
	for (MODE::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << "\t";
	std::cout << std::endl;

	std::cout << "Insert value with iterator 96 to 99 before the fourth value\n";
	MODE::list<int>		test;
	for (int i = 90; i < 100; i++)
		test.push_back(i);
	MODE::list<int>::iterator		it_test = test.begin();
	it++;
	it++;
	for (int x = 0; x < 6; x++)
		it_test++;
	lst.insert(it, it_test, test.end());
	for (MODE::list<int>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << *ite << "\t";
	std::cout << std::endl;

}

{
	std::cout << "\nPop/push  back/front test :\n\n";

	MODE::list<int>	lst;

	for (int i = 0; i < 5; i++)
		lst.push_back(i);
	lst.push_back(100);
	std::cout << "Initial value of lst : ";
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Pop back 2 times\n";
	lst.pop_back();
	lst.pop_back();
//	lst.insert(lst.begin(), 4, 12);
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << "\nPop front 2 times\n";
	lst.pop_front();
	lst.pop_front();
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";

	std::cout << "\nPush front values 0 to 8\n";
	for (int i = 0; i < 9; i++)
		lst.push_front(i);
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
}

{
	std::cout << "\n\nTest with remove\n";

	MODE::list<int>		lst;

	for (int i = 0; i < 10; i++)
		lst.push_back(i % 3);
	std::cout << "Initial value : ";
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Remove all value equal to 0\n";
	lst.remove(0);
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Remove all value equal to 2\n";
	lst.remove(2);
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Remove all value equal to 1\n";
	lst.remove(1);
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "size = " << lst.size() << std::endl;
}


{
	std::cout << "\nTest with remove_if :\n\n";

	MODE::list<int>	lst;

	lst.push_back(15);
	lst.push_back(36);
	lst.push_back(7);
	lst.push_back(17);
	lst.push_back(20);
	lst.push_back(39);
	lst.push_back(4);
	lst.push_back(1);
	lst.remove_if (single_digit);           // 15 36 17 20 39

	lst.remove_if (is_odd());               // 36 20

//	lst.remove_if (is_even());               // emptu

	std::cout << "mylist contains:";
	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

{
	std::cout << "\nTest with resize :\n";

	MODE::list<int>	lst;

	for (int i = 0; i < 20; i+= 2)
		lst.push_back(i);
	std::cout << "Initial value : ";
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	std::cout << "Resize 15 with _size 10\n";
	lst.resize(15, 1);
	std::cout << "size =" << lst.size() << "\t";
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;

	std::cout << "Resize 5 with _size 15\n";
	lst.resize(5, 8);
	std::cout << "size =" << lst.size() << "\t";
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
	
	std::cout << "Resize 0 with _size 5\n";
	lst.resize(0, 8);
	std::cout << "size =" << lst.size() << "\t";
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;

	std::cout << "Resize 4 with _size 0\n";
	lst.resize(4, 1);
	std::cout << "size =" << lst.size() << "\t";
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << "\t";
	std::cout << std::endl;
}

{
	std::cout << "\nTest with reverse :\n";
	
	MODE::list<int> lst;

	for (int i = 1; i <= 10; ++i)
		lst.push_back(i);
	std::cout << "Initial value : ";
	for (MODE::list<int>::iterator i = lst.begin(); i != lst.end(); i++)
		std::cout << *i << " ";
	std::cout << std::endl;

	lst.reverse();

	std::cout << "reverse lst contains:";
	for (MODE::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
		std::cout << ' ' << *it;

	std::cout << '\n';
}

{
	std::cout << "\nTest with sort :\n";

	MODE::list<std::string> lst;
	MODE::list<std::string>::iterator it;
	lst.push_back ("one");
	lst.push_back ("two");
	lst.push_back ("Three");
	lst.push_back("four");
	lst.push_back("five");
	lst.push_back("fivee");
	lst.push_back("six");
	std::cout << "Initial value : ";
	for (MODE::list<std::string>::iterator ite = lst.begin(); ite != lst.end(); ite++)
		std::cout << " " << *ite;
	std::cout << std::endl;
	lst.sort();

	std::cout << "mylist contains:";
	for (it=lst.begin(); it!=lst.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Sort with function compare_nocase\n";
	lst.sort(compare_nocase);

	std::cout << "mylist contains:";
	for (it = lst.begin(); it != lst.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

{
	std::cout << "\nTest with splice\n";
	MODE::list<int>		lst1;
	MODE::list<int>		lst2;
	MODE::list<int>::iterator	ite;

	for (int i = 0; i < 10; i++)
		lst1.push_back(i);
	for (int i = 10; i < 20; i++)
		lst2.push_back(i);
		std::cout << "Initial value :\nlst1 : ";
	for (MODE::list<int>::iterator it = lst1.begin(); it != lst1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << "\nlst2 : ";
	for (MODE::list<int>::iterator it = lst2.begin(); it != lst2.end(); ++it)
		std::cout << ' ' << *it;

	ite = lst1.begin();
	ite++;
	ite++;
	ite++;
	lst1.splice(ite, lst2);
	std::cout << "lst1 value after splice with it point to 3 :\nlst1 : ";
	for (MODE::list<int>::iterator it = lst1.begin(); it != lst1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "lst2 value after splice :\nlst2 : ";
	for (MODE::list<int>::iterator it = lst2.begin(); it != lst2.end(); ++it)
		std::cout << ' ' << *it;;
	std::cout << std::endl << std::endl;

	std::cout << "Splice value 3 in lst1 to lst2\n";
	lst2.splice (lst2.begin(), lst1, ite);
	std::cout << "lst1 value after splice with it point to 3 :\nlst1 : ";
	for (MODE::list<int>::iterator it = lst1.begin(); it != lst1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << std::endl;
	std::cout << "lst2 value after splice :\nlst2 : ";
	for (MODE::list<int>::iterator it = lst2.begin(); it != lst2.end(); ++it)
		std::cout << ' ' << *it;;
	std::cout << std::endl << std::endl;

	lst1.clear();
	lst1.push_back(1);
	lst1.push_back(10);
	lst1.push_back(20);
	lst1.push_back(30);
	lst1.push_back(3);
	lst1.push_back(4);
	ite = lst1.begin();
	for (int i = 0; i < 3; i++)
		ite++;
	std::cout << "mylist1 contains:";
	for (MODE::list<int>::iterator it = lst1.begin(); it != lst1.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
	std::cout << "Ite pointe on value " << *ite << " of lst1\n";
	lst2.splice (lst2.begin(), lst1, lst1.begin(), ite);
//	1 10 20 30 3 4
//	lst1.splice(lst1.begin(), lst1, ite, lst1.end());
//	lst1.insert(lst1.begin(), 12);
	std::cout << "mylist1 contains:";
	for (ite = lst1.begin(); ite != lst1.end(); ++ite)
		std::cout << ' ' << *ite;
	std::cout << '\n';

	std::cout << "mylist2 contains:";
	for (ite = lst2.begin(); ite != lst2.end(); ++ite)
		std::cout << ' ' << *ite;
	std::cout << '\n';;
}

{
	std::cout << "\nTest with swap\n\n";

	MODE::list<int> first (3,100);   // three ints with a value of 100
	MODE::list<int> second (5,200);  // five ints with a value of 200

	std::cout << "First BEFORE swap : ";
	for (MODE::list<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "Second BEFORE swap : ";
	for (MODE::list<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	first.swap(second);

	std::cout << "first AFTER swap:";
	for (MODE::list<int>::iterator it=first.begin(); it!=first.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << first.size();
	std::cout << '\n';

	std::cout << "second AFTER swap:";
	for (MODE::list<int>::iterator it=second.begin(); it!=second.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << second.size();
	std::cout << '\n';

	std::cout << "\nWith 2 empty list\n";
	MODE::list<int> lst1;   // three ints with a value of 100
	MODE::list<int> lst2;  // five ints with a value of 200

	std::cout << "lst1 BEFORE swap : ";
	for (MODE::list<int>::iterator it=lst1.begin(); it!=lst1.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "lst2 BEFORE swap : ";
	for (MODE::list<int>::iterator it=lst2.begin(); it!=lst2.end(); it++)
		std::cout << ' ' << *it;
	std::cout << '\n';
	lst1.swap(lst2);

	std::cout << "lst1 AFTER swap:";
	for (MODE::list<int>::iterator it=lst1.begin(); it!=lst1.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << lst1.size();
	std::cout << '\n';

	std::cout << "lst2 AFTER swap:";
	for (MODE::list<int>::iterator it=lst2.begin(); it!=lst2.end(); it++)
		std::cout << ' ' << *it;
	std::cout << " size = " << lst2.size();
	std::cout << '\n';
}

{
	std::cout << "\nTest with unique\n\n";

	MODE::list<double>		lst;

	lst.push_back(16.54);
	lst.push_back(16.54);
	lst.push_back(27.02);
	lst.push_back(27.02);
	lst.push_back(160.02);
	lst.push_back(2.84);
	lst.push_back(160.12);
	lst.push_back(16.54);
	lst.push_back(3.99);
	lst.push_back(16.73);
	lst.push_back(2.84);
	lst.push_back(156.12);
	lst.push_back(3.12);
	lst.push_back(19.32);

	std::cout << "Initial list value : ";
	for (MODE::list<double>::iterator it = lst.begin(); it !=lst.end(); it++)
		std::cout << "|" << *it << "| ";
	std::cout << std::endl;

	lst.sort();
	lst.unique();

	std::cout <<  "List value after unique(): ";
	for (MODE::list<double>::iterator it = lst.begin(); it !=lst.end(); it++)
		std::cout << "|" << *it << "| ";
	std::cout << std::endl;

	lst.sort();
	lst.unique(same_integral_part);

	std::cout <<  "List value after unique(same_integral_part): ";
	for (MODE::list<double>::iterator it = lst.begin(); it !=lst.end(); it++)
		std::cout << "|" << *it << "| ";
	std::cout << std::endl;

	lst.sort();
	lst.unique(is_near());

	std::cout <<  "List value after unique(is_near()): ";
	for (MODE::list<double>::iterator it = lst.begin(); it !=lst.end(); it++)
		std::cout << "|" << *it << "| ";
	std::cout << std::endl;
}

{
	std::cout << "\nTest with merge :\n\n";

	MODE::list<double> first, second;

	first.push_back (3.1);
	first.push_back (2.2);
	first.push_back (2.9);

	second.push_back (3.7);
	second.push_back (7.1);
	second.push_back (1.4);

	first.sort();
	second.sort();

	std::cout << "first contains before:";
	for (MODE::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " size = " << first.size();
	std::cout << '\n';

	std::cout << "second contains before:";
	for (MODE::list<double>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " size = " << second.size();
	std::cout << '\n';
	std::cout << '\n';
	first.merge(second);

	// (second is now empty)
	std::cout << "second contains after 1st merge:";
	for (MODE::list<double>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " size = " << second.size();
	std::cout << '\n';

	std::cout << "first contains after 1st merge:";
	for (MODE::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " size = " << first.size();
	std::cout << '\n';
	std::cout << '\n';

	second.push_back (15);
	second.push_back (5);
	second.push_back(4);

	first.clear();
	first.push_back(12.12);
	first.push_back(10.10);
	first.push_back(8.08);
	first.push_back(6.06);
	first.sort();
	second.sort();

	std::cout << "first contains before 2nd merge:";
	for (MODE::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << " size = " << first.size();
	std::cout << '\n';

	first.merge(second,mycomparison);

	std::cout << "first contains:";
	for (MODE::list<double>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}

{
	std::cout << "\nTest with relational operator\n\n";
	MODE::list<int> a;
	MODE::list<int> b;
	MODE::list<int> c;

	a.push_back(10); a.push_back(20); a.push_back(30);
	b.push_back(10); b.push_back(20); b.push_back(30);
	c.push_back(30); c.push_back(20); c.push_back(10);

	std::cout << " a = {10, 20, 30}\n";
	std::cout << " b = {10, 20, 30}\n";
	std::cout << " c = {30, 20, 10}\n\n";
	if (a==b) std::cout << "a and b are equal\n";
	if (b!=c) std::cout << "b and c are not equal\n";
	if (b<c) std::cout << "b is less than c\n";
	if (c>b) std::cout << "c is greater than b\n";
	if (a<=b) std::cout << "a is less than or equal to b\n";
	if (a>=b) std::cout << "a is greater than or equal to b\n";
}

{
	std::cout << "\nTest with overload swap\n\n";

	std::list<int> foo (3,100);   // three ints with a value of 100
	std::list<int> bar (5,200);   // five ints with a value of 200

	std::cout << "Foo = 100 100 100\n";
	std::cout << "Bar = 200 200 200 200 200\n";
	std::swap(foo,bar);

	std::cout << "foo contains:";
	for (std::list<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "bar contains:";
	for (std::list<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';
}
	return (0);
}
