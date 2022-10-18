#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

namespace ft{

	template<class T, T v>
	struct integral_constant {
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		static const T					value = v;

	};

	typedef integral_constant<bool, true> t_type;

	template <class T>
	struct is_integral :										integral_constant<bool, false> {};

	template <>	struct is_integral<bool> :						t_type{};
	template <>	struct is_integral<char> :						t_type{};
	template <>	struct is_integral<signed char> :				t_type{};
	template <>	struct is_integral<short> :						t_type{};
	template <>	struct is_integral<int> :						t_type{};
	template <>	struct is_integral<long> :						t_type{};
	template <>	struct is_integral<unsigned char> :				t_type{};
	template <>	struct is_integral<unsigned short> :			t_type{};
	template <>	struct is_integral<unsigned int> :				t_type{};
	template <>	struct is_integral<unsigned long> :				t_type{};

};

#endif