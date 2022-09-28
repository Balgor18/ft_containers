#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
# include "pair.hpp"
# include "Node.hpp"
# include "RBT.hpp"

namespace ft {
	
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
	class map
	{
		public:
			typedef Key															key_type;
			typedef T															mapped_type;
			typedef pair<const key_type, mapped_type>							value_type;
			typedef Compare														key_compare;
			typedef Allocator													allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef typename allocator_type::size_type							size_type;
			typedef typename allocator_type::difference_type					difference_type;

			typedef ft::RBT_iterator<value_type, ft::Node<value_type> >				iterator;
			typedef ft::RBT_iterator<const value_type, const ft::Node<value_type> >	const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;

			class value_compare
			{

				friend class map;
				protected:
					Compare	comp;
					value_compare (Compare c) : comp(c) {}
				public:
					typedef bool result_type;
					typedef value_type first_argument_type;
					typedef value_type second_argument_type;
					bool operator() (const value_type& x, const value_type& y) const
					{
						return comp(x.first, y.first);
					}
			};

		private :
			Red_black_tree<value_type>	_RBT;
			allocator_type				_alloc;
			key_compare					_cmp;

		public :
			// construct/copy/destroy:
			explicit map(const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _RBT(), _alloc(alloc), _cmp(comp){};

			template <class InputIterator>
			map(InputIterator first, InputIterator last, const Compare& comp = Compare(), const Allocator& alloc = Allocator()) : _RBT(), _alloc(alloc), _cmp(comp) {
				_RBT.insert(first, last);
			};

			map(const map<Key,T,Compare,Allocator>& cpy) : _RBT(cpy._RBT), _alloc(cpy._alloc), _cmp(cpy._cmp) {
				_RBT.insert(cpy.begin(), cpy.end());
			};

			~map() {};

			map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& lhs)
			{
				this->clear();

				const_iterator it = lhs.begin();
				while (it != lhs.end())
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

			iterator	begin()
			{
				return (_RBT.begin());
			}

			const_iterator	begin() const
			{
				return (_RBT.begin());
			}

			iterator	end()
			{
				return _RBT.end();
			}

			const_iterator	end() const
			{
				return _RBT.end();
			}

			reverse_iterator	rbegin()
			{
				return _RBT.rbegin();
			}

			const_reverse_iterator	rbegin() const
			{
				return _RBT.rbegin();
			}

			reverse_iterator	rend()
			{
				return _RBT.rend();
			}

			const_reverse_iterator	rend() const
			{
				return _RBT.rend();
			}

			bool	empty()
			{
				return _RBT.empty();
			}

			size_type	size() const
			{
				return _RBT.size();
			}

			size_type	max_size()
			{
				return _RBT.max_size();
			}

			mapped_type& operator[] (const key_type& k) {
				return (*((insert(ft::make_pair(k, mapped_type()))).first)).second;
				};

			pair<iterator,bool> insert (const value_type& val)
			{
				_RBT.insert(val);
				iterator it = _RBT.find(val);
				if (it.get_node() != _RBT.get_nil())
					return ft::make_pair(it, 0);
				return ft::make_pair(it, 1);
			}

			iterator insert (iterator position, const value_type& val)
			{
				(void)position;
				_RBT.insert(val);
				iterator it = _RBT.find(val);
				return _RBT.find(val);
			}
			
			template <class InputIterator>
			void insert (InputIterator first, InputIterator last)
			{
				return _RBT.insert(first, last);
			}

			void erase (iterator position)
			{
				return _RBT.erase(position);
			}

			size_type erase (const key_type& k)
			{
				return _RBT.erase(ft::make_pair(k, mapped_type()));
			}

			void erase (iterator first, iterator last)
			{
				return _RBT.erase(first, last);
			}

			void swap (map& other)
			{
				_RBT.swap(other._RBT);
				std::swap(_alloc, other._alloc);
				std::swap(_cmp, other._cmp);
			}

			void clear()
			{
				_RBT.clear();
			}

			size_type count(const key_type& key) const
			{
				return _RBT.count(ft::make_pair(key, mapped_type()));
			};

			iterator find( const Key& key )
			{
				return _RBT.find(ft::make_pair(key, mapped_type()));
			}

			const_iterator find( const Key& key ) const
			{
				return _RBT.find(ft::make_pair(key, mapped_type()));
			}

			pair<iterator,iterator> equal_range( const Key& key )
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}

			pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				return ft::make_pair(lower_bound(key), upper_bound(key));
			}

			iterator lower_bound( const Key& key )
			{
				return _RBT.lower_bound(ft::make_pair(key, mapped_type()));
			}

			const_iterator lower_bound( const Key& key ) const
			{
				return _RBT.lower_bound(ft::make_pair(key, mapped_type()));
			}

			iterator upper_bound( const Key& key )
			{
				return _RBT.upper_bound(ft::make_pair(key, mapped_type()));
			}

			const_iterator upper_bound( const Key& key ) const
			{
				return _RBT.upper_bound(ft::make_pair(key, mapped_type()));
			}

			key_compare key_comp() const
			{
				return key_compare();
			}

			value_compare value_comp() const
			{
				return value_compare(key_compare());
			}

	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator==(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator< (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator!=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return (!(lhs == rhs));
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator> (const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return (rhs < lhs);
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator>=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return (!(lhs < rhs));
	};

	template <class Key, class T, class Compare, class Alloc>
	bool operator<=(const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs) {
		return (!(rhs < lhs));
	};
}

#endif