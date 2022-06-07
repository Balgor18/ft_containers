#include "stack.hpp"
#include <vector>
#include <deque>

void	constructor_test(){
	std::deque<int> mydeque (3,100);
	std::vector<int> myvector (2,200);
	ft::stack<int> first;
	ft::stack<int,std::vector<int> > third;
	ft::stack<int,std::vector<int> > fourth (myvector);

	std::cout << "size of first: " << first.size() << '\n';
	std::cout << "size of third: " << third.size() << '\n';
	std::cout << "size of fourth: " << fourth.size() << '\n';
}

void	push_and_pop_test(){
	ft::stack<int> mystack;
	int sum (0);

	for (int i=1;i<=10;i++) mystack.push(i);
	while (!mystack.empty())
	{
		sum += mystack.top();
		mystack.pop();
	}
	std::cout << "total: " << sum << '\n';
}

void	size_test(){
	ft::stack<int> myints;

	std::cout << "0. size: " << myints.size() << '\n';
	for (int i=0; i<5; i++) myints.push(i);
	std::cout << "1. size: " << myints.size() << '\n';
	myints.pop();
	std::cout << "2. size: " << myints.size() << '\n';
}

void	top_test(){
	ft::stack<int> mystack2;

	mystack2.push(10);
	mystack2.push(20);
	mystack2.top() -= 5;
	std::cout << "mystack2.top() is now " << mystack2.top() << '\n';
}


int main ()
{
	std::cout << "Constructor stack" << std::endl;
	constructor_test();
	std::cout << "##################" << std::endl;
	std::cout << "push and pop stack" << std::endl;
	push_and_pop_test();
	std::cout << "##################" << std::endl;
	std::cout << "size stack" << std::endl;
	size_test();
	std::cout << "##################" << std::endl;
	std::cout << "top stack" << std::endl;
	top_test();
	std::cout << "##################" << std::endl;
	return 0;
}
