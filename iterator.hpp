#ifndef ITERATOR_HPP
# define ITERATOR_HPP

namespace ft{

	struct input_iterator_tag { };
	struct output_iterator_tag { };
	struct forward_iterator_tag: public input_iterator_tag { };
	struct bidirectional_iterator_tag: public forward_iterator_tag { };
	struct random_access_iterator_tag: public bidirectional_iterator_tag { };

	template <class _Iterator>
	struct iterator_traits {
		typedef typename Iterator::iterator_category	iterator_category;//if its a random _access
		typedef typename Iterator::value_type			value_type; // the type point ex : int
		typedef typename Iterator::difference_type		difference_type;// diff space btw two type ex : int for next int is 4 octets
		typedef typename Iterator::pointer				pointer;// *
		typedef typename Iterator::reference			reference;// &
	};

	template <class T>
	struct iterator_traits<T*> {
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef T*								pointer;
		typedef T&								reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*> {
		typedef std::ptrdiff_t					difference_type;
		typedef T								value_type;
		typedef const T*						pointer;
		typedef const T&						reference;
		typedef ft::random_access_iterator_tag	iterator_category;
	};

	template <class Category, class T, class diff_btw = std::ptrdiff_t, class Pointer = T*, class Reference = T&>
	struct iterator {
			typedef T							value_type;
			typedef diff_btw					difference_type;
			typedef Pointer						pointer;
			typedef Reference					reference;
			typedef Category					iterator_category;
	};
};

namespace ft{
	// class RandomAccessIterator
	template<typename T>
	class random_access_iterator {
		public:
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::value_type			value_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::iterator_category		iterator_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::difference_type		difference_type;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::reference				reference;
			typedef typename ft::iterator<ft::random_access_iterator_tag, T>::pointer				pointer;
		protected:
			pointer	current;
		public :
			random_access_iterator() : current(0) { return ; };

			explicit random_access_iterator(pointer x) : current(x) { return ; };

			template <class U>
			random_access_iterator(const random_access_iterator<U> &u) : current(u.base()) { return ;};

			pointer base() const { return current; };

			reference operator*() const { return *current; };

			pointer operator->() const { return &(operator*()); };

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

			random_access_iterator operator+(difference_type n) const {
				random_access_iterator tmp(*this);
				return (tmp += n);
			};

			random_access_iterator operator-(difference_type n) const {
				random_access_iterator tmp(*this);
				return (tmp -= n);
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
// <
// >
// <=
// >=
// +=
// -=
// =
};


namespace ft{
	// Revese iterator
	template<typename _Iterator>
	class reverse_iterator : public ft::iterator<typename iterator_traits<_Iterator>::iterator_category,
						typename iterator_traits<_Iterator>::value_type,
						typename iterator_traits<_Iterator>::difference_type,
						typename iterator_traits<_Iterator>::pointer,
						typename iterator_traits<_Iterator>::reference> {
		protected:
			_Iterator							current;
			typedef iterator_traits<_Iterator>	__traits_type;
		public:
			typedef _Iterator										iterator_type;
			typedef typename __traits_type::difference_type			difference_type;
			typedef typename __traits_type::pointer					pointer;
			typedef typename __traits_type::reference				reference;

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
			 *  The copy constructor is normal.
			 */
			reverse_iterator(const reverse_iterator& __x) : current(__x.current) { };

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
};
#endif