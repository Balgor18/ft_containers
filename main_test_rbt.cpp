#include "RBT.hpp"
#include "RBT_iterator.hpp"
#include <map>
#include <iterator>
#include <algorithm>
#include <set>
#include "pair.hpp"

// int	main()
// {
// 	// ft::Red_black_tree<int>	test;

// 	ft::Red_black_tree<int>	test1(1);

// 	test1.insert(4);
// 	test1.insert(5);
// 	test1.print();

// 	ft::Red_black_tree<int>::iterator it = test1.begin();
// 	it++;
// 	test1.erase(it);

// 	std::cout << "-------------------------" << std::endl;
// 	test1.print();
// 	// std::set<int>	real;

// 	test1.insert(6);
// 	test1.insert(7);
// 	test1.insert(8);
// 	test1.insert(9);
// 	test1.print();

// 	ft::Red_black_tree<int>	test2(1);

// 	test2.insert(4);
// 	test2.insert(5);
// 	test2.print();

// 	ft::Red_black_tree<int>::iterator it2 = test2.begin();
// 	it2++;
// 	test2.erase(it2);

// 	std::cout << "-------------------------" << std::endl;
// 	test2.print();
// 	// std::set<int>	real;

// 	test2.insert(6);
// 	test2.insert(7);
// 	test2.insert(8);
// 	test2.insert(10);
// 	test2.print();

// 	if (test1 == test2)
// 		std::cout << "Egaux" << std::endl;
// 	else
// 		std::cout << "Pas egaux" << std::endl;

// 	if (test1 != test2)
// 		std::cout << "Pas egaux" << std::endl;
// 	else
// 		std::cout << "Egaux" << std::endl;

// 	// std::set<int>::iterator it;

// 	// for (it = real.begin(); it != real.end(); it++)
// 	// {
// 	// 	std::cout << *it << std::endl;
// 	// }

// 	// it = real.begin();
// 	// // it = it + 3;
// 	// std::cout << "-------------------------" << std::endl << *real.erase(it) << std::endl << "-------------------------" << std::endl;
// 	// for (it = real.begin(); it != real.end(); it++)
// 	// {
// 	// 	std::cout << *it << std::endl;
// 	// }
// 	return EXIT_SUCCESS;
// }

int	main()
{
	std::set<int>	test1;

	test1.insert(4);
	test1.insert(5);
	test1.insert(6);
	test1.insert(7);
	test1.insert(8);
	test1.insert(9);

	std::set<int>	test2;

	test2.insert(4);
	test2.insert(5);
	test2.insert(6);
	test2.insert(7);
	test2.insert(8);
	test2.insert(10);

	if (test1 == test2)
		std::cout << "Egaux" << std::endl;
	else
		std::cout << "Pas egaux" << std::endl;

	if (test1 != test2)
		std::cout << "Pas egaux" << std::endl;
	else
		std::cout << "Egaux" << std::endl;

	std::cout << "---------------------------------------------------------------" << std::endl;

	ft::Red_black_tree<int>	test10(1);

	test10.insert(4);
	test10.insert(5);
	test10.insert(6);
	test10.insert(7);
	test10.insert(8);
	test10.insert(9);
	test10.print();

	ft::Red_black_tree<int>	test20(1);

	test20.insert(4);
	test20.insert(5);
	test20.insert(6);
	test20.insert(7);
	test20.insert(8);
	test20.insert(10);
	test20.print();

	if (test10 == test20)
		std::cout << "Egaux" << std::endl;
	else
		std::cout << "Pas egaux" << std::endl;

	// if (test10 != test20)
	// 	std::cout << "Pas egaux" << std::endl;
	// else
	// 	std::cout << "Egaux" << std::endl;

	// if (test10 < test20)
	// 	std::cout << "test10 plus petit de test20" << std::endl;
	// else
	// 	std::cout << "test20 plus petit de test10 ou plus grand" << std::endl;

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