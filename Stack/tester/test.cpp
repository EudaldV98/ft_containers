#include "../stack.hpp"
#include "../../Vector/vector.hpp"

int		main(void)
{
	ft::vector<int>		l(2,42);
	ft::stack<int>		s(l);
	ft::stack<int>		s2(l);



	l.push_back(41);
	s2.push(41);
	std::cout << "stack size : " << s.size() << std::endl;
	s.push(43);
	std::cout << " == : " << std::boolalpha << (s == s2) << std::endl;
	std::cout << " != : " << std::boolalpha << (s != s2) << std::endl;
	std::cout << " < : " << std::boolalpha << (s < s2) << std::endl;
	std::cout << " <= : " << std::boolalpha << (s2 <= s2) << std::endl;
	std::cout << " > : " << std::boolalpha << (s > s2) << std::endl;
	std::cout << " >= : " << std::boolalpha << (s >= s2) << std::endl;
	while (!s.empty())
 	{
     std::cout << ' ' << s.top();
     s.pop();
  	}
	std::cout << std::endl;

	return (0);
}