#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP
# include "iterator_traits.hpp"

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

};
#endif
