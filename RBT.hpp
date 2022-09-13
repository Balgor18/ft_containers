#ifndef RBT_HPP
# define RBT_HPP

# include "Node.hpp"
# include "RBT_iterator.hpp"
# include "iterator.hpp"
# include <sstream>

namespace ft {

	// Remove std::less<T>
	template<class T, class Compare = std::less<T>, class Node = Node<T>, class Allocator = std::allocator<Node> >// MEMO remode std::less
	class Red_black_tree
	{
		public :
			typedef Allocator								allocator_type;
			typedef std::size_t								size_type;
			typedef ft::Node<T>*								node_ptr;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

			typedef RBT_iterator<T>						iterator;
			typedef RBT_iterator<const T>				const_iterator;
			typedef reverse_iterator<iterator> 			reverse_iterator;
			// typedef reverse_iterator<const_iterator>	const_reverse_iterator;
		private :
			node_ptr		_NIL;
			node_ptr		_root;
			allocator_type	_alloc;
			size_type		_size;
			Compare			_cmp;

			void	_print(Node *node, std::stringstream &buffer, bool isTail, std::string prefix)
			{
				if (node->child_right != this->_NIL)
					this->_print(node->child_right, buffer, false, std::string(prefix).append(isTail ? "│   " : "    "));
				buffer << prefix << (isTail ? "└── " : "┌── ");
				if (node->color == RED)
					buffer << "\033[31m";
				buffer << node->data << "\033[0m" << std::endl;
				if (node->child_left != this->_NIL)
					this->_print(node->child_left, buffer, true, std::string(prefix).append(isTail ? "    " : "│   "));
			}

			void	_clear(node_ptr actual)
			{
				if (actual->child_left != _NIL)
					_clear(actual->child_left);
				else if (actual->child_right != _NIL)
					_clear(actual->child_right);

				if (actual != _NIL)
				{
					node_ptr	tmp = actual->parent;

					if (tmp->child_right == actual)
						tmp->child_right = _NIL;
					else
						tmp->child_left = _NIL;
					_alloc.destroy(actual);
					_alloc.deallocate(actual, 1);
				}
			}
		public :
			Red_black_tree(const Allocator& alloc= Allocator(), const Compare& cmp = Compare()) : _alloc(alloc), _cmp(cmp)
			{
				_NIL = _alloc.allocate(1);
				_alloc.construct(_NIL, T());
				_NIL->set_color(BLACK);
				_NIL->set_child_left(_NIL);
				_NIL->set_child_right(_NIL);
				_NIL->set_parent(_NIL);
				_root = _NIL;
				_size = 0;
			};

			Red_black_tree(T pair, const Allocator& alloc= Allocator(), const Compare& cmp = Compare()) : _alloc(alloc), _cmp(cmp)
			{
				_NIL = _alloc.allocate(1);
				_alloc.construct(_NIL, T());
				_NIL->set_color(BLACK);
				_NIL->set_child_left(_NIL);
				_NIL->set_child_right(_NIL);
				_NIL->set_parent(_NIL);
				_root = _alloc.allocate(1);
				_alloc.construct(_root, pair);
				_root->set_color(BLACK);
				_root->set_parent(_NIL);
				_root->set_child_left(_NIL);
				_root->set_child_right(_NIL);
				_size = 1;
			};

			//copy constructor
			Red_black_tree(Red_black_tree& cpy) : _NIL(cpy._NIL), _root(cpy._root), _alloc(cpy._alloc), _size(cpy._size) {};

			//overload operator=
			Red_black_tree<T, Compare>&	operator=(const Red_black_tree<T, Compare>&rhs)
			{
				if (this == &rhs)
					return (*this);
				_NIL = rhs._NIL;
				_root = rhs._root;
				_alloc = rhs._alloc;
				_size = rhs._size;
				_cmp = rhs._cmp;
			}

			// Destructor
			~Red_black_tree(void)
			{
				clear();
				_alloc.destroy(_NIL);
				_alloc.deallocate(_NIL, 1);
			}

			void	print(void)
			{
				std::stringstream	buffer;

				if (!_size)
				{
					std::cout << "Binary tree empty"<< std::endl;
					return ;
				}
				std::cout <<  "size: " << this->size() << std::endl;
				if (this->_root != this->_NIL)
				{
					this->_print(this->_root, buffer, true, "");
					std::cout << buffer.str();
				}
			}

			// ================= Iterator =================
			iterator	begin()
			{
				node_ptr	tmp = _root;
				
				while (tmp != _NIL)
				{
					if (tmp->child_left == _NIL)
						break ;
					tmp = tmp->child_left;
				}
				return iterator(_root, _NIL, tmp);
			}

			const_iterator	begin() const
			{
				node_ptr	tmp = _root;
				
				while (tmp != _NIL)
				{
					if (tmp->child_left == _NIL)
						break ;
					tmp = tmp->child_left;
				}
				return const_iterator(_root, _NIL, tmp);
			}

			iterator	end()
			{
				node_ptr	tmp = _root;
				
				while (tmp != _NIL)
				{
					if (tmp->child_right == _NIL)
						break ;
					tmp = tmp->child_right;
				}
				return iterator(_root, _NIL, tmp);
			}

			const_iterator	end() const
			{
				node_ptr	tmp = _root;
				
				while (tmp != _NIL)
				{
					if (tmp->child_right == _NIL)
						break ;
					tmp = tmp->child_right;
				}
				return const_iterator(_root, _NIL, tmp);
			}

			// FIX When reverse_iterator is code 
			reverse_iterator	rebgin()
			{
				return reverse_iterator(end());
			}

			// FIXME When const reverse iterator work
			// const_reverse_iterator rbegin() const
			// {
			// 	return const_reverse_iterator(end());
			// }

			// FIX When reverse_iterator is code 
			reverse_iterator	rend()
			{
				return reverse_iterator(begin());
			}

			// FIXME When const reverse iterator work
			// const_reverse_iterator rend() const
			// {
			// 	return const_reverse_iterator(begin());
			// }

			// ================= Capacity =================
			bool	empty() const
			{
				if (_size == 0)
					return true;
				return false;
			}

			size_type	size(void) const { return _size; }

			size_type	max_size() const { return _alloc.max_size(); }

			// ================= Modifiers =================
			void	clear()
			{
				// DO clear algo
				_clear(_root);
				_root = _NIL;
				_size = 0;
			}

			// node_ptr	insert(const T& pair) // TODO Modif this
			void	insert(const T& pair)
			{
				// TODO Modif this
				node_ptr	tmp;
				node_ptr	new_elem;

				new_elem = _alloc.allocate(1);
				_alloc.construct(new_elem, pair);
				new_elem->set_parent(_NIL);
				new_elem->set_child_left(_NIL);
				new_elem->set_child_right(_NIL);
				_size++;
				if (_root == _NIL)
				{
					new_elem->set_color(BLACK);
					_root = new_elem;
					return ;
				}
				new_elem->set_color(RED);
				tmp = _root;
				while (tmp != _NIL)
				{
					if (tmp->data < new_elem->data)// Go vers la droite
					{
						if (tmp->child_right != _NIL)
						{
							tmp = tmp->child_right;
							continue;
						}
						else
						{
							tmp->child_right = new_elem;
							new_elem->set_parent(tmp);// MEMO if break move this line 
							return ;// MEMO probably need break
						}
					}

					if (tmp->data > new_elem->data)// Go vers la gauche
					{
						if (tmp->child_left != _NIL)
						{
							tmp = tmp->child_left;
							continue;
						}
						else
						{
							tmp->child_left = new_elem;
							new_elem->set_parent(tmp);// MEMO if break move this line 
							return ;// MEMO probably need break
						}
					}
				}
				// TODO Modif this
			}

			// iterator	insert(interator hint, const T& val)
			// {
				// TODO
			// }

			// template<typename input_iterator>
			// void	insert(input_iterator first, input_iterator last)
			// {
				// TODO
			// }

			void	swap(Red_black_tree &other)
			{
				std::swap(_root, other._root);
				std::swap(_NIL, other._NIL);
				std::swap(_size, other._size);
				std::swap(_cmp, other._cmp);;
			}

			// void	insert(T pair)
			// {
			// 	node_ptr	tmp;
			// 	node_ptr	new_elem;
			// 	new_elem = _alloc.allocate(1);
			// 	_alloc.construct(new_elem, pair);
			// 	new_elem->set_parent(_NIL);
			// 	new_elem->set_child_left(_NIL);
			// 	new_elem->set_child_right(_NIL);
			// 	_size++;
			// 	if (_root == _NIL)
			// 	{
			// 	§	new_elem->set_color(BLACK);
			// 		_root = new_elem;
			// 		return ;
			// 	}
			// 	new_elem->set_color(RED);
			// 	tmp = _root;
			// 	while (tmp != _NIL)
			// 	{
			// 		if (tmp->data < new_elem->data)// Go vers la droite
			// 		{
			// 			if (tmp->child_right != _NIL)
			// 			{
			// 				tmp = tmp->child_right;
			// 				continue;
			// 			}
			// 			else
			// 			{
			// 				tmp->child_right = new_elem;
			// 				new_elem->set_parent(tmp);// MEMO if break move this line 
			// 				return ;// MEMO probably need break
			// 			}
			// 		}
			// 		if (tmp->data > new_elem->data)// Go vers la gauche
			// 		{
			// 			if (tmp->child_left != _NIL)
			// 			{
			// 				tmp = tmp->child_left;
			// 				continue;
			// 			}
			// 			else
			// 			{
			// 				tmp->child_left = new_elem;
			// 				new_elem->set_parent(tmp);// MEMO if break move this line 
			// 				return ;// MEMO probably need break
			// 			}
			// 		}
			// 	}
			// }

			iterator	erase(iterator pos)
			{
				// TODO
			}

			iterator	erase(iterator first, iterator last)
			{
				// TODO
			}

			// size_type	erase(const Key& key)
			// {
			// 	// TODO
			// }

			size_type	count(const T &x) const
			{
				if (find(x) == end())
					return 0;
				return 1;
			}

			iterator	find(const T& x)
			{
				node_ptr	tmp = _root;

				if (tmp == _NIL)
					return end();
				while (tmp != _NIL)
				{
					if (!_cmp(tmp->data, x) && !_cmp(x, tmp->data))
						return iterator(_root, _NIL, tmp);
					else if (_cmp(x, tmp->data))
						tmp = tmp->child_left;
					else
						tmp = tmp->child_right;
				}
				return end();
			}

			// FIX When const iterator is code 
			const_iterator	find(const T& x) const
			{
				node_ptr	tmp = _root;

				if (tmp == _NIL)
					return end();
				while (tmp != _NIL)
				{
					if (!_cmp(tmp->data, x) && !_cmp(x, tmp->data))
						return const_iterator(_root, _NIL, tmp);
					else if (_cmp(x, tmp->data))
						tmp = tmp->child_left;
					else
						tmp = tmp->child_right;
				}
				return end();
			}

			// std::pair<iterator,iterator>	equal_range(const Key& key)
			// {
				// TODO
			// }

			// std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			// {
				// TODO
			// }


			iterator lower_bound( const T& x )
			{
				iterator it = begin();
				iterator ite = end();

				for (; it != ite; it++)
				{
					if (_cmp(*it, x));
					else
						break;
				}
				return it;
			}

			
			// const_iterator lower_bound( const Key& key ) const
			// {
			// 	const_iterator it = begin();
			// 	const_iterator ite = end();

			// 	for (; it != ite; it++)
			// 	{
			// 		if (_cmp(*it, x));
			// 		else
			// 			break;
			// 	}
			// 	return it;
			// }

			iterator upper_bound( const T& x )
			{
				iterator	ite = end();
				iterator	it = lower_bound(x);

				if (it != ite && !_cmp(x,*it) && !_cmp(*it, x))
					return (++it);
				return (it);
			}

			// const_iterator upper_bound( const Key& key ) const
			// {
			// 	const_iterator	ite = end();
			// 	const_iterator	it = lower_bound(x);

			// 	if (it != ite && !_cmp(x,*it) && !_cmp(*it, x))
			// 		return (++it);
			// 	return (it);
			// }

			// node_ptr	get_root()const
			// {
			// 	return _root;
			// }

			// node_ptr	get_nil()const
			// {
			// 	return _NIL;
			// }

			// ================= Observers =================
			// key_compare key_comp() const
			// {
			// 	// TODO
			// }

			// value_compare value_comp() const
			// {
			// 	// TODO
			// }
		
			// template< class Key, class T, class Compare, class Alloc >
			// bool operator==( const std::map<Key,T,Compare,Alloc>& lhs,
			// 				const std::map<Key,T,Compare,Alloc>& rhs );

			// template< class Key, class T, class Compare, class Alloc >
			// bool operator!=( const std::map<Key,T,Compare,Alloc>& lhs,
			// 				const std::map<Key,T,Compare,Alloc>& rhs );

			// template< class Key, class T, class Compare, class Alloc >
			// bool operator<( const std::map<Key,T,Compare,Alloc>& lhs,
			// 				const std::map<Key,T,Compare,Alloc>& rhs );

			// template< class Key, class T, class Compare, class Alloc >
			// bool operator<=( const std::map<Key,T,Compare,Alloc>& lhs,
			// 				const std::map<Key,T,Compare,Alloc>& rhs );

			// template< class Key, class T, class Compare, class Alloc >
			// bool operator>( const std::map<Key,T,Compare,Alloc>& lhs,
			// 				const std::map<Key,T,Compare,Alloc>& rhs );

			// template< class Key, class T, class Compare, class Alloc >
			// bool operator>=( const std::map<Key,T,Compare,Alloc>& lhs,
			// 				const std::map<Key,T,Compare,Alloc>& rhs );

	};


};

#endif