#ifndef RBT_HPP
# define RBT_HPP

# include "Node.hpp"
# include "RBT_iterator.hpp"
# include "iterator.hpp"
# include <sstream>
# include "lexicographical_compare.hpp"
# include "pair.hpp"

namespace ft {

	// Remove std::less<T>
	template<class T, class Compare = std::less<T>, class Allocator = std::allocator<Node<T> > >// MEMO remode std::less
	class Red_black_tree
	{
		public :
			typedef Allocator											allocator_type;
			typedef std::size_t											size_type;
			typedef Compare												key_compare;
			typedef ft::Node<T>*										node_ptr;

			typedef typename Allocator::reference						reference;
			typedef typename Allocator::const_reference					const_reference;
			typedef typename Allocator::pointer							pointer;
			typedef typename Allocator::const_pointer					const_pointer;

			typedef ft::RBT_iterator<T, ft::Node<T> >					iterator;
			typedef ft::RBT_iterator<const T, const ft::Node<T> >		const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			class value_compare
			{

				friend class Red_black_tree;
				protected:
					Compare comp;
					value_compare (Compare c) : comp(c) {}
				public:
					bool operator() (const T& x, const T& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private :
			node_ptr		_NIL;
			node_ptr		_root;
			allocator_type	_alloc;
			size_type		_size;
			Compare			_cmp;

			void	_print(node_ptr	node, std::stringstream &buffer, bool isTail, std::string prefix)
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

			void	_invert(node_ptr	lhs, node_ptr	rhs) {
				if (lhs->parent == _NIL)
					_root = rhs;
				else if (lhs == lhs->parent->child_left)
					lhs->parent->child_left = rhs;
				else
					lhs->parent->child_right =rhs;
				rhs->parent = lhs->parent;
			}

			node_ptr	max(node_ptr x) {
				node_ptr node = x;

				while (node->child_right != _NIL)
					node = node->child_right;
				return node;
			}

			node_ptr	min(node_ptr x) {
				node_ptr node = x;

				while (node->child_left != _NIL)
					node = node->child_left;
				return node;
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
			Red_black_tree(const Red_black_tree& cpy) : _NIL(cpy._NIL), _root(cpy._root), _alloc(cpy._alloc), _size(cpy._size) {};

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
				return iterator(_root, _NIL, _NIL);
			}

			const_iterator	end() const
			{
				return const_iterator(_root, _NIL, _NIL);
			}

			reverse_iterator	rbegin()
			{
				return reverse_iterator(end());
			}

			const_reverse_iterator rbegin() const
			{
				return const_reverse_iterator(end());
			}

			reverse_iterator	rend()
			{
				return reverse_iterator(begin());
			}

			const_reverse_iterator rend() const
			{
				return const_reverse_iterator(begin());
			}

			// ================= Capacity =================
			bool	empty() const
			{
				if (_size == 0)
					return true;
				return false;
			}

			size_type	size(void) const 
			{
				return _size;
			}

			size_type	max_size() const 
			{
				return _alloc.max_size();
			}

			// ================= Modifiers =================
			void	clear()
			{
				_clear(_root);
				_root = _NIL;
				_size = 0;
			}

			T	insert(const T& pair)
			{
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
					return _root->data;
				}
				new_elem->set_color(RED);
				tmp = _root;
				while (tmp != _NIL)
				{
					if (tmp->data < new_elem->data)
					{
						if (tmp->child_right != _NIL)
						{
							tmp = tmp->child_right;
							continue;
						}
						else
						{
							tmp->child_right = new_elem;
							break ;
						}
					}

					if (tmp->data > new_elem->data)
					{
						if (tmp->child_left != _NIL)
						{
							tmp = tmp->child_left;
							continue;
						}
						else
						{
							tmp->child_left = new_elem;
							break ;
						}
					}
					if (tmp->data == new_elem->data)
					{
						_clear(new_elem);
						return tmp->data;
					}
				}
				new_elem->set_parent(tmp);
				// TODO Balance RBT here (Probably)
				return new_elem->data;
			}

			iterator	insert(iterator hint, const T& val)
			{
				(void)hint;
				return iterator(insert(val), _NIL, _root);
			}

			template<typename input_iterator>
			void	insert(input_iterator first, input_iterator last)
			{
				for (; first != last; first++) {
					insert(*first);
				}
			}

			void	swap(Red_black_tree &other)
			{
				std::swap(_root, other._root);
				std::swap(_NIL, other._NIL);
				std::swap(_size, other._size);
				std::swap(_cmp, other._cmp);;
			}

			void	erase(iterator pos)
			{
				node_ptr	color_node = pos.get_node();; 
				node_ptr	param_node = pos.get_node();
				node_ptr	left;
				node_ptr	right;
				if (param_node == _NIL) {
					return ;
				}
				if (param_node->child_left == _NIL) {
					right = param_node->child_right;
					_invert(param_node, param_node->child_right);
				}
				else if (param_node->child_right == _NIL) {
					left = param_node->child_left;
					_invert(param_node, param_node->child_left);
				}
				else {
					left = min(param_node->child_right);
					color_node = left;
					right = left->child_right;
					if (left->parent == param_node) {
						left->parent = left;
					}
					else {
						_invert(left, left->child_right);
						left->child_right = param_node->child_right;
						left->child_right->parent = left;
					}
					_invert(param_node, left);
					left->child_left = param_node->child_left;
					left->child_left->parent = left;
					left->color = param_node->color;
				}
				// TODO rebalanced TREE
				_alloc.destroy(param_node);
				_alloc.deallocate(param_node, 1);
				_size--;
				return ;
			}

			void	erase(iterator first, iterator last)
			{
				iterator	tmp;

				while (first != last)
				{
					tmp = first;
					first++;
					erase(tmp);
				}
			}

			size_type	erase(const T& key)
			{
				node_ptr	color_node = find(key).get_node(); 
				node_ptr	param_node = find(key).get_node();
				node_ptr	left;
				node_ptr	right;

				if (param_node == _NIL) {
					return 0;
				}
				if (param_node->child_left == _NIL) {
					right = param_node->child_right;
					_invert(param_node, param_node->child_right);
				}
				else if (param_node->child_right == _NIL) {
					left = param_node->child_left;
					_invert(param_node, param_node->child_left);
				}
				else {
					left = min(param_node->child_right);
					color_node = left;
					right = left->child_right;
					if (left->parent == param_node) {
						left->parent = left;
					}
					else {
						_invert(left, left->child_right);
						left->child_right = param_node->child_right;
						left->child_right->parent = left;
					}
					_invert(param_node, left);
					left->child_left = param_node->child_left;
					left->child_left->parent = left;
					left->color = param_node->color;
				}
				_alloc.destroy(param_node);
				_alloc.deallocate(param_node, 1);
				_size--;
				return 1;
			}

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

			pair<iterator, iterator>	equal_range(const T& key)
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}

			pair<const_iterator, const_iterator>	equal_range( const T& key ) const
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}

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

			const_iterator lower_bound( const T& key ) const
			{
				const_iterator it = begin();
				const_iterator ite = end();

				for (; it != ite; it++)
				{
					if (_cmp(*it, key));
					else
						break;
				}
				return it;
			}

			iterator upper_bound( const T& x )
			{
				iterator	ite = end();
				iterator	it = lower_bound(x);

				if (it != ite && !_cmp(x,*it) && !_cmp(*it, x))
					return (++it);
				return (it);
			}

			const_iterator upper_bound( const T& key ) const
			{
				const_iterator	ite = end();
				const_iterator	it = lower_bound(key);

				if (it != ite && !_cmp(key,*it) && !_cmp(*it, key))
					return (++it);
				return (it);
			}

			// ================= Observers =================
			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return value_compare(key_compare());
			}

			node_ptr	get_nil() const
			{
				return _NIL;
			}

			node_ptr	get_root() const
			{
				return _root;
			}
	};

	// https://stackoverflow.com/questions/70490594/trouble-implementing-const-iterator-in-c

	template<class T, class Compare, class Allocator>
	bool operator==(Red_black_tree<T, Compare, Allocator>& lhs,
					Red_black_tree<T, Compare, Allocator>& rhs )
	{
		return (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()));
	};

	template<class T, class Compare, class Allocator>
	bool operator!=( Red_black_tree<T, Compare, Allocator>& lhs,
					Red_black_tree<T, Compare, Allocator>& rhs )
	{
		return (!(lhs == rhs));
	};

	template<class T, class Compare, class Allocator>
	bool operator<( Red_black_tree<T, Compare, Allocator>& lhs,
					Red_black_tree<T, Compare, Allocator>& rhs )
	{
		return (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()));
	};

	template<class T, class Compare, class Allocator>
	bool operator<=( Red_black_tree<T, Compare, Allocator>& lhs,
					Red_black_tree<T, Compare, Allocator>& rhs )
	{
		return !(lhs < rhs);
	};

	template<class T, class Compare, class Allocator>
	bool operator>( Red_black_tree<T, Compare, Allocator>& lhs,
					Red_black_tree<T, Compare, Allocator>& rhs )
	{
		return !(lhs < rhs);
	};

	template<class T, class Compare, class Allocator>
	bool operator>=( Red_black_tree<T, Compare, Allocator>& lhs,
					Red_black_tree<T, Compare, Allocator>& rhs )
	{
		return !(lhs < rhs);
	};

};

#endif