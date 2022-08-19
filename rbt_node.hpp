#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

#define BLACK 0
#define RED 1
template<typename T>
class Node{
	// typedef 
	typedef T	value_type;

	Node		*parent;
	Node		*child_left;
	Node		*child_right;
	bool		color;

	Node(const value_type& value) : value_type(value), parent(NULL), child_left(NULL), child_right(NULL), color(BLACK) {};
	Node() : value_type(), parent(NULL), child_left(NULL), child_right(NULL), color(BLACK) {};

	Node(const Node& cpy) : value_type(cpy.value_type),parent(cpy.parent), child_left(cpy.child_left), child_right(cpy.child_right), color(cpy.color) {};

	virtual ~Node();


};

#endif