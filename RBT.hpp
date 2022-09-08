#ifndef RBT_HPP
# define RBT_HPP

# include "Node.hpp"
# include <sstream>
namespace ft {

	// Remove std::less<T>
	template<class T, class Compare = std::less<T>, class Node = Node<T>, class Allocator = std::allocator<Node> >// MEMO remode std::less
	class Red_black_tree
	{
		public :
			typedef Allocator								allocator_type;
			typedef std::size_t								size_type;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

			// typedef ft::RBT_iterator<T>						iterator;
			// typedef ft::const_RBTIterator<T>				const_iterator;
			// typedef ft::reverse_iterator<iterator> 			reverse_iterator;
			// typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;
		private :
			Node			*_NIL;
			Node			*_root;
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

		public :
			Red_black_tree(const Allocator& alloc= Allocator(), const Compare& cmp = Compare()) : _alloc(alloc), _cmp(cmp)
			{
				_NIL = _alloc.allocate(1);
				_alloc.construct(_NIL, T());
				_NIL->set_color(BLACK);
				_root = _NIL;
				_size = 0;
			};

			Red_black_tree(T pair, const Allocator& alloc= Allocator(), const Compare& cmp = Compare()) : _alloc(alloc), _cmp(cmp)
			{
				_NIL = _alloc.allocate(1);
				_alloc.construct(_NIL, T());
				_NIL->set_color(BLACK);
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

			}

			size_type	size(void) const
			{
				return _size;
			}

			// iterator	find(const T& x)
			bool	find(const T& x)
			{
				Node	*tmp = _root;

				if (tmp == _NIL)
					return false;
					// return _NIL;
				while (tmp != _NIL)
				{
					if (!_cmp(tmp->data, x) && !_cmp(x, tmp->data))
						return true;
						// return tmp;
					else if (_cmp(x, tmp->data))
						tmp = tmp->child_left;
					else
						tmp = tmp->child_right;
				}
				// return _NIL;
				return false;
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

			// insert
			void	insert(T pair)
			{
				Node	*tmp;
				Node	*new_elem;

				new_elem = _alloc.allocate(1);
				_alloc.construct(new_elem, pair);
				// new_elem->set_data(pair);
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
			}

			// delete
			void	erase(T pair)// MEMO Check the enter value
			{
				// Node	*tmp;

				// tmp = _root;
			}

			Node	*get_root()const
			{
				return _root;
			}
	};

};

#endif