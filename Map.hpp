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
			typedef Key											key_type;
			typedef T											mapped_type;
			typedef pair<const key_type, mapped_type>			value_type;
			typedef Compare										key_compare;
			typedef Allocator									allocator_type;
			typedef typename allocator_type::reference			reference;
			typedef typename allocator_type::const_reference	const_reference;
			typedef typename allocator_type::pointer			pointer;
			typedef typename allocator_type::const_pointer		const_pointer;
			typedef typename allocator_type::size_type			size_type;
			typedef typename allocator_type::difference_type	difference_type;

			typedef RBT_iterator<T, ft::Node<T> >				iterator;
			typedef RBT_iterator<const T, const ft::Node<T> >	const_iterator;
			typedef ft::reverse_iterator<iterator>				reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

			class value_compare
			{

				friend class map;
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

			map(const map<Key,T,Compare,Allocator>& x) : _RBT(x._RBT), _alloc(x._alloc), _cmp(x._cmp) {
				_RBT.insert(x.begin(), x.end());
			};

			~map() {};

			map<Key,T,Compare,Allocator>& operator=(const map<Key,T,Compare,Allocator>& x) {
			const_iterator it = x.begin();

				this->clear();
				while (it != x.end())
				{
					insert(*it);
					 it++;
				}
				return *this;
			};

			allocator_type get_allocator() const { return _alloc; };

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

			size_type	size()
			{
				return _RBT.size();
			}

			size_type	max_size()
			{
				return _RBT.max_size();
			}

			// DBG Check
			mapped_type& operator[] (const key_type& k) {
				return (*((insert(ft::make_pair(k, T()))).first)).second;
				};

			// TODO AT

			pair<iterator,bool> insert (const value_type& val)
			{
				return _RBT.insert(val);
			}

			iterator insert (iterator position, const value_type& val)
			{
				return _RBT.insert(position, val);
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
				return _RBT.erase(k);
			}

			void erase (iterator first, iterator last)
			{
				return _RBT.erase(first, last);
			}

			void swap (map& x)
			{
				return _RBT.swap(x);
			}

			void clear()
			{
				_RBT.clear();
			}

			size_type count( const Key& key ) const
			{
				return _RBT.count(key);
			}

			iterator find( const Key& key )
			{
				return _RBT.find(key);
			}

			const_iterator find( const Key& key ) const
			{
				return _RBT.find(key);
			}

			std::pair<iterator,iterator> equal_range( const Key& key )
			{
				return _RBT.equal_range(key);
			}

			std::pair<const_iterator,const_iterator> equal_range( const Key& key ) const
			{
				return _RBT.equal_range(key);
			}

			iterator lower_bound( const Key& key )
			{
				return _RBT.lower_bound(key);
			}

			const_iterator lower_bound( const Key& key ) const
			{
				return _RBT.lower_bound(key);
			}

			iterator upper_bound( const Key& key )
			{
				return _RBT.upper_bound(key);
			}

			const_iterator upper_bound( const Key& key ) const
			{
				return _RBT.upper_bound(key);
			}

			key_compare key_comp() const
			{
				return _RBT.key_comp();
			}

			value_compare value_comp() const
			{
				return _RBT.value_comp();
			}

	};

	template< class Key, class T, class Compare, class Alloc >
	bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs._RBT == lhs._RBT);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (!(rhs._RBT == lhs._RBT));
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs._RBT < lhs._RBT);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs._RBT <= lhs._RBT);
	}

	template< class Key, class T, class Compare, class Alloc >
	bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs._RBT > lhs._RBT);
	}
	template< class Key, class T, class Compare, class Alloc >
	bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs,
					const ft::map<Key,T,Compare,Alloc>& rhs )
	{
		return (rhs._RBT >= lhs._RBT);
	}
}

#endif