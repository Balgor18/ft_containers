#ifndef LEXICOGRAPHICAL_COMPARE_HPP
# define LEXICOGRAPHICAL_COMPARE_HPP

namespace ft {
	template <class T1, class T2>
	bool lexicographical_compare (T1 first1, T1 last1, T2 first2, T2 last2)
	{
		while (first1!=last1)
		{
			if (first2==last2 || *first2<*first1) return false;
			else if (*first1<*first2) return true;
			++first1; ++first2;
		}
		return (first2!=last2);
	}

	template<class T1, class T2>
	bool	equal(T1 first1, T1 last1, T2 first2)
	{
		while( first1 != last1) {
			if (!(*first1 == *first2)) {
				return false;
			}
			 ++first1;
			 ++first2;
		}
		return true;
	}
};
#endif