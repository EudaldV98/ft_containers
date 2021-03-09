/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_stack.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jvaquer <jvaquer@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:32:31 by jvaquer           #+#    #+#             */
/*   Updated: 2021/03/05 14:32:46 by jvaquer          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>       // std::cout
#include <deque>          // std::deque
#include <list>           // std::list
#include <stack>          // std::stack
#include "srcs/Stack/Stack.hpp"

#ifndef MODE
# define MODE ft
#endif

int main ()
{
{
	std::cout << "Test with constructor :\n";
		MODE::list<int> mydeck(3,100);        // deque with 3 elements
	MODE::list<int> mylist(2,200);         // list with 2 elements

	MODE::stack<int> first;                 // empty stack
	MODE::stack<int, MODE::list<int> > second(mydeck);       // stack initialized to copy of deque

	MODE::stack<int, MODE::list<int> > third; // empty stack with list as underlying container
	MODE::stack<int, MODE::list<int> > fourth(mylist);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of second: " << second.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}

{
	std::cout << "\nTest with empty() :\n";
	MODE::stack<int> mystack;
	int sum (0);

	mystack.empty() ? std::cout << "mystack is empty\n": std::cout << "mystack is not empty\n";
	std::cout << "fill mystack\n";
	for (int i=1;i<=10;i++) mystack.push(i);
	mystack.empty() ? std::cout << "mystack is empty\n": std::cout << "mystack is not empty\n";

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << "total: " << sum << '\n';
}

{
	std::cout << "\nTest with top() : \n";
	MODE::stack<int> mystack;

	mystack.push(77);
	mystack.push(16);


	std::cout << "mystack.top() is now " << mystack.top() << '\n';
}

{
	std::cout << "\nTest with pop() and push() :\n";

	MODE::stack<int> mystack;
	int myint;

	std::cout << "Please enter some integers (enter 0 to end):\n";

	do {
		std::cin >> myint;
		mystack.push (myint);
	} while (myint);

	std::cout << "mystack contains: ";
	while (!mystack.empty())
	{
		std::cout << ' ' << mystack.top();
		mystack.pop();
	}
	std::cout << '\n';
}

{
	std::cout << "\nTest with size() :\n";

	MODE::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';

}

{
	std::cout << "\nTest with relational operator :\n";

	MODE::stack<int>	a;
	MODE::stack<int>	b;
	MODE::stack<int>	c;

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
	std::cout << (b <= c ? "less than c\n": "not less than c\n");

	std::cout << std::endl;

	std::cout << "c is ";
	std::cout << (c > b ? "greter than b\n": "not greater than b\n");

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
