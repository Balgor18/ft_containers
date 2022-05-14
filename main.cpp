#include <stack>
#include <vector>
#include "Stack.hpp"
#include "Vector.hpp"
#include <iostream>
#include <algorithm>

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

// END STACK MAIN

// VECTOR MAIN
int	main(void)
{
	std::vector<int>	real;
	ft::vector<int>		mind;

	real.push_back(5);
	mind.push_back(5);
	std::cout << "real.capacity " << real.capacity() << std::endl;
	std::cout << "real.size " << real.size() << std::endl;
	std::cout << "mind.capacity " << mind.capacity() << std::endl;
	std::cout << "mind.size " << mind.size() << std::endl;


	// std::vector<double>		real2;
	// ft::vector<double>		mind2;

	// real2.push_back(5);
	// mind2.push_back(5);
	// std::cout << "real2.capacity " << real2.capacity() << std::endl;
	// std::cout << "real2.size " << real2.size() << std::endl;
	// std::cout << "mind2.capacity " << mind2.capacity() << std::endl;
	// std::cout << "mind2.size " << mind2.size() << std::endl;
	return (EXIT_SUCCESS);
}
// END VECTOR MAIN