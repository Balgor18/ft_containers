#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

namespace ft {
	template<typename _Iterator>
	class random_access_iterator : public ft::iterator<typename iterator_traits<_Iterator>::iterator_category,
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
			random_access_iterator() : current() { };

			/**
			 *  This %iterator will move in the opposite direction that @p x does.
			 */
			explicit random_access_iterator(iterator_type __x) : current(__x) { };

			/**
			 *  The copy constructor is normal.
			 */
			random_access_iterator(const random_access_iterator& __x) : current(__x.current) { };

			/**
			 *  A %random_access_iterator across other types can be copied if the
			 *  underlying %iterator can be converted to the type of @c current.
			 */
			template<typename _Iter>
			random_access_iterator(const random_access_iterator<_Iter>& __x): current(__x.base()) { } ;

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
			// reference operator*() const {
			// 	_Iterator __tmp = current;
			// 	return *--__tmp;
			// }

			/**
			 *  @return  A pointer to the value at @c --current
			 *
			 *  This requires that @c --current is dereferenceable.
			 */
			// pointer operator->() const { return &(operator*()); };

			/**
			 *  @return  @c *this
			 *
			 *  Decrements the underlying iterator.
			 */
			// random_access_iterator&	operator++() {
			// 	--current;
			// 	return *this;
			// };

			/**
			 *  @return  The original value of @c *this
			 *
			 *  Decrements the underlying iterator.
			 */
			// random_access_iterator operator++(int) {
			// 	random_access_iterator __tmp = *this;
			// 	--current;
			// 	return __tmp;
			// };

			/**
			 *  @return  @c *this
			 *
			 *  Increments the underlying iterator.
			 */
			// random_access_iterator& operator--() {
			// 	++current;
			// 	return *this;
			// };

			/**
			 *  @return  A random_access_iterator with the previous value of @c *this
			 *
			 *  Increments the underlying iterator.
			 */
			// random_access_iterator operator--(int) {
			// 	random_access_iterator __tmp = *this;
			// 	++current;
			// 	return __tmp;
			// };

			/**
			 *  @return  A random_access_iterator that refers to @c current - @a __n
			 *
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			// random_access_iterator operator+(difference_type __n) const { return random_access_iterator(current - __n); };

			/**
			 *  @return  *this
			 *
			 *  Moves the underlying iterator backwards @a __n steps.
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			// random_access_iterator& operator+=(difference_type __n) {
			// 	current -= __n;
			// 	return *this;
			// };

			/**
			 *  @return  A random_access_iterator that refers to @c current - @a __n
			 *
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			// random_access_iterator operator-(difference_type __n) const { return random_access_iterator(current + __n); };

			/**
			 *  @return  *this
			 *
			 *  Moves the underlying iterator forwards @a __n steps.
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			// random_access_iterator& operator-=(difference_type __n) {
			// 	current += __n;
			// 	return *this;
			// };

			/**
			 *  @return  The value at @c current - @a __n - 1
			 *
			 *  The underlying iterator must be a Random Access Iterator.
			 */
			// reference operator[](difference_type __n) const { return *(*this + __n); };
	};
};
#endif