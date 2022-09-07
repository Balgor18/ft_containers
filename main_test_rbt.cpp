#include "RBT.hpp"

template<typename T>
void is_find(ft::Red_black_tree<T> rb, T to_find) {
	std::cout << "is " << to_find << " is in rbtree" << std::endl;
	if (rb.find(to_find) )
		std::cout << " yessss" << std::endl;
	else
		std::cout << "  nooo" << std::endl;

}

int	main()
{
/*	ft::Red_black_tree<int>	test;

	test.print();
	test.insert(4);
	test.print();
	test.insert(14);
	test.insert(2);
	test.insert(3);
	test.insert(5);
	test.insert(6);
	test.insert(7);
	test.insert(8);
	test.insert(9);
	test.print();
	*/

	ft::Red_black_tree<char> victor;

	victor.insert('b');
	victor.insert('m');
	victor.insert('d');
	victor.insert('c');
	victor.insert('i');
	victor.insert('h');
	victor.insert('g');
	victor.insert('x');
	victor.insert('y');
	victor.insert('z');
	victor.insert('a');
	victor.print();
	is_find(victor, ' ');
	is_find(victor, 'a');
	is_find(victor, 'b');
	is_find(victor, 'c');
	is_find(victor, 'd');
	is_find(victor, 'm');
	is_find(victor, 'i');
	is_find(victor, 'h');
	is_find(victor, 'g');
	is_find(victor, 'w');
	is_find(victor, 't');
	

	// tree.insert(14);
	return EXIT_SUCCESS;
}