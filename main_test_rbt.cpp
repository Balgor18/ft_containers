#include "RBT.hpp"
#include "RBT_iterator.hpp"
#include <map>
#include <iterator>
#include <algorithm>
#include <set>
#include "pair.hpp"

int	main()
{
	// ft::Red_black_tree<int>	test;

	ft::Red_black_tree<int>	test1(1);

	test1.insert(4);
	test1.insert(5);
	test1.print();

	ft::Red_black_tree<int>::iterator it = test1.begin();
	it++;
	test1.erase(it);

	std::cout << "-------------------------" << std::endl;
	test1.print();
	// std::set<int>	real;

	// int lol = 1;
	// // for (int lol = 1; lol <= 10; lol++)
	// // {
	// 	real.insert(lol);
	// // }

	// std::set<int>::iterator it;

	// for (it = real.begin(); it != real.end(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }

	// it = real.begin();
	// // it = it + 3;
	// std::cout << "-------------------------" << std::endl << *real.erase(it) << std::endl << "-------------------------" << std::endl;
	// for (it = real.begin(); it != real.end(); it++)
	// {
	// 	std::cout << *it << std::endl;
	// }
	return EXIT_SUCCESS;
}