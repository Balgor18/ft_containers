#include "RBT.hpp"
#include "RBT_iterator.hpp"

int	main()
{
	ft::Red_black_tree<int>	test;

	test.print();
	test.insert(4);
	test.print();
	// ft::RBT_iterator<int>	test_iterator(test.get_root(), test.get_nil());
	// std::cout << "test.begin() " << test_iterator.begin() << std::endl;
	test.insert(2);
	test.insert(3);
	test.insert(5);
	test.insert(6);
	test.insert(7);
	test.insert(8);
	test.insert(9);
	test.print();

	return EXIT_SUCCESS;
}