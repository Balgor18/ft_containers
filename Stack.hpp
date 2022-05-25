
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
			Container	c;
		public:
			explicit stack(const Container& co= Container()) : c(co) {
			};

			bool empty() const {
				return c.empty();
			}

			size_type size() const {
				return c.size();
			}

			void push(const value_type& x) {
				c.push_back(x);
			}

			value_type& top() {
				return c.back();
			}
			const value_type& top() const {
				return c.back();
			}

			void pop() {
				c.pop_back();
			}

			template <class Tt, class Containerr>
			friend bool operator== (const stack<Tt,Containerr>& lhs, const stack<Tt,Containerr>& rhs);

			template <class Tt, class Containerr>
			friend bool operator!= (const stack<Tt,Containerr>& lhs, const stack<Tt,Containerr>& rhs);

			template <class Tt, class Containerr>
			friend bool operator<= (const stack<Tt,Containerr>& lhs, const stack<Tt,Containerr>& rhs);

			template <class Tt, class Containerr>
			friend bool operator>= (const stack<Tt,Containerr>& lhs, const stack<Tt,Containerr>& rhs);

			template <class Tt, class Containerr>
			friend bool operator< (const stack<Tt,Containerr>& lhs, const stack<Tt,Containerr>& rhs);

			template <class Tt, class Containerr>
			friend bool operator> (const stack<Tt,Containerr>& lhs, const stack<Tt,Containerr>& rhs);
	};

	template <class T, class Container>
	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c == rhs.c);
	};

	template <class T, class Container>
	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c != rhs.c);
	};

	template <class T, class Container>
	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c <= rhs.c);
	};

	template <class T, class Container>
	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c >= rhs.c);
	};

	template <class T, class Container>
	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c < rhs.c);
	};

	template <class T, class Container>
	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs) {
		return (lhs.c > rhs.c);
	};

}

#endif
