/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 22:07:56 by jrim              #+#    #+#             */
/*   Updated: 2023/02/25 22:07:56 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft 
{
	template <typename T1, typename T2>
	struct pair 
	{
		typedef T1		first_type;
		typedef T2		second_type;

		first_type		first;
		second_type		second;

		pair(void) 
			: first(first_type()), second(second_type()) {}
		pair(const first_type& x, const second_type& y) 
			: first(x), second(y) {}
		template <typename U1, typename U2>
		pair(const pair<U1, U2>& ref) 
			: first(ref.first), second(ref.second) {}
		pair& operator=(const pair& ref) 
		{
			if (this != &ref) 
			{
				first = ref.first;
				second = ref.second;
			}
			return (*this);
		}
	}; // end of class pair

	// make_pair
	template <typename T1, typename T2>
	ft::pair<T1, T2>	make_pair(T1 x, T2 y) 
	{
		return pair<T1, T2>(x, y);
	}

	// comparison operator 
	template <typename T1, typename T2>
	bool	operator==(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) 
	{
		return x.first == y.first && x.second == y.second;
	}

	template <typename T1, typename T2>
	bool	operator!=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) 
	{
		return !(x == y);
	}

	template <typename T1, typename T2>
	bool	operator<(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) 
	{
		return x.first < y.first || (!(x.first > y.first) && x.second < y.second);
	}

	template <typename T1, typename T2>
	bool	operator<=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) 
	{
		return !(y < x);
	}

	template <typename T1, typename T2>
	bool	operator>(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) 
	{
		return y < x;
	}

	template <typename T1, typename T2>
	bool	operator>=(const ft::pair<T1, T2>& x, const ft::pair<T1, T2>& y) 
	{
		return !(x < y);
	}
}  // end of namespace ft

#endif