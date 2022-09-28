#include <set>
#include "set.hpp"

template <class T>
void	print(ft::set<T>& lst)
{
	for (typename ft::set<T>::iterator it = lst.begin(); it != lst.end(); it++)
		std::cout << it->first << " => " << it->second << '\n';
}

int main ()
{
	int myints[]={12,75,10,32,20,25};
	ft::set<int> first (myints,myints+3);     // 10,12,75
	ft::set<int> second (myints+3,myints+6);  // 20,25,32

	ft::swap(first,second);

	std::cout << "first contains:";
	for (ft::set<int>::iterator it=first.begin(); it!=first.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	std::cout << "second contains:";
	for (ft::set<int>::iterator it=second.begin(); it!=second.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	return 0;
}