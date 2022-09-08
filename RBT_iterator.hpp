#ifndef RBT_ITERATOR_HPP
# define RBT_ITERATOR_HPP

# include "RBT.hpp"
# include "Node.hpp"
# include "iterator.hpp"

namespace ft
{
	template <class T, class node_type = ft::Node<T>>
	class RBT_iterator
	{
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::value_type			value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::iterator_category		iterator_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>::reference				reference;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, T>:: pointer				pointer;
		typedef RBT_iterator<T>

		node_type		*_node;

		RBT_iterator&	operator++()
		{
			if (_node )

			return *this;
		}

		RBT_iterator	operator++(int) {

			return tmp;
		};

		RBT_iterator&	operator--() {

			return *this;
		};

		RBT_iterator	operator--(int) {

			return tmp;
		};
	};
}

#endif 