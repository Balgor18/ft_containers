#include <stack>
#include <vector>
// #include "Stack.hpp"
#include "vector.hpp"
#include <iostream>
#include <algorithm>
#include "iterator.hpp"
#include <string>

#define TESTED_TYPE int
#define TESTED_NAMESPACE ft
#define T_SIZE_TYPE typename TESTED_NAMESPACE::vector<T>::size_type

template <typename T>
void	printSize(TESTED_NAMESPACE::vector<T> const &vct, bool print_content = true)
{
	const T_SIZE_TYPE size = vct.size();
	const T_SIZE_TYPE capacity = vct.capacity();
	const std::string isCapacityOk = (capacity >= size) ? "OK" : "KO";
	// Cannot limit capacity's max value because it's implementation dependent

	std::cout << "size: " << size << std::endl;
	std::cout << "capacity: " << isCapacityOk << std::endl;
	std::cout << "max_size: " << vct.max_size() << std::endl;
	if (print_content)
	{
		typename TESTED_NAMESPACE::vector<T>::const_iterator it = vct.begin();
		typename TESTED_NAMESPACE::vector<T>::const_iterator ite = vct.end();
		std::cout << std::endl << "Content is:" << std::endl;
		for (; it != ite; ++it)
			std::cout << "- " << *it << std::endl;
	}
	std::cout << "###############################################" << std::endl;
}

int		main(void)
{
	const int size = 5;
	TESTED_NAMESPACE::vector<TESTED_TYPE> vct(size);
	TESTED_NAMESPACE::vector<TESTED_TYPE>::reverse_iterator it = vct.rbegin();
	TESTED_NAMESPACE::vector<TESTED_TYPE>::const_reverse_iterator ite = vct.rbegin();

	for (int i = 0; i < size; ++i)
		it[i] = (size - i) * 5;

	it = it + 5;
	it = 1 + it;
	it = it - 4;
	std::cout << *(it += 2) << std::endl;
	std::cout << *(it -= 1) << std::endl;

	*(it -= 2) = 42;
	*(it += 2) = 21;

	std::cout << "const_ite +=/-=: " << *(ite += 2) << " | " << *(ite -= 2) << std::endl;

	std::cout << "(it == const_it): " << (ite == it) << std::endl;
	std::cout << "(const_ite - it): " << (ite - it) << std::endl;
	std::cout << "(ite + 3 == it): " << (ite + 3 == it) << std::endl;

	printSize(vct, true);
	return (0);
}










// STACK MAIN

// int	main(void)
// {
// 	std::stack<int>	real;
// 	ft::stack<int>	mind;

// 	std::cout << "Est ce vide ?" << std::endl;
// 	std::cout << "real = " << real.empty() << std::endl;
// 	std::cout << "mind = " << mind.empty() << std::endl;

// 	std::cout << "Je push 5" << std::endl;
// 	real.push(5);
// 	mind.push(5);

// 	std::cout << "Est ce vide ?" << std::endl;
// 	std::cout << "real = " << real.empty() << std::endl;
// 	std::cout << "mind = " << mind.empty() << std::endl;

// 	std::cout << "Je push 6" << std::endl;
// 	real.push(6);
// 	mind.push(6);

// 	std::cout << "Je push 7" << std::endl;
// 	real.push(7);
// 	mind.push(7);

// 	std::cout << "Qu'elle est mon top ?" << std::endl;
// 	std::cout << "real = " << real.top() << std::endl;
// 	std::cout << "mind = " << mind.top() << std::endl;

// 	std::cout << "J'utilise pop" << std::endl;
// 	real.pop();
// 	mind.pop();

// 	std::cout << "Qu'elle est mon top ?" << std::endl;
// 	std::cout << "real = " << real.top() << std::endl;
// 	std::cout << "mind = " << mind.top() << std::endl;

// 	std::cout << "Combien j'ai d'elem ?" << std::endl;
// 	std::cout << "real = " << real.size() << std::endl;
// 	std::cout << "mind = " << mind.size() << std::endl;

// 	return (EXIT_SUCCESS);
// }

// int main()
// {
// 	std::stack<float>								other_stack;
// 	std::vector<std::string>							lst;

// 	lst.push_back("salut");
// 	lst.push_back("tu vas bien?");
// 	lst.push_back("super");
// 	lst.push_back("et toi?");

// 	std::stack<std::string, std::vector<std::string> >	my_stack(lst);

// 	std::cout << std::boolalpha << other_stack.empty() << std::endl;
// 	other_stack.push(8.5); // 8.5;
// 	other_stack.push(42.4242); // 8.5; 42.4242;
// 	std::cout << other_stack.size() << '\n'; // 2
// 	other_stack.pop(); // 8.5;
// 	std::cout << other_stack.size() << '\n'; // 1
// 	other_stack.push(78541.987); // 8.5; 78541.987;
// 	std::cout << other_stack.size() << '\n'; // 2
// 	std::cout << other_stack.top() << '\n'; //78541.987
// 	std::cout << std::boolalpha << other_stack.empty() << std::endl;

// 	const std::string const_top = my_stack.top();

// 	std::cout << "const top: " << const_top << '\n';

// 	while (!my_stack.empty())
// 	{
// 		std::cout << my_stack.top() << '\n';
// 		my_stack.pop();
// 	}

// 	return (0);
// }

// template <class T>
// void	print(ft::vector<ft::vector<T> >& lst)
// {
// 	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			std::cout << *it2 << ' ';
// 		std::cout << '\n';
// 	}
// }

// template <class T>
// void	print(ft::vector<T>& lst)
// {
// 	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';
// }


// int main()
// {
//   ft::vector<int> first;
//   ft::vector<int> second;
//   ft::vector<int> third;

//   first.assign (7,100);             // 7 ints with a value of 100

//   ft::vector<int>::iterator it;
//   it=first.begin()+1;

//   second.assign (it,first.end()-1); // the 5 central values of first

//   int myints[] = {1776,7,4};
//   third.assign (myints,myints+3);   // assigning from array.

//   std::cout << "Size of first: " << int (first.size()) << '\n';
//   std::cout << "Size of second: " << int (second.size()) << '\n';
//   std::cout << "Size of third: " << int (third.size()) << '\n';
//   return 0;
// }

// template <class T>
// void	print(ft::vector<ft::vector<T> >& lst)
// {
// 	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			std::cout << *it2 << ' ';
// 		std::cout << '\n';
// 	}
// }

// template <class T>
// void	print(ft::vector<T>& lst)
// {
// 	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';
// }


// int main ()
// {
// 	ft::vector<int>	myvector;

// 	myvector.push_back(10);
// 	while (myvector.back() != 0)
// 		myvector.push_back ( myvector.back() - 1 );
// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size() ; i++)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	return 0;
// }

// template <class T>
// void	print(ft::vector<ft::vector<T> >& lst)
// {
// 	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			std::cout << *it2 << ' ';
// 		std::cout << '\n';
// 	}
// }

// template <class T>
// void	print(ft::vector<T>& lst)
// {
// 	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';
// }


// int main ()
// {
// 	ft::vector<int> myvector;

// 	myvector.push_back (100);
// 	myvector.push_back (200);
// 	myvector.push_back (300);

// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size(); i++)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	myvector.clear();
// 	myvector.push_back (1101);
// 	myvector.push_back (2202);

// 	std::cout << "myvector contains:";
// 	for (unsigned i=0; i<myvector.size(); i++)
// 		std::cout << ' ' << myvector[i];
// 	std::cout << '\n';

// 	return 0;
// }

// int main(void)
// {
// 		ft::vector<int>			test(3, 3);

// 	std::cout << "self assignation test\n";
// 	ft::vector<ft::vector<int> >	self_assign;
// 	ft::vector<ft::vector<int> >	*ptr = &self_assign;
// 	ft::vector<ft::vector<int> >	*ptr2 = &self_assign;

// 	self_assign.assign(4, test);
// 	*ptr = *ptr2;

// 	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
// //	self_assign = self_assign; //compiler doesn't like it!



// 	ft::vector<ft::vector<int> > JOHN;
// 	ft::vector<ft::vector<int> > BOB(5, test);
// 	std::cout << "BOB(5, test(test, 5)) : \n";
// 	for (size_t i = 0; i < BOB.size(); i++)
// 	{
// 		for (size_t j = 0; j < BOB[i].size(); j++)
// 			std::cout << BOB[i][j] << ' ';
// 		std::cout << '\n';
// 	}
// }


// int main()
// {
// 	ft::vector<int>			test(3, 3);

// 	std::cout << "self assignation test\n";
// 	ft::vector<ft::vector<int> >	self_assign;
// 	ft::vector<ft::vector<int> >	*ptr = &self_assign;
// 	ft::vector<ft::vector<int> >	*ptr2 = &self_assign;

// 	self_assign.assign(4, test);
// 	*ptr = *ptr2;

// 	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
// //	self_assign = self_assign; //compiler doesn't like it!



// 	ft::vector<ft::vector<int> > JOHN;
// 	ft::vector<ft::vector<int> > BOB(5, test);
// 	std::cout << "BOB(5, test(test, 5)) : \n";
// 	for (size_t i = 0; i < BOB.size(); i++)
// 	{
// 		for (size_t j = 0; j < BOB[i].size(); j++)
// 			std::cout << BOB[i][j] << ' ';
// 		std::cout << '\n';
// 	}
// 	ft::vector<ft::vector<int> > MIKE(BOB);

// 	// CTORs
// 	std::cout << "\nCTORS\n";
// 	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
// 	std::cout << "BOB is empty? " << BOB.empty() << '\n';

// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

// 	// RESIZE
// 	size_t	bob_resize = 2;
// 	std::cout << "\nRESIZE\n";
// 	BOB.resize(bob_resize);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

// 	size_t	mike_resize = 9;
// 	bob_resize = 0;
	
// 	BOB.resize(bob_resize);
// 	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
// 	MIKE.resize(mike_resize, test);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_resize)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_resize)
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 		{
// 			std::cout << MIKE[i][j] << ' ';
// 		}
// 	std::cout << std::endl;
// 	}

// 	// RESERVE
// 	std::cout << "\nRESERVE\n";

// 	size_t	john_reserve = 0;
// 	size_t	bob_reserve = 3;
// 	size_t	mike_reserve = 4;

// 	JOHN.reserve(john_reserve);
// 	BOB.reserve(bob_reserve);
// 	MIKE.reserve(mike_reserve);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= john_reserve)
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= bob_reserve)
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= mike_reserve)
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}

// 	//AT
// 	std::cout << "\nAT\n";
// 	try
// 	{
// 		std::cout << MIKE.at(2).front() << '\n';
// 		std::cout << MIKE.at(87).back() << '\n';
// 	}
// 	catch (std::out_of_range& oor)
// 	{
// 		(void)oor;
// 		std::cout << "OOR error caught\n";
// 	}

// 	// FRONT / BACK
// 	std::cout << "\nFRONT / BACK\n";
// 	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
// 	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

// 	//ASSIGN
// 	std::cout << "\nASSIGN\n";
// 	test.assign(3, 17);
// 	BOB.assign(3, test);

// 	//ASSIGN RANGE
// 	std::cout << "\nASSIGN RANGE\n";
// 	ft::vector<ft::vector<int> >	assign_range;
// 	assign_range.assign(8, test);
// 	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

// 	//EMPTY
// 	std::cout << "\nEMPTY\n";
// 	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
// 	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

// 	//PUSH/POP_BACK
// 	std::cout << "\nPUSH/POP_BACK\n";
// 	test.assign(2, 42);
// 	BOB.push_back(test);
// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
// 	BOB.pop_back();
// 	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

// 	//INSERT
// 	std::cout << "\nINSERT\n";
// 	ft::vector<ft::vector<int> >	insert_in_me;
// 	for (int i = 0; i < 15; i++)
// 	{
// 		ft::vector<int>	j(2, i);
// 		insert_in_me.push_back(j);
// 	}
// 	for (size_t i = 0; i < insert_in_me.size(); i++)
// 	{
// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
// 			std::cout << insert_in_me.at(i).at(j) << ' ';
// 		std::cout << '\n';
// 	}

// 	ft::vector<ft::vector<int> >::iterator	tmp;
// 	test.assign(23, 19);
// 	tmp = insert_in_me.begin() + 4;
// 	insert_in_me.insert(tmp, 8, test);
// 	for (size_t i = 0; i < insert_in_me.size(); i++)
// 	{
// 		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
// 			std::cout << insert_in_me.at(i).at(j) << ' ';
// 		std::cout << '\n';
// 	}

// 	ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
// 	std::cout << "Const it.front() : " << std::endl;
// 	std::cout << (*const_it).front() << '\n';


// 	//INSERT
// 	std::cout << "\nINSERT\n";
// 	ft::vector<ft::vector<int> >	std_insert_in_me;
// 	for (int i = 0; i < 15; i++)
// 		std_insert_in_me.push_back(test);
// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
// 		std::cout << std_insert_in_me.at(i).front() << ' ';
// 	std::cout << '\n';

// 	ft::vector<ft::vector<int> >::iterator	std_tmp;
// 	std_tmp = std_insert_in_me.begin() + 4;
// 	std_insert_in_me.insert(std_tmp, 8, test);
// 	for (size_t i = 0; i < std_insert_in_me.size(); i++)
// 		std::cout << std_insert_in_me.at(i).back() << ' ';
// 	std::cout << '\n';


// 	//INSERT RANGE
// 	std::cout << "\nINSERT RANGE\n";
// 	ft::vector<ft::vector<int> >	insert_bis;
// 	for (int i = 0; i < 7; i++)
// 	{
// 		ft::vector<int>	j(2, i * 3);
// 		insert_bis.push_back(j);
// 	}
// 	for (size_t i = 0; i < insert_bis.size(); i++)
// 		std::cout << insert_bis[i].back() << ' ';
// 	std::cout << '\n';

// 	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
// 	for (size_t i = 0; i < insert_bis.size(); i++)
// 		std::cout << insert_bis[i].back() << ' ';
// 	std::cout << '\n';


// 	//ERASE
// 	std::cout << "\nERASE\n";
// 	ft::vector<ft::vector<int> >	erase_in_me;
// 	for (int i = 0; i < 15; i++)
// 	{
// 		ft::vector<int>	j(1, i);
// 		erase_in_me.push_back(j);
// 	}
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';

// 	erase_in_me.erase(erase_in_me.begin() + 7);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';
// 	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
// 	for (size_t i = 0; i < erase_in_me.size(); i++)
// 		std::cout << erase_in_me.at(i).front() << ' ';
// 	std::cout << '\n';

// 	//SWAP
// 	std::cout << "\nSWAP\n";
// 	john_reserve = 4;
// 	JOHN.reserve(john_reserve);
// 	BOB.swap(MIKE);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}

// 	MIKE.swap(JOHN);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}

// 	//CLEAR
// 	std::cout << "\nCLEAR\n";
// 	JOHN.clear();
// 	MIKE.clear();
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}

// 	//NON MEMBER Functions
// 	std::cout << "\nNON MEMBER functions\n";
// 	swap(BOB, MIKE);
// 	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
// 	if (JOHN.capacity() >= JOHN.size())
// 		std::cout << "Capacity of JOHN is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
// 	std::cout << "Size of BOB " << BOB.size() << std::endl;
// 	if (BOB.capacity() >= BOB.size())
// 		std::cout << "Capacity of BOB is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
// 	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
// 	if (MIKE.capacity() >= MIKE.size())
// 		std::cout << "Capacity of MIKE is sufficient\n";
// 	else
// 		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
// 	for (size_t i = 0; i < MIKE.size(); i++)
// 	{
// 		for (size_t j = 0; j < MIKE[i].size(); j++)
// 			std::cout << MIKE[i][j] << ' ';
// 	std::cout << std::endl;
// 	}
	
// 	//RELATIONAL OPERATORS
// 	std::cout << "\nRELATIONAL OPERATORS\n";
// 	ft::vector<ft::vector<int> > MIKE_2(MIKE);
// 	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
// 	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

// 	std::cout << "\nReal Vector\n";
// 	ft::vector<ft::vector<int> > real;
// 	real.assign(5, test);
// 	for (ft::vector<ft::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
// 		std::cout << (*it).front() << " ";
// 	std::cout << '\n';

// 	std::cout << std::endl;
// 	return (0);
// }



// template <class T>
// void	print(ft::vector<ft::vector<T> >& lst)
// {
// 	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			std::cout << *it2 << ' ';
// 		std::cout << '\n';
// 	}
// }

// template <class T>
// void	print(ft::vector<T>& lst)
// {
// 	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';
// }
// class Awesome {

// 	public:

// 		Awesome( void ) : _n( 42 ) { std::cout << "Default constructor" << std::endl; } //should not happen too often or else there is a wrong use of allocator (which calls the copy constructor)
// 		Awesome( int n ) : _n( n ) { /*std::cout << "Int constructor" << std::endl;*/ (void)n; }
// 		Awesome( Awesome const &rhs ) : _n( 42 ) { *this = rhs;}
// 		virtual ~Awesome(void) {}

// 		Awesome &operator=( Awesome const & rhs ) { this->_n = rhs._n; return (*this); }
// 		bool operator==( Awesome const & rhs ) const { return (this->_n == rhs._n); }
// 		bool operator!=( Awesome const & rhs ) const { return (this->_n != rhs._n); }
// 		bool operator>( Awesome const & rhs ) const { return (this->_n > rhs._n); }
// 		bool operator<( Awesome const & rhs ) const { return (this->_n < rhs._n); }
// 		bool operator>=( Awesome const & rhs ) const { return (this->_n >= rhs._n); }
// 		bool operator<=( Awesome const & rhs ) const { return (this->_n <= rhs._n); }
// 		void operator+=(int rhs){ _n += rhs; }
// 		int get( void ) const { return this->_n; }

// 	private:

// 		int _n;
// };

// std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }

// template <class T>
// void	print_vector(ft::vector<T> &test)
// {
// 	// typename ft::vector<T>::iterator		beg = test.begin();
// 	// typename ft::vector<T>::iterator		end = test.end();
// 	std::cout << "size : " << test.size() << ", capacity : " << test.capacity() << std::endl;
// 	// for (typename ft::vector<T>::iterator it = beg; it != end; it++)
// 	// {
// 	// 	std::cout << *it << " ";
// 	// 	if (((it - beg) % 10 == 9) && it > beg)
// 	// 		std::cout << std::endl;
// 	// }
// 	std::cout << std::endl;
// }

// template <class T>
// void	push_pop_back_tests(void)
// {
// 	std::cout << std::endl << "PUSH BACK & POP BACK TESTS" << std::endl;
// 	ft::vector<T> test;

// 	std::cout << "Empty ? " << test.empty() << " / Capacity : " << test.capacity() << " / Size : " << test.size() << std::endl;
// 	for (size_t i = 0; i < 51; i++)
// 	{
// 		test.push_back(i);
// 		std::cout << test.size() << ": " << test.capacity() << " - ";
// 		if (!(i % 10) && i != 0)
// 			std::cout << std::endl;
// 	}
// 	print_vector<T>(test);
// 	test.pop_back();
// 	test.pop_back();
// 	test.pop_back();
// 	test.pop_back();
// 	print_vector<T>(test);
// }

// template <class T>
// void	resize_tests(void)
// {
// 	std::cout << std::endl << "RESIZE TESTS" << std::endl;
// 	ft::vector<T> test(12, 12);

// 	test.resize(72);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.resize(100);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.resize(4170);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.resize(171, 12);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.resize(62);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// }

// template <class T>
// void	insert_tests()
// {
// 	std::cout << std::endl << "INSERT TESTS" << std::endl;
// 	ft::vector<T> test(1, 1);
// 	ft::vector<T> test2(5, 5);

// 	test.insert(test.begin(), 200, 12);
// 	print_vector<T>(test);
// 	test.insert(test.begin() + 12, 200, 30);
// 	print_vector<T>(test);
// 	test.insert(test.end(), 12, 50);
// 	print_vector<T>(test);
// 	test.insert(test.end() - 1, 0, 60);
// 	print_vector<T>(test);
// 	test.insert(test.end() - 1, 1, 70);
// 	print_vector<T>(test);
// 	test.insert(test.begin() + 412, test2.begin(), test2.end());
// 	print_vector<T>(test);
// 	test.insert(test.begin() + 6, test2.begin(), test2.end());
// 	print_vector<T>(test);
// 	test.insert(test.end(), test2.begin(), test2.end());
// 	print_vector<T>(test);
// }

// template <class T>
// void	reserve_tests(void)
// {
// 	std::cout << std::endl << "RESERVE TESTS" << std::endl;
// 	ft::vector<T> test(65, 7);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(12);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(66);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(128);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(1023);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	test.reserve(10252);
// 	std::cout << "s: " << test.size() << ", c: " << test.capacity() << std::endl;
// 	try
// 	{
// 		test.reserve(test.max_size() + 1);
// 	}
// 	catch(std::length_error &le)
// 	{
// 		std::cout << "length error" << std::endl;
// 	}
// 	catch(std::exception &e)
// 	{
// 		std::cout << "error : " << e.what() << std::endl;
// 	}
// 	print_vector<T>(test);
// }


// template <class T>
// void	reverse_it_tests(void)
// {
// 	std::cout << std::endl << "REVERSE IT TESTS" << std::endl;
// 	ft::vector<T> test;
// 	for (size_t i = 0; i < 12; i++) { test.push_back(i); }
// 	typename ft::vector<T>::reverse_iterator		revbeg = test.rbegin();
// 	for (typename ft::vector<T>::reverse_iterator it = revbeg; it != test.rend(); it++)
// 	{
// 		std::cout << *it << " ";
// 		if (!((revbeg - it) % 10) && it != revbeg)
// 			std::cout << std::endl;
// 	}
// 	std::cout << *(test.rbegin() + 2) << std::endl;
// 	std::cout << *(test.rend() - 8) << std::endl;
// 	std::cout << (test.rbegin() == revbeg) << std::endl;
// 	revbeg++;
// 	std::cout << *revbeg << std::endl;
// 	std::cout << (test.rbegin() == test.rend()) << std::endl;
// 	std::cout << (test.rbegin() <= test.rbegin()) << std::endl;
// 	std::cout << (test.rbegin() < test.rend()) << std::endl;
// 	std::cout << (test.rbegin() >= test.rend()) << std::endl;
// 	revbeg += 3;
// 	std::cout << *revbeg << std::endl;
// 	std::cout << std::endl;
// }

// template <class T>
// void	erase_clear_tests(void)
// {
// 	std::cout << std::endl << "ERASE && CLEAR TESTS" << std::endl;
// 	ft::vector<T> test(31, 12);
// 	test.erase(test.begin(), test.begin() + 5);
// 	print_vector<T>(test);
// 	test.erase(test.begin() + 12, test.begin() + 16);
// 	print_vector<T>(test);
// 	test.clear();
// 	print_vector<T>(test);
// }

// void	max_size_tests(void)
// {
// 	std::cout << std::endl << "MAX SIZE TESTS" << std::endl;
// 	ft::vector<int> test(31, 12);
// 	ft::vector<std::string> test2;
// 	ft::vector<long long int> test3;
// 	ft::vector<Awesome> test4;
// 	ft::vector<unsigned int> test5(12, 340);
// 	std::cout << test.max_size() << std::endl;
// 	std::cout << test2.max_size() << std::endl;
// 	std::cout << test3.max_size() << std::endl;
// 	std::cout << test4.max_size() << std::endl;
// 	std::cout << test5.max_size() << std::endl;
// }

// void	awesome_tests(void)
// {
// 	std::cout << std::endl << "AWESOME TESTS" << std::endl;
// 	ft::vector<Awesome> test(21, 12);
// 	print_vector<Awesome>(test);
// 	ft::vector<Awesome> test2;
// 	print_vector<Awesome>(test2);
// 	test2.push_back(12);
// 	test2.push_back(8);
// 	test2.push_back(16);
// 	print_vector<Awesome>(test2);
// 	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
// 	test.assign(test2.begin(), test2.end());
// 	print_vector<Awesome>(test);
// 	test = test2;
// 	print_vector<Awesome>(test);
// 	std::cout << "SAME ?" << (test.begin() + 1 == test2.begin() + 1) << std::endl;
// 	test.insert(test.end(), test2.begin(), test2.end());
// 	print_vector<Awesome>(test);
// 	test.insert(test.begin(), test2.begin(), test2.end());
// 	test2 = test;
// 	print_vector<Awesome>(test);
// 	std::cout << "end awesome test" << std::endl;
// }

// template <class T>
// void	copy_swap_tests(void)
// {
// 	std::cout << std::endl << "COPY && SWAP TESTS" << std::endl;
// 	ft::vector<T> test;
// 	for (size_t i = 0; i < 50; i++) { test.push_back(i); }
// 	print_vector<T>(test);
// 	ft::vector<T> test_copy(test);
// 	for (size_t i = 0; i < test_copy.size(); i++) { test_copy[i] += 100; }
// 	print_vector<T>(test_copy);
// 	// ft::vector<T> test_range(test.begin() + 20, test.begin() + 30);
// 	// print_vector<T>(test_range);
// 	// test_copy.swap(test);
// 	// print_vector<T>(test);
// 	// print_vector<T>(test_copy);
// 	// test_copy.swap(test_range);
// 	// print_vector<T>(test_range);
// 	// print_vector<T>(test_copy);
// 	// test.swap(test_copy);
// 	// print_vector<T>(test);
// 	// print_vector<T>(test_copy);
// }

// int main()
// {
// 	// push_pop_back_tests<int>();
// 	// resize_tests<int>();
// 	// insert_tests<int>();
// 	// reserve_tests<int>();
// 	copy_swap_tests<int>();
// 	// reverse_it_tests<int>();
// 	// erase_clear_tests<int>();
// 	// max_size_tests();
// 	// awesome_tests();
// 	// push_pop_back_tests<Awesome>();
// 	// resize_tests<Awesome>();
// 	// insert_tests<Awesome>();
// 	// reserve_tests<Awesome>();
// 	copy_swap_tests<Awesome>();
// 	// reverse_it_tests<Awesome>();
// 	// erase_clear_tests<Awesome>();
// }


// int main ()
// {
// 	ft::vector<int> foo (3,100);   // three ints with a value of 100
// 	ft::vector<int> bar (2,200);   // two ints with a value of 200

// 	if (foo==bar) std::cout << "foo and bar are equal\n";
// 	if (foo!=bar) std::cout << "foo and bar are not equal\n";
// 	if (foo< bar) std::cout << "foo is less than bar\n";
// 	if (foo> bar) std::cout << "foo is greater than bar\n";
// 	if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
// 	if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

// 	return 0;
// }


// template <class T>
// void	print(ft::vector<ft::vector<T> >& lst)
// {
// 	for (typename ft::vector<ft::vector<T> >::iterator it = lst.begin(); it != lst.end(); it++)
// 	{
// 		for (typename ft::vector<T>::iterator it2 = it->begin(); it2 != it->end(); it2++)
// 			std::cout << *it2 << ' ';
// 		std::cout << '\n';
// 	}
// }

// template <class T>
// void	print(ft::vector<T>& lst)
// {
// 	for (typename ft::vector<T>::iterator it = lst.begin(); it != lst.end(); it++)
// 		std::cout << *it << ' ';
// 	std::cout << '\n';
// }

// int main ()
// {
// 	ft::vector<int> myvector (5);  // 5 default-constructed ints

// 	int i=0;

// 	ft::vector<int>::reverse_iterator rit = myvector.rbegin();
// 	for (; rit!= myvector.rend(); ++rit)
// 	*rit = ++i;

// 	std::cout << "myvector contains:";
// 	for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
// 	std::cout << ' ' << *it;
// 	std::cout << '\n';

// 	return 0;
// }


// END STACK MAIN

// VECTOR MAIN
// int	main(void)
// {
	// std::vector<int>	real;
	// ft::vector<int>		mind;

	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// std::cout << "real.max_size " << real.max_size() << std::endl;
	// std::cout << "mind.max_size " << mind.max_size() << std::endl;

	// std::cout << "real.empty " << real.empty() << std::endl;
	// std::cout << "mind.empty " << mind.empty() << std::endl;

	// real.push_back(5);
	// real.push_back(5);
	// real.push_back(5);
	// real.push_back(5);
	// real.push_back(5);
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// std::cout << " resize " << std::endl;
	// real.resize(2);
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;


	// mind.push_back(5);
	// mind.push_back(5);
	// mind.push_back(5);
	// mind.push_back(5);
	// mind.push_back(5);
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// std::cout << " resize " << std::endl;
	// mind.resize(2);
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// real.push_back(5);
	// real.push_back(5);

	// real.push_back(5);
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	// std::cout << " resize " << std::endl;
	// real.resize(5, 100);
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;

	// for (std::vector<int>::iterator itv = real.begin(); itv < real.end(); itv++){
	// 	std::cout << "val = " << *itv << std::endl;
	// }


	// mind.push_back(5);
	// std::cout << " resize " << std::endl;
	// mind.resize(5, 100);
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// mind.begin();
	// for (ft::vector<int>::iterator itv = mind.begin(); itv < mind.end(); itv++){
	// 	std::cout << "val = " << *itv << std::endl;
	// }



	// real.reserve(5);
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;

	// mind.reserve(5);
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;


	// real.insert(real.begin(), 1);
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	
	// mind.insert(mind.begin(), 1);
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;


	// real.clear();
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	
	// mind.clear();
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;


	// mind.push_back(5);
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// real.resize(20);
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;

	// real.push_back(5);
	// mind.push_back(5);
	// std::cout << " push 5 " << std::endl;
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// real.push_back(6);
	// mind.push_back(6);
	// std::cout << " push 6 " << std::endl;
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// real.push_back(7);
	// mind.push_back(7);
	// std::cout << " push 7 " << std::endl;
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// real.push_back(8);
	// mind.push_back(8);
	// std::cout << " push 8 " << std::endl;
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;

	// real.push_back(9);
	// mind.push_back(9);
	// std::cout << " push 9 " << std::endl;
	// std::cout << "real.capacity " << real.capacity() << std::endl;
	// std::cout << "real.size " << real.size() << std::endl;
	// std::cout << "mind.capacity " << mind.capacity() << std::endl;
	// std::cout << "mind.size " << mind.size() << std::endl;


	// std::vector<double>		real2;
	// ft::vector<double>		mind2;

	// real2.push_back(5);
	// mind2.push_back(5);
	// std::cout << "real2.capacity " << real2.capacity() << std::endl;
	// std::cout << "real2.size " << real2.size() << std::endl;
	// std::cout << "mind2.capacity " << mind2.capacity() << std::endl;
	// std::cout << "mind2.size " << mind2.size() << std::endl;
// 	return (EXIT_SUCCESS);
// }
// END VECTOR MAIN