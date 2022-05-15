#ifndef ITERATOR_TRAITS_HPP
# define ITERATOR_TRAITS_HPP

/**
   *  @brief  Traits class for iterators.
   *
   *  This class does nothing but define nested typedefs.  The general
   *  version simply @a forwards the nested typedefs from the Iterator
   *  argument.  Specialized versions for pointers and pointers-to-const
   *  provide tighter, more correct semantics.
  */
namespace ft {

	template<typename _Category, typename _Tp, typename _Distance = ptrdiff_t,
		typename _Pointer = _Tp*, typename _Reference = _Tp&>
	struct iterator
	{
		/// One of the @link iterator_tags tag types@endlink.
		typedef _Category	iterator_category;
		/// The type "pointed to" by the iterator.
		typedef _Tp			value_type;
		/// Distance between iterators is represented as this type.
		typedef _Distance	difference_type;
		/// This type represents a pointer-to-value_type.
		typedef _Pointer	pointer;
		/// This type represents a reference-to-value_type.
		typedef _Reference	reference;
	};

	///  Marking input iterators.
	struct input_iterator_tag { };
	///  Marking output iterators.
	struct output_iterator_tag { };
	/// Forward iterators support a superset of input iterator operations.
	struct forward_iterator_tag : public input_iterator_tag { };
	/// Bidirectional iterators support a superset of forward iterator
	/// operations.
	struct bidirectional_iterator_tag : public forward_iterator_tag { };
	/// Random-access iterators support a superset of bidirectional
	/// iterator operations.
	struct random_access_iterator_tag : public bidirectional_iterator_tag { };


	template<typename _Iterator>
	struct iterator_traits
	{
		typedef typename _Iterator::iterator_category	iterator_category;//if its a random _access
		typedef typename _Iterator::value_type			value_type; // the type point ex : int
		typedef typename _Iterator::difference_type		difference_type;// diff space btw two type ex : int for next int is 4 octets
		typedef typename _Iterator::pointer				pointer;// *
		typedef typename _Iterator::reference			reference;// &
	};

	/// Partial specialization for pointer types.
	template<typename _T>
	struct iterator_traits<_T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef _T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef _T*								pointer;
		typedef _T&								reference;
	};

	/// Partial specialization for const pointer types.
	template<typename _T>
	struct iterator_traits<const _T*>
	{
		typedef std::random_access_iterator_tag	iterator_category;
		typedef _T								value_type;
		typedef ptrdiff_t						difference_type;
		typedef const _T*						pointer;
		typedef const _T&						reference;
	};
};
#endif
