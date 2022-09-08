#ifndef MAP_HPP
# define MAP_HPP

# include <functional>
namespace ft {
	
	template <class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T>>>
	class map
	{
	public:
		// types:
		typedef Key                                      key_type;
		typedef T                                        mapped_type;
		typedef pair<const key_type, mapped_type>        value_type;
		typedef Compare                                  key_compare;
		typedef Allocator                                allocator_type;
		typedef typename allocator_type::reference       reference;
		typedef typename allocator_type::const_reference const_reference;
		typedef typename allocator_type::pointer         pointer;
		typedef typename allocator_type::const_pointer   const_pointer;
		typedef typename allocator_type::size_type       size_type;
		typedef typename allocator_type::difference_type difference_type;

		typedef implementation-defined                   iterator;
		typedef implementation-defined                   const_iterator;
		typedef std::reverse_iterator<iterator>          reverse_iterator;
		typedef std::reverse_iterator<const_iterator>    const_reverse_iterator;

		// construct/copy/destroy:
		map()
			noexcept(
				is_nothrow_default_constructible<allocator_type>::value &&
				is_nothrow_default_constructible<key_compare>::value &&
				is_nothrow_copy_constructible<key_compare>::value);
		explicit map(const key_compare& comp);
		map(const key_compare& comp, const allocator_type& a);
		template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp = key_compare());
		template <class InputIterator>
			map(InputIterator first, InputIterator last,
				const key_compare& comp, const allocator_type& a);
		map(const map& m);
		map(map&& m)
			noexcept(
				is_nothrow_move_constructible<allocator_type>::value &&
				is_nothrow_move_constructible<key_compare>::value);
		explicit map(const allocator_type& a);
		map(const map& m, const allocator_type& a);
		map(map&& m, const allocator_type& a);
		map(initializer_list<value_type> il, const key_compare& comp = key_compare());
		map(initializer_list<value_type> il, const key_compare& comp, const allocator_type& a);
	~map();

		map& operator=(const map& m);
		map& operator=(map&& m)
			noexcept(
				allocator_type::propagate_on_container_move_assignment::value &&
				is_nothrow_move_assignable<allocator_type>::value &&
				is_nothrow_move_assignable<key_compare>::value);
		map& operator=(initializer_list<value_type> il);

		// iterators:
		iterator begin() ;
		const_iterator begin() const ;
		iterator end() ;
		const_iterator end()   const ;

		reverse_iterator rbegin() ;
		const_reverse_iterator rbegin() const ;
		reverse_iterator rend() ;
		const_reverse_iterator rend()   const ;

		const_iterator         cbegin()  const ;
		const_iterator         cend()    const ;
		const_reverse_iterator crbegin() const ;
		const_reverse_iterator crend()   const ;

		// capacity:
		bool	empty()	const
		{
				return (_size ? 0 : 1);
		};

		size_type	size(void) const
		{
			return _size;
		}

		size_type	max_size(void) const
		{
			return _alloc.max_size();
		}

		// element access:
		mapped_type& operator[](const key_type& k);
		mapped_type& operator[](key_type&& k);

			mapped_type& at(const key_type& k);
		const mapped_type& at(const key_type& k) const;

		// modifiers:
		template <class... Args>
			pair<iterator, bool> emplace(Args&&... args);

		template <class... Args>
		iterator emplace_hint(const_iterator position, Args&&... args);

		pair<iterator, bool> insert(const value_type& v);

		template <class P>
		pair<iterator, bool> insert(P&& p);

		iterator insert(const_iterator position, const value_type& v);
		template <class P>
		iterator insert(const_iterator position, P&& p);

		template <class InputIterator>
		void insert(InputIterator first, InputIterator last);

		void insert(initializer_list<value_type> il);

		iterator  erase(const_iterator position);
		size_type erase(const key_type& k);
		iterator  erase(const_iterator first, const_iterator last);
		void clear() noexcept;

		// observers:
		allocator_type get_allocator() const
		{
			return _alloc;
		};

		key_compare	key_comp()	const
		{
			return key_compare();
		};

		value_compare  value_comp()    const;

		// map operations:
		iterator find(const key_type& k)
		{
			// Node	*tmp;

			// tmp = _root;
			// while (tmp != _NIL)
			// {
			// 	std::cout << "key_comp " << key_comp(to_find, tmp->data) << std::endl;
			// 	if (to_find < tmp->data)// MEMO Si plus petit alors go cote gauche
			// 	{
					
			// 	}
			// 	else
			// 	{

			// 	}
			// }
			// return _NIL;
		}




		const_iterator find(const key_type& k) const;

		size_type      count(const key_type& k) const;


			iterator lower_bound(const key_type& k);
		const_iterator lower_bound(const key_type& k) const;

			iterator upper_bound(const key_type& k);
		const_iterator upper_bound(const key_type& k) const;

		pair<iterator,iterator>             equal_range(const key_type& k);
		pair<const_iterator,const_iterator> equal_range(const key_type& k) const;
	};

	template <class Key, class T, class Compare, class Allocator>
	bool	operator==(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator< (const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator!=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator> (const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator>=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	template <class Key, class T, class Compare, class Allocator>
	bool	operator<=(const map<Key, T, Compare, Allocator>& x,
			const map<Key, T, Compare, Allocator>& y);

	// specialized algorithms:
	template <class Key, class T, class Compare, class Allocator>
	void
	swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y)
		noexcept(noexcept(x.swap(y)));

}

#endif