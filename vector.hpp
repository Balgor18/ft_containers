#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <iostream>
# include <algorithm>
# include "iterator.hpp"
# include "enable_if.hpp"
# include "is_integral.hpp"
# include "lexicographical_compare.hpp"

namespace ft {
template <class T, class Allocator = std::allocator<T> >
	class vector {

		public:
		// types:

		typedef T										value_type;
		typedef Allocator								allocator_type;
		typedef std::size_t								size_type;
		typedef std::ptrdiff_t							difference_type;
		typedef typename Allocator::reference			reference;
		typedef typename Allocator::const_reference		const_reference;
		typedef typename Allocator::pointer				pointer;
		typedef typename Allocator::const_pointer		const_pointer;
		
		typedef ft::random_access_iterator<T>			iterator;
		typedef ft::random_access_iterator<const T>		const_iterator;
		typedef ft::reverse_iterator<iterator>			reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

		// 23.2.4.1 construct/copy/destroy:
		private :// Attribute
			allocator_type	_alloc;
			size_type		_size;
			size_type		_capacity;
			pointer	 		_ptr;

		public :
			explicit vector(const Allocator& alloc= Allocator()) : _alloc(alloc), _size(0), _capacity(0), _ptr(NULL) {
			};

			explicit vector(size_type n, const T& value = T(), const Allocator& alloc= Allocator()) : _alloc(alloc), _size(n), _capacity(n){
				_ptr = _alloc.allocate(n);
				for (size_type i = 0; i < n;i++){
						_alloc.construct(_ptr + i, value);
				}
			};

			template <class InputIterator>
			vector(InputIterator first, InputIterator last, const Allocator& alloc= Allocator(), typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0): _alloc(alloc), _size(0), _capacity(0), _ptr(NULL){
				assign(first, last);
			};

			vector(const vector<T,Allocator>& x) : _alloc(x._alloc), _size(x._size), _capacity(0), _ptr(NULL){
				if (x._size == 0)
					return ;
				_ptr = _alloc.allocate(x._size);
				for (size_type i = 0; i < x._size; i++)
					_alloc.construct(_ptr + i, *(x._ptr + i));
				_size = x._size;
				_capacity = x._size;
			};

			~vector() {
				clear();
				if (_capacity > 0)
					_alloc.deallocate(_ptr, _capacity);
			};

			vector<T,Allocator>& operator=(const vector<T,Allocator>& rhs) {
				if (this != &rhs)
					assign(rhs.begin(), rhs.end());
				return (*this);
			};

			void assign(size_type n, const T& u) {
				erase(this->begin(), this->end());
				insert(this->begin(), n, u);
			};

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last,
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0) {
				erase(this->begin(), this->end());
				insert(begin(), first, last);
			};

			allocator_type get_allocator() const {
				return (this->_alloc);
			};

			// iterators:

			iterator begin(void) {
				return (iterator(_ptr));
			};
			const_iterator begin(void) const {
				return (const_iterator(_ptr));
			};

			iterator end(void) {
				return (iterator(_ptr + _size));
			};
			const_iterator end(void) const {
				return const_iterator((_ptr + _size));
			};

			reverse_iterator rbegin(void) {
				return (reverse_iterator(this->end()));
			};
			const_reverse_iterator rbegin(void) const {
				return (const_reverse_iterator(this->end()));
			};

			reverse_iterator rend(void) {
				return (reverse_iterator(this->begin()));
			};
			const_reverse_iterator rend(void) const {
				return (const_reverse_iterator(this->begin()));
			};

			// 23.2.4.2 capacity:

			size_type size(void) const {
				return (_size);
			};
			size_type max_size() const {
				return (_alloc.max_size());
			};
			size_type capacity(void) const {
				return (_capacity);
			};
			bool empty() const {
				return (_size == 0);
			};

			void resize(size_type n, T c = T()){
				if (n < _size)
					erase(begin() + n, end());
				else if (n > _size)
				{
					if (n > _size *2)
						reserve(n);
					else
						reserve(_size *2);
					while (_size < n)
						push_back(c);
					_size = n;
				}
			};

			void reserve(size_type n){
				if (n > this->max_size())
					throw std::length_error("vector::reserve");
				if (n <= capacity())
					return;
				else {
					pointer	tmp = _alloc.allocate(n);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(tmp + i, *(_ptr + i));
						_alloc.destroy(_ptr + i);
					}
					_alloc.deallocate(_ptr, _capacity);
					_capacity = n;
					_ptr = tmp;
				}
			};
		
			// element access:

			reference operator[]( size_type n ) {
				return *(this->begin() + n);
			};

			const_reference operator[]( size_type n ) const {
				return *(this->begin() + n);
			};

			const_reference at(size_type n) const{
				if (n > _size)
					throw std::out_of_range("Vector at");
				return *(_ptr + n);
			};
			reference at(size_type n){
				if (n > _size)
					throw std::out_of_range("Vector at");
				return *(_ptr + n);
			};

			reference front() {
				return *(this->begin());
			};

			const_reference front() const {
				return *(this->begin());
			};

			reference back() {
				return *(--this->end());
			};

			const_reference back() const {
				return *(--this->end());
			};

			// 23.2.4.3 modifiers:

			void push_back(const T& x) {
				if (!_size && !_capacity) {
					_ptr = _alloc.allocate(1);
					_alloc.construct(_ptr, x);
					_size++;
					_capacity = _size;
					return ;
				}
				else if (_size == _capacity) {
					pointer	tmp;
					tmp = _alloc.allocate(_size * 2);
					for (size_type i = 0; i < _size; i++) {
						_alloc.construct(tmp + i, *(_ptr + i));
						_alloc.destroy(_ptr + i);
					}
					_alloc.deallocate(_ptr, _capacity);
					_capacity = (_size * 2);
					_alloc.construct(tmp + _size, x);
					_size++;
					_ptr = tmp;
					return ;
				}
				_alloc.construct(_ptr + _size, x);
				_size++;
			};

			void pop_back(void){
				_alloc.destroy(&this->back());
				_size--;
			};

			iterator insert(iterator pos, const T& x){
				difference_type dist = pos - this->begin();

				if (_capacity == _size && _capacity != 0) {
					reserve(2 * _capacity);
				}
				else if (!_capacity)
					reserve(1);
				for (difference_type j = _size; j > dist; j--) {
					_alloc.construct(_ptr + j, _ptr[j - 1]);
				}
				_alloc.construct(_ptr + dist, x);
				_size++;
				return this->begin() + dist;
			};

			void insert(iterator pos, size_type n, const T& x){
				difference_type dist = pos - this->begin();

				if (n == 0)
					return ;
				if (_capacity < _size + n && _size * 2 >= _size + n) 
						reserve(2 * _size);
				else
					reserve(_size + n);
				for (difference_type i = _size - 1; i >= dist; i--) {
					_alloc.construct(_ptr + n + i, _ptr[i]);
					_alloc.destroy(_ptr + i);
				}
				_size += n;
				for (size_type j = 0; j < n; j++) {
					_alloc.construct(_ptr + j + dist, x);
				}
			};

			template <class InputIterator>
			void insert(iterator pos, InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = 0){
				difference_type dist = pos - this->begin();
				size_type it_dist = 0;
				size_type last_size = this->_size;
				InputIterator it = first;

				while (it != last) {
					it_dist++;
					it++;
				}
				if (this->_capacity < this->_size + it_dist && this->_size * 2 > this->_size + it_dist)
					reserve(2 * this->_size);
				else
					reserve(this->_size + it_dist);
				for (difference_type i = last_size - 1; i >= dist ; i--) {
					this->_alloc.construct(&_ptr[it_dist + i], _ptr[i]);
					this->_alloc.destroy(_ptr + i);
				}
				for (size_type j = 0; first != last; j++){
					this->_alloc.construct(&_ptr[j + dist], *first);
					first++;
					_size++;
				}
			};

			iterator erase(iterator pos){
				iterator	it = this->begin();
				size_type	dist = pos - it;
				size_type	i = dist;
				while (it + dist != this->end() - 1) {
					i++;
					_ptr[i - 1] = _ptr[i];
					it++;	
				}
				this->pop_back();
				return (this->begin() + dist);
			};

			iterator erase(iterator first, iterator last){
				iterator	iterato = this->begin();
				size_type	i = 0;
				for (;iterato != first; iterato++)
					i++;
				for (;first != last;first++)
					erase(iterato);
				return (this->begin() + i);
			};
			
			void swap(vector<T,Allocator> &x) {
				std::swap(_size, x._size);
				std::swap(_capacity, x._capacity);
				std::swap(_ptr, x._ptr);
			};

			void clear(void) {
				if (_capacity == 0)
					return ;
				for (size_type i = 0; i < _size; i++)
					_alloc.destroy(_ptr + i);
				_size = 0;
			};

	};

	template< class T, class Alloc >
	void swap( ft::vector<T,Alloc>& lhs, ft	::vector<T,Alloc>& rhs ) {
		lhs.swap(rhs);
	};

	template <class T, class Allocator>
	bool operator==(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
		if (lhs.size() != rhs.size())
			return false;
		for (size_t j = 0; j < lhs.size(); j++) {
			if (lhs.at(j) != rhs.at(j))
				return false;
		}
		return true;
	};

	template <class T, class Allocator>
	bool operator< (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	};

	template <class T, class Allocator>
	bool operator!=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
		return (!(lhs == rhs));
	};

	template <class T, class Allocator>
	bool operator> (const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
		return (rhs < lhs);
	};

	template< class T, class Alloc >
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs ) {
		return (!(lhs < rhs));
	}

	template <class T, class Allocator>
	bool operator<=(const vector<T,Allocator>& lhs, const vector<T,Allocator>& rhs) {
		return (!(rhs < lhs));
	};

};

#endif

