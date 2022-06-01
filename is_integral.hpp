#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

# include <iostream>
// # include <type_traits>

namespace ft{

	template<class T, T v>
	struct integral_constant {
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		static const T					value = v;

		// operator value_type() const {
		// 	return v;
		// };
	};

	typedef integral_constant<bool, true> t_type;

	template <class T>
	struct is_integral :										integral_constant<bool, false> {};

	// template <class T>
	// struct is_integral<const T> :					is_integral<T> {};

	// template <class T>
	// struct is_integral<volatile const T> :			is_integral<T>{};

	// template <class T>
	// struct is_integral<volatile T> :				is_integral<T>{};

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

	// template <> struct is_integral<const bool> :				t_type {};
	// template <> struct is_integral<const char> :				t_type {};
	// template <> struct is_integral<const wchar_t> :				t_type {};
	// template <> struct is_integral<const signed char> :			t_type {};
	// template <> struct is_integral<const short int> :			t_type {};
	// template <> struct is_integral<const int> :					t_type {};
	// template <> struct is_integral<const long int> :			t_type {};
	// template <> struct is_integral<const unsigned char> :		t_type {};
	// template <> struct is_integral<const unsigned short int> :	t_type {};
	// template <> struct is_integral<const unsigned int> :		t_type {};
	// template <> struct is_integral<const unsigned long int> :	t_type {};

};

#endif