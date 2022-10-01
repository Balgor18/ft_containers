#ifndef SET_HPP
# define SET_HPP

# include <functional>
# include "pair.hpp"
# include "Node.hpp"
# include "RBT.hpp"
// # include "RBT_iterator.hpp"

namespace ft {

	template < class T, class Compare = std::less<T>, class Alloc = std::allocator<T> >
	class set{
		public:
			typedef T										value_type;
			typedef Compare									key_compare;
			typedef Compare									value_compare;
			typedef Alloc									allocator_type;
			typedef typename Alloc::reference				reference;
			typedef typename Alloc::const_reference			const_reference;
			typedef typename Alloc::size_type				size_type;
			typedef typename Alloc::difference_type			difference_type;
			typedef typename Alloc::pointer					pointer;
			typedef typename Alloc::const_pointer			const_pointer;
			
			typedef ft::RBT_iterator<value_type, ft::Node<value_type> >					iterator;
			typedef ft::RBT_iterator<const value_type, const ft::Node<value_type> >		const_iterator;
			typedef ft::reverse_iterator<iterator>										reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>								const_reverse_iterator;

		private :
			Red_black_tree<value_type>		_RBT;
			allocator_type					_alloc;
			value_compare					_cmp;
		public :

			explicit set(const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : _RBT(), _alloc(alloc), _cmp(comp){};

			template <class InputIterator>
			set(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Alloc& alloc = Alloc()) : _RBT(), _alloc(alloc), _cmp(comp)
			{
				insert(first, last);
			};

			set(const set<T,Compare,Alloc>& cpy) : _RBT(value_compare(cpy._cmp)), _alloc(Alloc()), _cmp(Compare())
			{
				insert(cpy.begin(), cpy.end());
			};

			~set()
			{

			};

			set<T,Compare,Alloc>& operator= (const set<T,Compare,Alloc>& cpy)
			{
				this->clear();
				const_iterator it = cpy.begin();
				while(it != cpy.end())
				{
					insert(*it);
					it++;
				}
				return *this;
			};
			
			allocator_type get_allocator() const 
			{
				return _alloc;
			};
		
			iterator begin() 
			{
				return _RBT.begin();
			};

			const_iterator begin() const 
			{
				return _RBT.begin();
			};

			iterator end() 
			{
				return _RBT.end();
			};

			const_iterator end() const 
			{
				return _RBT.end();
			};

			reverse_iterator rbegin() 
			{
				return _RBT.rbegin();
			};

			const_reverse_iterator rbegin() const 
			{
				return _RBT.rbegin();
			};

			reverse_iterator rend() 
			{
				return _RBT.rend();
			};

			const_reverse_iterator rend() const 
			{
				return _RBT.rend();
			};


			bool empty() const 
			{
				return _RBT.empty();
			};

			size_type size() const 
			{
				return _RBT.size();
			};
			
			size_type max_size() const 
			{
				return _alloc.max_size();
			};

			pair<iterator,bool> insert (const value_type& val)
			{
				_RBT.insert(val);
				iterator it = _RBT.find(val);
				if (it.get_node() != _RBT.get_nil())
					return ft::make_pair(it, 0);
				return ft::make_pair(it, 1);
			}

			iterator insert(iterator position, const value_type& val)
			{
				(void)position;
				_RBT.insert(val);
				iterator it = _RBT.find(val);
				return _RBT.find(val);
			};

			template <class InputIterator>
			void insert(InputIterator first, InputIterator last)
			{
				return _RBT.insert(first, last);
			};

			void erase(iterator position)
			{
				_RBT.erase(*position);
			};

			size_type erase(const value_type& x)
			{
				return _RBT.erase(x);
			};

			void erase(iterator first, iterator last)
			{
				return _RBT.erase(first, last);
			};

			void swap(set<T,Compare,Alloc>& other) {
				_RBT.swap(other._RBT);
				std::swap(_alloc, other._alloc);
				std::swap(_cmp, other._cmp);
			};

			void clear() {
				_RBT.clear();
			};

			key_compare key_comp() const
			{
				return key_compare();
			};

			key_compare value_comp() const
			{
				return value_compare(key_compare());
			};

			iterator find(const value_type& val)
			{
				return _RBT.find(val);
			};

			const_iterator find(const value_type& val) const
			{
				return _RBT.find(val);
			};

			size_type count(const value_type& val) const
			{
				return _RBT.count(val);
			};

			iterator lower_bound(const value_type& val)
			{
				return _RBT.lower_bound(val);
			};

			const_iterator lower_bound(const value_type& val) const
			{
				return _RBT.lower_bound(val);
			};

			iterator upper_bound(const value_type& val)
			{
				return _RBT.upper_bound(val);
			};

			const_iterator upper_bound(const value_type& val) const
			{
				return _RBT.upper_bound(val);
			};

			pair<iterator,iterator>	equal_range(const value_type& val) {
				return ft::make_pair(lower_bound(val), upper_bound(val));
			};

			pair<const_iterator,const_iterator>	equal_range(const value_type& val) const {
				return ft::make_pair(lower_bound(val), upper_bound(val));
			};
	};

	template <class T, class Compare, class Alloc>
	bool operator==(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template <class T, class Compare, class Alloc>
	bool operator< (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class T, class Compare, class Alloc>
	bool operator!=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return (!(lhs == rhs));
	};

	template <class T, class Compare, class Alloc>
	bool operator> (const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return (rhs < lhs);
	};

	template <class T, class Compare, class Alloc>
	bool operator>=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return (!(lhs < rhs));
	};

	template <class T, class Compare, class Alloc>
	bool operator<=(const set<T,Compare,Alloc>& lhs, const set<T,Compare,Alloc>& rhs) {
		return (!(rhs < lhs));
	};

	template <class T, class Compare, class Alloc>
	void swap(set<T,Compare,Alloc>& lhs, set<T,Compare,Alloc>& rhs) {
		lhs.swap(rhs);
	};

}

#endif