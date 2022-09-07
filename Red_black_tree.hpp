#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "Node.hpp"

namespace ft {

	template<class T, class Allocator = std::allocator<T> >
	class Red_black_tree : public Node<T>
	{
		public :
			typedef Allocator			allocator_type;
			typedef std::size_t			size_type;
			typedef Node<T>*			Node_PTR;
			typedef Node<T>&			Node_REF;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;


		private :
			pointer			_NIL;
			pointer			_root;
			allocator_type	_alloc;
			size_type		_size;
		// comparator cmp

		public :
			Red_black_tree(const Allocator& alloc= Allocator()) : _alloc(alloc)
			{
				_NIL = _alloc.allocate(1);
				// _NIL->set_color(BLACK); // DBG Error il trouve pas que c'est une node
				_root = _NIL;
				_size = 0;
			};

			// Red_black_tree(T &pair, const Allocator& alloc= Allocator()) : _alloc(alloc)
			// {
			// 	_NIL = _alloc.allocate(1);
			// 	_NIL->set_color(BLACK);
			// 	_root = _alloc.allocate(1);
			// 	_root->set_data(pair);
			// 	_root->set_color(BLACK);
			// 	_root->set_left_child(_NIL);
			// 	_root->set_right_child(_NIL);
			// 	_size = 1;
			// };

			//copy constructor
			Red_black_tree(Red_black_tree& cpy) : _NIL(cpy._NIL), _root(cpy._root), _alloc(cpy._alloc), _size(cpy._size) {};

			//overload operator=
			Red_black_tree<T>&	operator=(const Red_black_tree<T>&rhs)
			{
				if (this == &rhs)
					return (*this);
				// DBG do somethind
			}

			// Destructor
			~Red_black_tree(void)
			{

			}

			// print
			void	print(void)
			{
				if (_root == _NIL)
				{
					std::cout << "Arbre Empty" << std::endl;
					return ;
				}
			}

			// insert
			void	insert(T &pair)
			{
				// Need to code insert
			}

			// delete
			void	erase(T &pair)
			{
				// Need cpde for erase
			}

	};

};

#endif