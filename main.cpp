#include <stack>
#include <vector>
#include "Stack.hpp"
#include "Vector.hpp"
#include <iostream>
#include <algorithm>
#include "iterator.hpp"
// STACK MAIN

int	main(void)
{
	std::stack<int>	real;
	ft::stack<int>	mind;

	std::cout << "Est ce vide ?" << std::endl;
	std::cout << "real = " << real.empty() << std::endl;
	std::cout << "mind = " << mind.empty() << std::endl;

	std::cout << "Je push 5" << std::endl;
	real.push(5);
	mind.push(5);

	std::cout << "Est ce vide ?" << std::endl;
	std::cout << "real = " << real.empty() << std::endl;
	std::cout << "mind = " << mind.empty() << std::endl;

	std::cout << "Je push 6" << std::endl;
	real.push(6);
	mind.push(6);

	std::cout << "Je push 7" << std::endl;
	real.push(7);
	mind.push(7);

	std::cout << "Qu'elle est mon top ?" << std::endl;
	std::cout << "real = " << real.top() << std::endl;
	std::cout << "mind = " << mind.top() << std::endl;

	std::cout << "J'utilise pop" << std::endl;
	real.pop();
	mind.pop();

	std::cout << "Qu'elle est mon top ?" << std::endl;
	std::cout << "real = " << real.top() << std::endl;
	std::cout << "mind = " << mind.top() << std::endl;

	std::cout << "Combien j'ai d'elem ?" << std::endl;
	std::cout << "real = " << real.size() << std::endl;
	std::cout << "mind = " << mind.size() << std::endl;

	return (EXIT_SUCCESS);
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