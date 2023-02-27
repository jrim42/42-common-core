/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_traits.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:08:15 by jrim              #+#    #+#             */
/*   Updated: 2023/02/25 22:08:16 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPE_TRAITS_HPP
# define TYPE_TRAITS_HPP

# include <cstdint>

namespace ft
{
	//=============================== enable_if ===============================//
	template <bool Cond, typename T = void>
	struct enable_if {};

	template <typename T>
	struct enable_if<true, T> 	{ typedef T type; };

	//=============================== remove_cv ===============================//
	template <typename T> struct remove_cv 						{ typedef T type; };
	template <typename T> struct remove_cv<const T>				{ typedef T type; };
	template <typename T> struct remove_cv<volatile T>			{ typedef T type; };
	template <typename T> struct remove_cv<const volatile T>	{ typedef T type; }; 

	//============================== is_integral ==============================//
	// integral constant
	template <typename T, T v>
	struct integral_constant 
	{
		typedef T					   value_type;
		typedef integral_constant	   type;
		static const value_type		 	value = v;

		operator value_type(void) const { return value; }
	};

	typedef integral_constant<bool, true>   true_type;
	typedef integral_constant<bool, false>  false_type;

	// is_integral_base
	template <typename> struct is_integral_base 					: public false_type {};
		
	template <> struct	is_integral_base<bool>						: public true_type {};
	template <> struct	is_integral_base<char>						: public true_type {};
	template <> struct	is_integral_base<char16_t>					: public true_type {};
	template <> struct	is_integral_base<char32_t>					: public true_type {};
	template <> struct	is_integral_base<wchar_t>					: public true_type {};
	template <> struct	is_integral_base<signed char>				: public true_type {};
	template <> struct	is_integral_base<unsigned char>				: public true_type {};
	template <> struct	is_integral_base<short int>					: public true_type {};
	template <> struct	is_integral_base<int>						: public true_type {};
	template <> struct	is_integral_base<long int>					: public true_type {};
	template <> struct	is_integral_base<long long int>				: public true_type {};
	template <> struct	is_integral_base<unsigned short int>		: public true_type {};
	template <> struct	is_integral_base<unsigned int>				: public true_type {};
	template <> struct	is_integral_base<unsigned long int>			: public true_type {};
	template <> struct	is_integral_base<unsigned long long int>	: public true_type {};

	// is_integral
	template <typename T>
	struct is_integral : public is_integral_base<typename remove_cv<T>::type> {};
} // end of namespace ft

#endif