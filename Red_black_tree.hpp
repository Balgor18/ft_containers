#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

# include "Node.hpp"
# include <memory>
# include <algorithm>
namespace ft {
	template<class T, class Allocator = std::allocator<T>>
	class Red_black_tree : public Node
	{
		public :
			typedef Allocator			allocator_type;
			typedef std::size_t			size_type;

			typedef typename Allocator::reference			reference;
			typedef typename Allocator::const_reference		const_reference;
			typedef typename Allocator::pointer				pointer;
			typedef typename Allocator::const_pointer		const_pointer;

			typedef typename Node*							Node_PTR;
			typedef typename Node&							Node_REF;

		private :
			Node_PTR		_NIL;
			Node_PTR		_root;
			allocator_type	_alloc;
			size_type		_size;
		// comparator cmp

		public :
			Red_black_tree(const Allocator& alloc= Allocator()) : _alloc(alloc)
			{
				NIL = _alloc.allocate(1);
				NIL.set_color(BLACK);
				root = NIL;
				size = 0;
			};

			// Red_black_tree(T &pair, const Allocator& alloc= Allocator()) : _alloc(alloc)
			// {
			// 	NIL = alloc.allocate(1);
			// 	Root = NIL;
			// 	size = 0;
			// };

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

			// delete
	};

};

#endif