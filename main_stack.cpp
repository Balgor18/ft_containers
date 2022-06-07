#include "stack.hpp"
#include <vector>
#include <deque>

int main ()
{
	std::cout << "Constructor stack" << std::endl;

	std::deque<int> mydeque (3,100);          // deque with 3 elements
	std::vector<int> myvector (2,200);        // vector with 2 elements

	ft::stack<int> first;                    // empty stack

	ft::stack<int,std::vector<int> > third;  // empty stack using vector
	ft::stack<int,std::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
	std::cout << "##################" << std::endl;

	std::cout << "push and pop" << std::endl;
	ft::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);

	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}

	std::cout << "total: " << sum << '\n';
	std::cout << "##################" << std::endl;

	std::cout << "size vector" << std::endl;
	ft::stack<int> myints;
	std::cout << "0. size: " << myints.size() << '\n';

	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';

	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
	std::cout << "##################" << std::endl;
	
	std::cout << "top stack" << std::endl;
	ft::stack<int> mystack2;

	mystack2.push(10);
	mystack2.push(20);

	mystack2.top() -= 5;

	std::cout << "mystack2.top() is now " << mystack2.top() << '\n';
	std::cout << "##################" << std::endl;

	std::cout << "push && pop stack" << std::endl;
	ft::stack<int> mystack3;
	for (int i=0; i<5; ++i) mystack3.push(i);

	std::cout << "Popping out elements...";
	while (!mystack3.empty())
	{
		std::cout << ' ' << mystack3.top();
		mystack3.pop();
	}
	std::cout << '\n';
	std::cout << "##################" << std::endl;

	return 0;
}
