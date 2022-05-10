#include <stack>
#include "Stack.hpp"
#include <iostream>
#include <algorithm>

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