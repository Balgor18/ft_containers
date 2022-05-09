
#ifndef STACK_HPP
# define STACK_HPP
# include <vector>
# include <algorithm>

namespace ft{
	template <class T, class Container = std::vector<T> > class stack{ // modif std::vector for ft::vector
		private :
			T			data;

		public :
			stack(void){};
			~stack(){};

	}
}

// https://www.guru99.com/stack-in-cpp-stl.html
// https://fr.acervolima.com/std-allocator-en-c-avec-des-exemples/#:~:text=allocator%20est%20l%27allocateur%20de,pour%20au%20moins%20n%20%C3%A9l%C3%A9ments
#endif
