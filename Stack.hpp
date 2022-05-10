
#ifndef STACK_HPP
# define STACK_HPP
# include <vector>
# include <algorithm>

namespace ft {
template <class T, class Container = std::vector<T> >
	class stack {
		public:
			typedef typename Container::value_type	value_type;
			typedef typename Container::size_type	size_type;
			typedef Container						container_type;
		protected:
			Container c;
		public:
			explicit stack(const Container& = Container()) : c() {};

			bool empty() const { return c.empty(); }

			size_type size() const { return c.size(); }

			void push(const value_type& x) { c.push_back(x); }

			value_type& top() { return c.back(); }
			// const value_type& top() const { return c.back(); }

			void pop() { c.pop_back(); }
	};
	// Need to reimplement ?
	template <class T, class Container>
	bool operator==(const stack<T, Container>& x, const stack<T, Container>& y);

	template <class T, class Container>
	bool operator< (const stack<T, Container>& x, const stack<T, Container>& y);

	template <class T, class Container>
	bool operator!=(const stack<T, Container>& x, const stack<T, Container>& y);

	template <class T, class Container>
	bool operator> (const stack<T, Container>& x, const stack<T, Container>& y);

	template <class T, class Container>
	bool operator>=(const stack<T, Container>& x, const stack<T, Container>& y);

	template <class T, class Container>
	bool operator<=(const stack<T, Container>& x, const stack<T, Container>& y);
}
// https://www.guru99.com/stack-in-cpp-stl.html
// https://fr.acervolima.com/std-allocator-en-c-avec-des-exemples/#:~:text=allocator%20est%20l%27allocateur%20de,pour%20au%20moins%20n%20%C3%A9l%C3%A9ments
#endif

// https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf
// page 485