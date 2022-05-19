#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <algorithm>
# include "iterator.hpp"
// # include "iterator_traits.hpp"
// # include "reverse_iterator.hpp"

// https://www.lirmm.fr/~ducour/Doc-objets/ISO+IEC+14882-1998.pdf
// https://fr.acervolima.com/std-allocator-en-c-avec-des-exemples/#:~:text=allocator%20est%20l%27allocateur%20de,pour%20au%20moins%20n%20%C3%A9l%C3%A9ments
// https://h-deb.clg.qc.ca/Sujets/Divers--cplusplus/SFINAE.html

// http://chenweixiang.github.io/docs/The_C++_Programming_Language_4th_Edition_Bjarne_Stroustrup.pdf
// https://code.woboq.org/gcc/libstdc++-v3/include/bits/stl_iterator.h.html

// http://www.cplusplus.com/reference/iterator/

namespace ft {
template <class T, class Allocator = std::allocator<T> >
	class vector {

		public:
		// types:

		typedef T									value_type;
		typedef Allocator							allocator_type;
		typedef std::size_t							size_type;
		typedef std::ptrdiff_t						difference_type;
		typedef typename Allocator::reference		reference;
		typedef typename Allocator::const_reference	const_reference;
		typedef typename Allocator::pointer			pointer;
		typedef typename Allocator::const_pointer	const_pointer;
		
		typedef ft::random_access_iterator<T>		iterator;
		typedef ft::random_access_iterator<const T>	const_iterator;
		// typedef ft::reverse_iterator<iterator> reverse_iterator;
		// typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;

		// 23.2.4.1 construct/copy/destroy:
		private :// Attribute
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			pointer	 		_ptr;
			// probably use 3 ptr (all people use 3 ptr) // the real one get only 3 ptr

		public :
			explicit vector(const Allocator& alloc= Allocator()) : _alloc(alloc), _size(0), _capacity(0) { };

			explicit vector(size_type n, const T& value = T(), const Allocator& alloc= Allocator()) : _alloc(alloc), _size(n), _capacity(n){
				_ptr = _alloc.allocate(n);
				for (size_type i = 0; i < n;i++){
						_alloc.construct(_ptr + i, value);
				}
			};

			// template <class InputIterator>
			// vector(InputIterator first, InputIterator last, const Allocator& = Allocator()){

			// };

			vector(const vector<T,Allocator>& x) : _alloc(x._alloc){
				_ptr = _alloc.allocate(x._capacity);
				for (size_type i = 0; i < x._size; i++)
				{
					_alloc.construct(_ptr + i, *(x._ptr + i));
				}
				_size = x._size;
				_capacity = x._capacity;
			};

			~vector() {
				clear();
				_alloc.deallocate(_ptr, _capacity);
			};

			// vector<T,Allocator>& operator=(const vector<T,Allocator>& x);

			// template <class InputIterator>
			// void assign(InputIterator first, InputIterator last);
			// void assign(size_type n, const T& u);

			allocator_type get_allocator() const { return (this->_alloc); };

			// iterators:

			iterator begin(void) {return (_ptr); };
			const_iterator begin(void) const { return (_ptr); };
			iterator end(void) { return (_ptr + _size); };
			const_iterator end(void) const { return (_ptr + _size); };
			reverse_iterator rbegin(void) {return (this->end()); };
			const_reverse_iterator rbegin(void) const { return (this->end());};
			reverse_iterator rend(void) { return (this->begin());};
			const_reverse_iterator rend(void) const {return (this->begin());};

			// 23.2.4.2 capacity:

			size_type size(void) const {return _size; };
			size_type max_size() const { return _alloc.max_size(); };
			size_type capacity(void) const { return _capacity; };
			bool empty() const { return _size == 0; };
			
			// void resize(size_type sz, T c = T());
			// void reserve(size_type n);

			// element access:

			// reference operator[](size_type n);
			// const_reference operator[](size_type n) const;
			// const_reference at(size_type n) const;
			// reference at(size_type n);
			// reference front();
			// const_reference front() const;
			// reference back();
			// const_reference back() const;

			// 23.2.4.3 modifiers:

			void push_back(const T& x) {
				if (!_size) {
					_ptr = _alloc.allocate(1);
					_alloc.construct(_ptr, x);
					_size++;
					_capacity = _size;
					return ;
				}
				else if (_size == _capacity) {
					pointer	tmp;
					tmp = _alloc.allocate(_size * 2);
					for (size_type i(0); i < _size; i++) {
						_alloc.construct(tmp + i, *(_ptr + i));
						_alloc.destroy(_ptr + i);
					}
					_alloc.deallocate(_ptr, _capacity);
					_capacity = (_size * 2);
					_size++;
					_ptr = tmp;
					return ;
				}
				_alloc.construct(_ptr + _size, x);
				_size++;
			};

			// void pop_back();
			// iterator insert(iterator position, const T& x);
			// void insert(iterator position, size_type n, const T& x);
			// template <class InputIterator>
			// void insert(iterator position, InputIterator first, InputIterator last);
			// iterator erase(iterator position);
			// iterator erase(iterator first, iterator last);
			// void swap(vector<T,Allocator>&);

			void clear(void) {
				for (size_type i = 0; i < _size; i++)
				{
					_alloc.destroy(_ptr + i);
				}
				_size = 0;
			};
	};
};

#endif
// https://www.guru99.com/cpp-vector-stl.html
