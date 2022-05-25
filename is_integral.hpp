#ifndef IS_INTEGRAL_HPP
#define IS_INTEGRAL_HPP

# include <iostream>
// # include <type_traits>

namespace ft{

	template<class T, T v>
	struct integral_constant {
		typedef T						value_type;
		typedef integral_constant<T, v>	type;
		static const T					val = v;

		operator value_type() const {
			return val;
		};
	};

	typedef integral_constant<bool, true> t_type;

	template <class T>
	struct is_integral : public integral_constant<bool, false> {

	};

	template <class T>
	struct is_integral<const T> : public is_integral<T> {

	};

	template <class T>
	struct is_integral<volatile const T> : public is_integral<T>{

	};

	template <class T>
	struct is_integral<volatile T> : public is_integral<T>{

	};

	template<>
	struct is_integral<bool> : public t_type{
	};
	template<>
	struct is_integral<char> : public t_type{
	};

	template<>
	struct is_integral<signed char> : public t_type{
	};
	template<>
	struct is_integral<short> : public t_type{
	};
	template<>
	struct is_integral<int> : public t_type{
	};
	template<>
	struct is_integral<long> : public t_type{
	};

	template<>
	struct is_integral<unsigned char> : public t_type {
	};
	template<>
	struct is_integral<unsigned short> : public t_type{
	};
	template<> 
	struct is_integral<unsigned int> : public t_type{
	};
	template<>
	struct is_integral<unsigned long> : public t_type{
	};

};

#endif