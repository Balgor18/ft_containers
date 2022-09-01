#ifndef RBT_NODE_HPP
# define RBT_NODE_HPP

# define BLACK 0
# define RED 1

template<typename Key,typename Value>
struct Pair
{
	Key		key;
	Value	value;
};

template<typename Key, typename Value>
class Node
{
	Node				*parent;
	Node				*child_left;
	Node				*child_right;
	Pair<const Key, Value>	pair;
	bool				color;

	// Default constructor
	Node () : (parent(NULL), child_left(NULL), child_right(NULL), pair(0, 0), color(RED)) {}
	Node(const Key &key, const Value &value) : (parent(NULL), child_left(NULL), child_right(NULL), pair(key, value), color(RED)) {}

	// Copy constructor
	Node(const Node &cpy) : (parent(cpy.parent), child_left(cpy.child_left), child_right(cpy.child_right), pair(cpy.key, cpy.value), color(cpy.color)){}

	// Destructor
	virtual ~Node();

	Node	*getParent(void) const
	{
		return parent;
	}

	Node	*getChild_left(void) const
	{
		return child_left;
	}

	Node *getChild_right(void) const
	{
		return child_right;
	}

	Pair<Key, value> getPair(void)const
	{
		return pair;
	}

	boll getColor(void) const
	{
		return color;
	}
};

#endif