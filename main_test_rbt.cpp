#include "RBT.hpp"
#include "RBT_iterator.hpp"
#include <map>
#include <iterator>
#include <algorithm>
#include <set>

int	main()
{
	ft::Red_black_tree<int>	test;

	ft::Red_black_tree<const int>	test1(1);

	test1.insert(4);
	test1.insert(5);
	test1.print();

	ft::Red_black_tree<int>::const_iterator	test_iterator = test1.begin();
	std::cout << "test_iterator " << *test_iterator << std::endl;
	test_iterator++;
	std::cout << "test_iterator " << *test_iterator << std::endl;
	test_iterator++;
	std::cout << "test_iterator " << *test_iterator << std::endl;
	test_iterator++;
	std::cout << "test_iterator " << *test_iterator << std::endl;

	test1.find(5);
	// test.insert(2);
	// test.insert(3);
	// test.insert(5);
	// test.insert(6);
	// test.insert(7);
	// test.insert(8);
	// test.insert(9);
	// test.print();

	return EXIT_SUCCESS;
}