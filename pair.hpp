#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft {
	template<class T1, class T2>
	class pair
	{
		private:
			typedef T1 type_first;
			typedef T2 type_second;

		public:
			type_first	first;
			type_second	second;

			pair() : first(), second() {};
	
			template<class T, class U>
			pair(const pair< T, U >& pair) : first(pair.first), second(pair.second) { };

			~pair() {};

			pair(const type_first& first, const type_second& second) : first(first), second(second) {};

			pair& operator= (const pair& rhs)
			{
				if (this == &rhs)
					return *this;
				first = rhs.first;
				second = rhs.second;
				return *this;
			}
			
			void swap (pair& pr)
			{
				std::swap(pr.first, first);
				std::swap(pr.second, second);
			}
	};

	template< class T1, class T2 >
	bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ) 
	{
		return ( lhs.first == rhs.first && lhs.second == rhs.second );
	}

	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return ((lhs.first < rhs.first) || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
	}

	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs==rhs);
	};

	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(rhs<lhs);
	};

	template <class T1, class T2>
	bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return rhs<lhs;
	};

	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs) {
		return !(lhs<rhs);
	};

	template <class T1,class T2>
	pair<T1,T2>		make_pair(T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	}
}

#endif