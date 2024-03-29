#ifndef ITERATOR_HPP
# define ITERATOR_HPP

# include <iterator>
# include <cstddef>
namespace ft{

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag: public input_iterator_tag { };
	struct bidirectional_iterator_tag: public forward_iterator_tag { };
	struct random_access_iterator_tag: public bidirectional_iterator_tag { };

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct Iterator {
		public:
			typedef Category				iterator_category;
			typedef T						value_type;
			typedef Distance				difference_type;
			typedef Pointer					pointer;
			typedef	Reference				reference;
			typedef	const Reference			const_reference;
	};

	template <class Iterator>
	class iterator_traits {
		public :
			typedef typename Iterator::difference_type			difference_type;
			typedef typename Iterator::value_type				value_type;
			typedef typename Iterator::pointer					pointer;
			typedef typename Iterator::reference				reference;
			typedef typename Iterator::iterator_category		iterator_category;
	};

	template <class T>
	class iterator_traits<T*> {
		public :
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef T*								pointer;
			typedef T&								reference;
			typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	class iterator_traits<const T*> {
		public :
			typedef std::ptrdiff_t					difference_type;
			typedef T								value_type;
			typedef const T*						pointer;
			typedef const T&						reference;
			typedef ft::random_access_iterator_tag	iterator_category;
	};

};

namespace ft{
	template<typename T>
	class random_access_iterator {
		public:
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::value_type				value_type;
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::iterator_category			iterator_category;
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::difference_type			difference_type;
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::reference					reference;
			typedef typename ft::Iterator<ft::random_access_iterator_tag, T>::pointer					pointer;
		protected:
			pointer	current;
		public :
			random_access_iterator() : current(0) {
				return ;
			};

			explicit random_access_iterator(pointer x) : current(x) {
				return ;
			};

			template <class U>
			random_access_iterator(const random_access_iterator<U> &u) : current(u.base()) {
				return ;
			};

			pointer base() const {
				return (current);
			};

			reference operator*() const {
				return (*current);
			};

			pointer operator->() const {
				return &(operator*());
			};

			template <class U>
			random_access_iterator& operator=(const random_access_iterator<U> &u) {
				current = u.base();
				return *this;
			};

			random_access_iterator& operator++() {
				++current;
				return *this;
			};

			random_access_iterator operator++(int) {
				random_access_iterator tmp = *this;
				++current;
				return tmp;
			};

			random_access_iterator& operator--() {
				--current;
				return *this;
			};

			random_access_iterator operator--(int) {
				random_access_iterator tmp = *this;
				--current;
				return tmp;
			};

			random_access_iterator operator+(const difference_type n) const {
				return random_access_iterator(current + n);
			};

			difference_type operator+(const random_access_iterator& n) const {
				return (this->current + n.current);
			};

			random_access_iterator operator-(const difference_type n) const {
				return random_access_iterator(current - n);
			};

			difference_type operator-(const random_access_iterator& n) const {
				return (this->current - n.current);
			};

			random_access_iterator& operator+=(difference_type n) {
				current += n;
				return *this;
			};

			random_access_iterator& operator-=(difference_type n) {
				current -= n;
				return *this;
			};

			reference operator[](difference_type n) const {
				return *(current + n);
			};
	};

	template<class T1, class T2>
	bool	operator<(const random_access_iterator<T1>& lrs, const random_access_iterator<T2>& rhs){
		return (lrs.base() < rhs.base());
	}

	template<class T>
	bool	operator<(const random_access_iterator<T>& lrs, const random_access_iterator<T>& rhs){
		return (lrs.base() < rhs.base());
	}

	template<class T1, class T2>
	bool	operator>(const random_access_iterator<T1>& lrs, const random_access_iterator<T2>& rhs){
		return (lrs.base() > rhs.base());
	}

	template<class T>
	bool	operator>(const random_access_iterator<T>& lrs, const random_access_iterator<T>& rhs){
		return (lrs.base() > rhs.base());
	}

	template<class T1, class T2>
	bool	operator<=(const random_access_iterator<T1>& lrs, const random_access_iterator<T2>& rhs){
		return (lrs.base() <= rhs.base());
	}

	template<class T>
	bool	operator<=(const random_access_iterator<T>& lrs, const random_access_iterator<T>& rhs){
		return (lrs.base() <= rhs.base());
	}

	template<class T1, class T2>
	bool	operator>=(const random_access_iterator<T1>& lrs, const random_access_iterator<T2>& rhs){
		return (lrs.base() >= rhs.base());
	}

	template<class T>
	bool	operator>=(const random_access_iterator<T>& lrs, const random_access_iterator<T>& rhs){
		return (lrs.base() >= rhs.base());
	}

	template<class T1, class T2>
	bool	operator+=(const random_access_iterator<T1>& lrs, const random_access_iterator<T2>& rhs){
		return (lrs.base() += rhs.base());
	}

	template<class T>
	bool	operator+=(const random_access_iterator<T>& lrs, const random_access_iterator<T>& rhs){
		return (lrs.base() += rhs.base());
	}

	template<class T1, class T2>
	bool	operator-=(const random_access_iterator<T1>& lrs, const random_access_iterator<T2>& rhs){
		return (lrs.base() -= rhs.base());
	}

	template<class T>
	bool	operator-=(const random_access_iterator<T>& lrs, const random_access_iterator<T>& rhs){
		return (lrs.base() -= rhs.base());
	}

	template<class T1, class T2>
	bool	operator==(const random_access_iterator<T1>& lrs, const random_access_iterator<T2>& rhs){
		return (lrs.base() == rhs.base());
	}

	template<class T>
	bool	operator==(const random_access_iterator<T>& lrs, const random_access_iterator<T>& rhs){
		return (lrs.base() == rhs.base());
	}
	
	template<class T1, class T2>
	bool	operator!=(const random_access_iterator<T1>& lrs, const random_access_iterator<T2>& rhs){
		return (lrs.base() != rhs.base());
	}

	template<class T>
	bool	operator!=(const random_access_iterator<T>& lrs, const random_access_iterator<T>& rhs){
		return (lrs.base() != rhs.base());
	}

	template <class T1, class T2>
	typename random_access_iterator<T1>::difference_type operator-(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) {
		return (lhs.base() - rhs.base());
	};
	
	template <class T>
	typename random_access_iterator<T>::difference_type operator-(const random_access_iterator<T>& lhs, const random_access_iterator<T>& rhs) {
		return random_access_iterator<T> (lhs.base() - rhs.base());
	};

	template <class T1, class T2>
	typename random_access_iterator<T1>::difference_type operator+(const random_access_iterator<T1>& lhs, const random_access_iterator<T2>& rhs) {
		return (lhs.base() + rhs.base());
	};

	template <class T>
	random_access_iterator<T> operator+(typename random_access_iterator<T>::difference_type lhs, const random_access_iterator<T>& rhs) {
		return random_access_iterator<T> (rhs.base() + lhs);
	};
};


namespace ft{
	// Revese iterator
	template<typename _Iterator>
	class reverse_iterator {
		protected:
			_Iterator								current;
			// typedef iterator_traits<_Iterator>	__traits_type;
		public:
			typedef _Iterator 													iterator_type;
			typedef typename iterator_traits<_Iterator>::iterator_category		iterator_category;
			typedef typename iterator_traits<_Iterator>::value_type				value_type;
			typedef typename iterator_traits<_Iterator>::difference_type		difference_type;
			typedef typename iterator_traits<_Iterator>::pointer				pointer;
			typedef typename iterator_traits<_Iterator>::reference				reference;

			/**
			 *  The default constructor value-initializes member @p current.
			 *  If it is a pointer, that means it is zero-initialized.
			 */
			reverse_iterator() : current() { };

			/**
			 *  This %iterator will move in the opposite direction that @p x does.
			 */
			explicit reverse_iterator(iterator_type __x) : current(__x) { };

			/**
			 *  A %reverse_iterator across other types can be copied if the
			 *  underlying %iterator can be converted to the type of @c current.
			 */
			template<typename _Iter>
			reverse_iterator(const reverse_iterator<_Iter>& __x): current(__x.base()) { } ;

			/**
			 *  @return  @c current, the %iterator used for underlying work.
			 */
			iterator_type base() const { return current; };

			/**
			 *  @return  A reference to the value at @c --current
			 *
			 *  This requires that @c --current is dereferenceable.
			 *
			 *  @warning This implementation requires that for an iterator of the
			 *           underlying iterator type, @c x, a reference obtained by
			 *           @c *x remains valid after @c x has been modified or
			 *           destroyed. This is a bug: http://gcc.gnu.org/PR51823
			 */
			reference operator*() const {
				_Iterator __tmp = current;
				return *--__tmp;
			}

			/**
			 *  @return  A pointer to the value at @c --current
			 *
			 *  This requires that @c --current is dereferenceable.
			 */
			pointer operator->() const { return &(operator*()); };

			/**
			 *  @return  @c *this
			 *
			 *  Decrements the underlying iterator.
			 */
			reverse_iterator&	operator++() {
				--current;
				return *this;
			};

			/**
			 *  @return  The original value of @c *this
			 *
			 *  Decrements the underlying iterator.
			 */
			reverse_iterator operator++(int) {
				reverse_iterator __tmp = *this;
				--current;
				return __tmp;
			};

			/**
			 *  @return  @c *this
			 *
			 *  Increments the underlying iterator.
			 */
			reverse_iterator& operator--() {
				++current;
				return *this;
			};

			/**
			 *  @return  A reverse_iterator with the previous value of @c *this
			 *
			 *  Increments the underlying iterator.
			 */
			reverse_iterator operator--(int) {
				reverse_iterator __tmp = *this;
				++current;
				return __tmp;
			};

			/**
			 *  @return  A reverse_iterator that refers to @c current - @a __n
			 *
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			reverse_iterator operator+(difference_type __n) const { return reverse_iterator(current - __n); };

			/**
			 *  @return  *this
			 *
			 *  Moves the underlying iterator backwards @a __n steps.
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			reverse_iterator& operator+=(difference_type __n) {
				current -= __n;
				return *this;
			};

			/**
			 *  @return  A reverse_iterator that refers to @c current - @a __n
			 *
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			reverse_iterator operator-(difference_type __n) const { return reverse_iterator(current + __n); };

			difference_type operator-(const reverse_iterator<_Iterator>& rhs) { return (rhs.base() - this->current); };

			/**
			 *  @return  *this
			 *
			 *  Moves the underlying iterator forwards @a __n steps.
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			reverse_iterator& operator-=(difference_type __n) {
				current += __n;
				return *this;
			};

			/**
			 *  @return  The value at @c current - @a __n - 1
			 *
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			reference operator[](difference_type __n) const {
				return *(*this + __n);
			};
	};

	template<typename _Iterator>
	bool operator==(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y) {
		return __x.base() == __y.base();
	}


	template <class Iterator1, class Iterator2>
	bool operator==(const ft::reverse_iterator<Iterator1>& __x, const ft::reverse_iterator<Iterator2>& __y) {
		return (__x.base() == __y.base());
	}

	template<typename _Iterator>
	bool operator!=(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y) {
		return !(__x == __y);
	}

	template <class Iterator1, class Iterator2>
	bool operator!=(const ft::reverse_iterator<Iterator1>& __x, const ft::reverse_iterator<Iterator2>& __y) {
		return (!(__x == __y));
	}

	template<typename _Iterator>
	bool operator<(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y) {
		return __y.base() < __x.base();
	}

	template <class Iterator1, class Iterator2>
	bool operator<(const ft::reverse_iterator<Iterator1>& __x, const ft::reverse_iterator<Iterator2>& __y) {
		return (__y.base() < __x.base());
	}

	template<typename _Iterator>
	bool operator>(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y) {
		return (__y < __x);
	}

	template <class Iterator1, class Iterator2>
	bool operator>(const ft::reverse_iterator<Iterator1>& __x, const ft::reverse_iterator<Iterator2>& __y) {
		return (__y < __x);
	}

	template<typename _Iterator>
	bool operator<=(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y) {
		return !(__y < __x);
	}

	template <class Iterator1, class Iterator2>
	bool operator<=(const ft::reverse_iterator<Iterator1>& __x, const ft::reverse_iterator<Iterator2>& __y) {
		return !(__y < __x);
	}

	template<typename _Iterator>
	bool operator>=(const reverse_iterator<_Iterator>& __x, const reverse_iterator<_Iterator>& __y) {
		return !(__x < __y);
	}

	template <class Iterator1, class Iterator2>
	bool operator>=(const ft::reverse_iterator<Iterator1>& __x, const ft::reverse_iterator<Iterator2>& __y) {
		return (!(__x < __y));
	}

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, const reverse_iterator<Iterator> &rev_it) {
		return(rev_it + n);
	}

};
#endif