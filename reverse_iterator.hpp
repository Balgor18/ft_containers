#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
// 24.4.1 Reverse iterators
/**
 *  Bidirectional and random access iterators have corresponding reverse
 *  %iterator adaptors that iterate through the data structure in the
 *  opposite direction.  They have the same signatures as the corresponding
 *  iterators.  The fundamental relation between a reverse %iterator and its
 *  corresponding %iterator @c i is established by the identity:
 *  @code
 *      &*(reverse_iterator(i)) == &*(i - 1)
 *  @endcode
 *
 *  <em>This mapping is dictated by the fact that while there is always a
 *  pointer past the end of an array, there might not be a valid pointer
 *  before the beginning of an array.</em> [24.4.1]/1,2
 *
 *  Reverse iterators can be tricky and surprising at first.  Their
 *  semantics make sense, however, and the trickiness is a side effect of
 *  the requirement that the iterators must be safe.
 */
namespace ft {
	template<typename _Iterator>
	class reverse_iterator : public iterator<typename iterator_traits<_Iterator>::iterator_category,
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
			reference operator[](difference_type __n) const { return *(*this + __n); };
	};
};
#endif
