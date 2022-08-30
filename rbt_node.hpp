#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#define BLACK 0
#define RED 1

template<typename T>
class Node{
	// typedef 
	typedef T	value_type;

	Node		*root;
	Node		*parent;
	Node		*child_left;
	Node		*child_right;
	bool		color;

	Node(const value_type& value) : value_type(value), root(NULL), parent(NULL), child_left(NULL), child_right(NULL), color(RED) {};
	Node() : value_type(), root(NULL),parent(NULL), child_left(NULL), child_right(NULL), color(RED) {};

	Node(const Node& cpy) : value_type(cpy.value_type), root(NULL), parent(cpy.parent), child_left(cpy.child_left), child_right(cpy.child_right), color(cpy.color) {};

	virtual ~Node();


	void	left_rotation(Node &x)
	{
		Node &y = x.child_right;

		x.child_right = y.child_left;
		if (y.child_left)
			y.child_left->parent = y;
		else if (x == x.parent->child_left)
			x.parent->child_left = y;
		else
			x.parent->child_right = y;
		y.child_left = x;
		x.parent = y;
	};

	void	rightRotate(Node &x)
	{
		Node &y = x.child_left;
	
		x.child_left = y.right;
		if (y.right != TNULL) {
			y.right->parent = x;
		}
		y.parent = x.parent;
		if (x.parent == nullptr) {
			root = y;// check the root
		} else if (x == x.parent->right) {
			x.parent->right = y;
		} else {
			x.parent->child_left = y;
		}
		y.right = x;
		x.parent = y;
	};

	void	recolor(Node &x)
	{
		if (x.color == RED)
			x.color = BLACK;
		else
			x.color = RED;
	}
};

#endif