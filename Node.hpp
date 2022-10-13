#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

# define BLACK 0
# define RED 1

# include <memory>
# include <algorithm>
# include <iostream>

namespace ft {

	template<class T>
	class Node
	{
		public :
			T		data;
			Node	*parent;
			bool	color;
			Node	*child_left;
			Node	*child_right;

			// Default constructor
			Node () : data(), parent(NULL), color(RED), child_left(NULL), child_right(NULL) {}
			Node(const T &data) : data(data), parent(NULL), color(RED), child_left(NULL), child_right(NULL) {}

			// Copy constructor
			Node(const Node &cpy) : data(cpy.data), parent(cpy.parent), color(cpy.color), child_left(cpy.child_left), child_right(cpy.child_right) {}

			// Overload operator = 
			Node<T>&	operator=(const Node<T>&rhs)
			{
				if (this == &rhs)
					return (*this);
				parent = rhs.parent;
				child_left = rhs.child_left;
				child_right = rhs.child_right;
			}

			// Destructor
			~Node() {};

			void	set_parent(Node *x)
			{
				parent = x;
			}

			void	set_child_left(Node *x)
			{
				child_left = x;
			}

			void	set_child_right(Node *x)
			{
				child_right = x;
			}

			void	set_data(T *x)
			{
				data = x;
			}

			void	set_color(bool x)
			{
				color = x;
			}
	};

}

#endif