#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "RBT.hpp"
# include "Node.hpp"
# include "iterator.hpp"

namespace ft
{
	template <class T>//, class node_type = ft::Node<T>>
	class RBT_iterator
	{
		typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;
		typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_type;
		typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::reference				reference;
		typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::pointer				pointer;
		typedef RBT_iterator<T>											Himself;
		typedef Node<T>*												node_ptr;
		protected :
			node_ptr	_root;
			node_ptr	_NIL;
			node_ptr	_actual_node;
		private:
			// Example https://www.cs.odu.edu/~zeil/cs361/latest/Public/treetraversal/index.html
			void	Increment()
			{
				if (_actual_node->child_right != _NIL) {
					_actual_node = _actual_node->child_right;
					while (_actual_node->child_left != _NIL) {
						_actual_node = _actual_node->child_left;
					}
				}
				else{
					node_ptr	tmp = _actual_node->parent;

					while (tmp != _NIL && _actual_node == tmp->child_right) {
						_actual_node = tmp;
						tmp = tmp->parent;
					}
					if (_actual_node->child_left != tmp)
						_actual_node = tmp;
					else
						_actual_node = _NIL;
				}
			}

			void Decrement()
			{
				if (_actual_node->parent->parent == _actual_node && _actual_node->color == RED)
					_actual_node = _actual_node->child_right;
				if (_actual_node->child_left != _NIL) {
					_actual_node = _actual_node->child_left;
					while (_actual_node->child_right != _NIL) {
						_actual_node = _actual_node->child_right;
					}
				}
				else {
					node_ptr	tmp = _actual_node->parent;

					while (tmp != _NIL && _actual_node == tmp->child_left) {
						_actual_node = tmp;
						tmp = tmp->parent;
					}
					_actual_node = tmp;
				}
			}

				node_ptr	maximum() {
					node_ptr	tmp = _root;

					while (tmp->child_right != _NIL)
						tmp = tmp->child_right;
					return tmp;
				};

		public :
			RBT_iterator(void) : _root(NULL), _NIL(NULL), _actual_node(NULL) {}

			RBT_iterator(node_ptr &root, node_ptr &nil, node_ptr &actual) : _root(root), _NIL(nil), _actual_node(actual){}

			RBT_iterator(RBT_iterator const &cpy) : _root(cpy._root), _NIL(cpy._NIL), _actual_node(cpy._actual_node) { }

			~RBT_iterator() {}

			RBT_iterator&	operator++()
			{
				Increment();
				return *this;
			}

			RBT_iterator	operator++(int) {
				Himself tmp(*this);

				Increment();
				return tmp;
			}

			RBT_iterator&	operator--() {
				if (_actual_node == _NIL) {
					_actual_node = maximum();
					return *this;
				}
				Decrement();
				return *this;
			}

			RBT_iterator	operator--(int) {
				Himself tmp(*this);

					if (_actual_node == _NIL) {
					_actual_node = maximum();
					return tmp;
				}
				Decrement();
				return tmp;
			}

			RBT_iterator &operator=(const RBT_iterator<T>& rhs)
			{
				_actual_node = rhs.get_node();
				_NIL = rhs.get_nil();
				_root = rhs.get_root();
				return *this;
			 }

			reference operator*() { return _actual_node->data; };
			
			const reference operator*() const { return _actual_node->data; };

			pointer operator->() { return &(_actual_node->data); };

			const pointer operator->() const { return &(_actual_node->data); };

			node_ptr	get_node() const { return _actual_node; };

			node_ptr	get_nil() const { return _NIL; };

			node_ptr	get_root() const { return _root; };
	};
}

#endif 