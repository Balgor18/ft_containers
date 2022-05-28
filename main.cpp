#include <stack>
#include <vector>
// #include "Stack.hpp"
#include "Vector.hpp"
#include <iostream>
#include <algorithm>
#include "iterator.hpp"
#include <string>
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


int main()
{
	ft::vector<int>			test(3, 3);

	std::cout << "self assignation test\n";
	ft::vector<ft::vector<int> >	self_assign;
	ft::vector<ft::vector<int> >	*ptr = &self_assign;
	ft::vector<ft::vector<int> >	*ptr2 = &self_assign;

	self_assign.assign(4, test);
	*ptr = *ptr2;

	std::cout << std::boolalpha << (*ptr == *ptr2) << '\n';
//	self_assign = self_assign; //compiler doesn't like it!



	ft::vector<ft::vector<int> > JOHN;
	ft::vector<ft::vector<int> > BOB(5, test);
	std::cout << "BOB(5, test(test, 5)) : \n";
	for (size_t i = 0; i < BOB.size(); i++)
	{
		for (size_t j = 0; j < BOB[i].size(); j++)
			std::cout << BOB[i][j] << ' ';
		std::cout << '\n';
	}
	ft::vector<ft::vector<int> > MIKE(BOB);

	// CTORs
	std::cout << "\nCTORS\n";
	std::cout << "Empty is empty ? " << std::boolalpha << JOHN.empty() << '\n';
	std::cout << "BOB is empty? " << BOB.empty() << '\n';

	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;

	// RESIZE
	size_t	bob_resize = 2;
	std::cout << "\nRESIZE\n";
	BOB.resize(bob_resize);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 53\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 58\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 63\n";

	size_t	mike_resize = 9;
	bob_resize = 0;
	
	BOB.resize(bob_resize);
	std::cout << "BOB is empty now ? " << BOB.empty() << '\n';
	MIKE.resize(mike_resize, test);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 86\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_resize)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 91\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_resize)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 96\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
		{
			std::cout << MIKE[i][j] << ' ';
		}
	std::cout << std::endl;
	}
	// RESERVE
	std::cout << "\nRESERVE\n";

	size_t	john_reserve = 0;
	size_t	bob_reserve = 3;
	size_t	mike_reserve = 4;

	JOHN.reserve(john_reserve);
	BOB.reserve(bob_reserve);
	MIKE.reserve(mike_reserve);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= john_reserve)
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 120\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= bob_reserve)
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 125\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= mike_reserve)
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 130\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//AT
	std::cout << "\nAT\n";
	try
	{
		std::cout << MIKE.at(2).front() << '\n';
		std::cout << MIKE.at(87).back() << '\n';
	}
	catch (std::out_of_range& oor)
	{
		(void)oor;
		std::cout << "OOR error caught\n";
	}

	// FRONT / BACK
	std::cout << "\nFRONT / BACK\n";
	std::cout << "front() of MIKE : " << MIKE.front().front() << '\n';
	std::cout << "back() of MIKE : " << MIKE.back().back() << '\n';

	//ASSIGN
	std::cout << "\nASSIGN\n";
	test.assign(3, 17);
	BOB.assign(3, test);

	//ASSIGN RANGE
	std::cout << "\nASSIGN RANGE\n";
	ft::vector<ft::vector<int> >	assign_range;
	assign_range.assign(8, test);
	assign_range.assign(BOB.begin() + 1, BOB.end() - 2);

	//EMPTY
	std::cout << "\nEMPTY\n";
	std::cout << "BOB is empty ? " << BOB.empty() << '\n';
	std::cout << "BOB at(1) : " << BOB.at(1).front() << '\n';

	//PUSH/POP_BACK
	std::cout << "\nPUSH/POP_BACK\n";
	test.assign(2, 42);
	BOB.push_back(test);
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';
	BOB.pop_back();
	std::cout << "last elem of BOB : " << BOB.back().back() << '\n';

	//INSERT
	std::cout << "\nINSERT\n";
	ft::vector<ft::vector<int> >	insert_in_me;
	for (int i = 0; i < 15; i++)
	{
		ft::vector<int>	j(2, i);
		insert_in_me.push_back(j);
	}
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	ft::vector<ft::vector<int> >::iterator	tmp;
	test.assign(23, 19);
	tmp = insert_in_me.begin() + 4;
	insert_in_me.insert(tmp, 8, test);
	for (size_t i = 0; i < insert_in_me.size(); i++)
	{
		for (size_t j = 0; j < insert_in_me.at(i).size(); j++)
			std::cout << insert_in_me.at(i).at(j) << ' ';
		std::cout << '\n';
	}

	ft::vector<ft::vector<int> >::const_iterator const_it(insert_in_me.begin());
	std::cout << "Const it.front() : " << std::endl;
	std::cout << (*const_it).front() << '\n';


	//INSERT
	std::cout << "\nINSERT\n";
	ft::vector<ft::vector<int> >	std_insert_in_me;
	for (int i = 0; i < 15; i++)
		std_insert_in_me.push_back(test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).front() << ' ';
	std::cout << '\n';

	ft::vector<ft::vector<int> >::iterator	std_tmp;
	std_tmp = std_insert_in_me.begin() + 4;
	std_insert_in_me.insert(std_tmp, 8, test);
	for (size_t i = 0; i < std_insert_in_me.size(); i++)
		std::cout << std_insert_in_me.at(i).back() << ' ';
	std::cout << '\n';


	//INSERT RANGE
	std::cout << "\nINSERT RANGE\n";
	ft::vector<ft::vector<int> >	insert_bis;
	for (int i = 0; i < 7; i++)
	{
		ft::vector<int>	j(2, i * 3);
		insert_bis.push_back(j);
	}
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';

	insert_bis.insert(insert_bis.begin() + 5, insert_in_me.begin(), insert_in_me.end());
	for (size_t i = 0; i < insert_bis.size(); i++)
		std::cout << insert_bis[i].back() << ' ';
	std::cout << '\n';


	//ERASE
	std::cout << "\nERASE\n";
	ft::vector<ft::vector<int> >	erase_in_me;
	for (int i = 0; i < 15; i++)
	{
		ft::vector<int>	j(1, i);
		erase_in_me.push_back(j);
	}
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	erase_in_me.erase(erase_in_me.begin() + 7);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';
	erase_in_me.erase(erase_in_me.begin() + 2, erase_in_me.begin() + 6);
	for (size_t i = 0; i < erase_in_me.size(); i++)
		std::cout << erase_in_me.at(i).front() << ' ';
	std::cout << '\n';

	//SWAP
	std::cout << "\nSWAP\n";
	john_reserve = 4;
	JOHN.reserve(john_reserve);
	BOB.swap(MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 272\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 277\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 282\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	MIKE.swap(JOHN);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 298\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 303\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 308\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//CLEAR
	std::cout << "\nCLEAR\n";
	JOHN.clear();
	MIKE.clear();
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 327\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 332\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 337\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}

	//NON MEMBER Functions
	std::cout << "\nNON MEMBER functions\n";
	swap(BOB, MIKE);
	std::cout << "Size of JOHN " << JOHN.size() << std::endl;
	if (JOHN.capacity() >= JOHN.size())
		std::cout << "Capacity of JOHN is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 355\n";
	std::cout << "Size of BOB " << BOB.size() << std::endl;
	if (BOB.capacity() >= BOB.size())
		std::cout << "Capacity of BOB is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 360\n";
	std::cout << "Size of MIKE " << MIKE.size() << std::endl;
	if (MIKE.capacity() >= MIKE.size())
		std::cout << "Capacity of MIKE is sufficient\n";
	else
		std::cerr << "THERE IS A PROBLEM ON LINE 365\n";
	for (size_t i = 0; i < MIKE.size(); i++)
	{
		for (size_t j = 0; j < MIKE[i].size(); j++)
			std::cout << MIKE[i][j] << ' ';
	std::cout << std::endl;
	}
	
	//RELATIONAL OPERATORS
	std::cout << "\nRELATIONAL OPERATORS\n";
	ft::vector<ft::vector<int> > MIKE_2(MIKE);
	std::cout << "MIKE and BOB are equal ? " << (MIKE == BOB) << '\n';
	std::cout << "MIKE and MIKE_2 are equal ? " << (MIKE == MIKE_2) << '\n';

	std::cout << "\nReal Vector\n";
	ft::vector<ft::vector<int> > real;
	real.assign(5, test);
	for (ft::vector<ft::vector<int> >::iterator it = real.begin(); it != real.end(); it++)
		std::cout << (*it).front() << " ";
	std::cout << '\n';

	std::cout << std::endl;
	return (0);
}

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