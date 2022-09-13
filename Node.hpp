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
			Node	*parent;
			Node	*child_left;
			Node	*child_right;
			T		data;
			bool	color;

			// Default constructor
			Node () : parent(NULL), child_left(NULL), child_right(NULL), data(), color(RED) {}
			Node(const T &data) : parent(NULL), child_left(NULL), child_right(NULL), data(data), color(RED) {}

			// Copy constructor
			Node(const Node &cpy) : parent(cpy.parent), child_left(cpy.child_left), child_right(cpy.child_right), data(cpy.key, cpy.value), color(cpy.color) {}

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