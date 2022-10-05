#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "RBT.hpp"
# include "Node.hpp"
# include "iterator.hpp"

namespace ft
{

	template <class T, class Node>
	class RBT_iterator {
		
		public :
			typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;
			typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_category;
			typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::reference				reference;
			typedef typename ft::Iterator<ft::bidirectional_iterator_tag, T>::pointer				pointer;
			typedef typename ft::Iterator<ft::bidirectional_iterator_tag, const T>::reference		const_reference;
			typedef typename ft::Iterator<ft::bidirectional_iterator_tag, const T>:: pointer		const_pointer;
			typedef Node*						node_ptr;
			typedef RBT_iterator<T, Node>		Himself;

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

			void	Decrement()
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

			RBT_iterator(node_ptr const root, node_ptr const nil, node_ptr const actual) : _root(root), _NIL(nil), _actual_node(actual){}

			RBT_iterator(RBT_iterator const &cpy) : _root(cpy._root), _NIL(cpy._NIL), _actual_node(cpy._actual_node) { }

			~RBT_iterator() {}

			operator RBT_iterator< const T, const Node>() const
			{
				return RBT_iterator< const T, const Node>(_root, _NIL, _actual_node);
			}

			RBT_iterator&	operator++()
			{
				Increment();
				return *this;
			}

			RBT_iterator	operator++(int)
			{
				Himself tmp(*this);

				Increment();
				return tmp;
			}

			RBT_iterator&	operator--()
			{
				if (_actual_node == _NIL) {
					_actual_node = maximum();
					return *this;
				}
				Decrement();
				return *this;
			}

			RBT_iterator	operator--(int)
			{
				Himself tmp(*this);

					if (_actual_node == _NIL) {
					_actual_node = maximum();
					return tmp;
				}
				Decrement();
				return tmp;
			}

			RBT_iterator &operator=(const RBT_iterator<T, Node>& rhs)
			{
				_actual_node = rhs.get_node();
				_NIL = rhs.get_nil();
				_root = rhs.get_root();
				return *this;
			 }

			reference operator*() 
			{
				return _actual_node->data;
			};
			
			const_reference operator*() const 
			{
				return _actual_node->data;
			};

			pointer operator->() 
			{
				return &(_actual_node->data);
			};

			const_pointer operator->() const 
			{
				return &(_actual_node->data);
			};

			node_ptr	get_node() const 
			{
				return _actual_node;
			};

			node_ptr	get_nil() const 
			{
				return _NIL;
			};

			node_ptr	get_root() const 
			{
				return _root;
			};

			bool operator==( const RBT_iterator& rhs )
			{
				return _actual_node == rhs._actual_node;
			};

			bool operator!=( const RBT_iterator& rhs )
			{
				// std::cout << "-----------------------" << std::endl;
				// std::cout << "actual == rhs actual   " << (_actual_node == rhs._actual_node) << std::endl;
				// std::cout << "rhs nil != rhs actual  " << (rhs._NIL == rhs._actual_node) << std::endl;
				// std::cout << "nil != actual node     " << (_NIL != _actual_node) << std::endl;
				// std::cout << "                       " << (rhs._NIL == rhs._actual_node && _NIL == _actual_node) << std::endl;
				// std::cout << "si 0 alors 1 && 1 || 0 ou 1 && 0 || 1" << std::endl;
				// std::cout << "DOIT change en 0 || 1 && 1" << std::endl;
				if (_actual_node == rhs._actual_node || _actual_node == _NIL)
					return 0;
				return 1;
				// if (_actual_node == rhs._actual_node || (rhs._NIL == rhs._actual_node && _NIL == _actual_node))
				// 	return 0;
				// return 1;
				// if (_actual_node == rhs._actual_node && (rhs._NIL != rhs._actual_node || _NIL != _actual_node))
				// 	return 0;
				// else
				// 	return 1;
				return (_actual_node != rhs._actual_node);
			};
	};
}

#endif 