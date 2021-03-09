/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_queue.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/08 11:43:09 by lucas             #+#    #+#             */
/*   Updated: 2021/02/18 16:14:04 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <queue>          // std::queue
#include "srcs/Queue/Queue.hpp"

#ifndef MODE
# define MODE ft
#endif

int main ()
{
{
	std::cout << "Test with constructor :\n";
		ft::list<int> mydeck(3,100);        // deque with 3 elements
	ft::list<int> mylist(2,200);         // list with 2 elements

	MODE::queue<int> first;                 // empty queue
	MODE::queue<int, ft::list<int> > second(mydeck);       // queue initialized to copy of deque

	MODE::queue<int, ft::list<int> > third; // empty queue with list as underlying container
	MODE::queue<int, ft::list<int> > fourth(mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}

{
	std::cout << "\nTest witn back() :\n";
	MODE::queue<int> myqueue;

	myqueue.push(12);
	myqueue.push(75);   // this is now the back

	myqueue.back() -= myqueue.front();

	std::cout << "myqueue.back() is now " << myqueue.back() << '\n';
}

{
	std::cout << "\nTest with empty() :\n";
	MODE::queue<int> myqueue;
	int sum (0);

	myqueue.empty() ? std::cout << "myqueue is empty\n": std::cout << "myqueue is not empty\n";
	std::cout << "fill myqueue\n";
	for (int i=1;i<=10;i++) myqueue.push(i);
	myqueue.empty() ? std::cout << "myqueue is empty\n": std::cout << "myqueue is not empty\n";

	while (!myqueue.empty())
	{
		sum += myqueue.front();
		myqueue.pop();
	}
	std::cout << "total: " << sum << '\n';
}

{
	std::cout << "\nTest with front() : \n";
	MODE::queue<int> myqueue;

	myqueue.push(77);
	myqueue.push(16);

	myqueue.front() -= myqueue.back();    // 77-16=61

	std::cout << "myqueue.front() is now " << myqueue.front() << '\n';
}

{
	std::cout << "\nTest with pop() and push() :\n";

	MODE::queue<int> myqueue;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		myqueue.push (myint);
	} while (myint);

	std::cout << "myqueue contains: ";
	while (!myqueue.empty())
	{
		std::cout << ' ' << myqueue.front();
		myqueue.pop();
	}
	std::cout << '\n';
}

{
	std::cout << "\nTest with size() :\n";

	MODE::queue<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

}

{
	std::cout << "\nTest with relational operator :\n";

	MODE::queue<int>	a;
	MODE::queue<int>	b;
	MODE::queue<int>	c;

	a.push(10); a.push(20); a.push(30);
	b.push(10); b.push(20); b.push(30);
	c.push(30); c.push(20); c.push(10);

	std::cout << " a = {10, 20, 30}\n";
	std::cout << " b = {10, 20, 30}\n";
	std::cout << " c = {30, 20, 10}\n\n";
	std::cout << "a and b are ";
	std::cout << (a == b ? "equal\n": "not equal\n") << std::endl;

	std::cout << "b and c are ";
	std::cout << (b != c ? "not equal\n": "equal\n") << std::endl;;

	std::cout << "b is ";
	std::cout << (b <= c ? "less than c\n": " not less than c\n");

	std::cout << std::endl;

	std::cout << "c is ";
	std::cout << (c > b ? "greater than b\n": "not greater than b\n");

	std::cout << std::endl;

	std::cout << "a is ";
	std::cout << (a <= b ? "less or equal to b\n": "not less or equal to b\n");

	std::cout <<std::endl;

	std::cout << "a is ";
	std::cout << (a >= b ? "greater or equal to b\n": "not greater or equal to b");

	std::cout << std::endl;
}

return 0;
}
