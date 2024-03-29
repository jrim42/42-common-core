/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:21:39 by jrim              #+#    #+#             */
/*   Updated: 2022/11/24 18:31:56 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

# define RED "\033[0;31m"
# define GRN "\033[0;32m"
# define YLW "\033[0;33m"
# define BLU "\033[0;36m"
# define GRY "\033[90m"
# define DFT "\033[0;37m"

class Fixed 
{
	private:
		int					value;
		const static int	bits = 8;
		
	public:
		Fixed(void);
		Fixed(const int fixed);
		Fixed(const float fixed);
		Fixed(const Fixed& ref);
		Fixed&	operator=(const Fixed& ref);
		~Fixed(void);
		
		int		getRawBits(void) const;
		void	setRawBits(int const raw);

		int 	toInt(void) const;
		float	toFloat(void) const;

		bool	operator>(const Fixed& ref) const;
		bool	operator<(const Fixed& ref) const;
		bool	operator>=(const Fixed& ref) const;
		bool	operator<=(const Fixed& ref) const;
		bool	operator==(const Fixed& ref) const;
		bool	operator!=(const Fixed& ref) const;
		Fixed	operator+(const Fixed& ref) const;
		Fixed	operator-(const Fixed& ref) const;
		Fixed	operator*(const Fixed& ref) const;
		Fixed	operator/(const Fixed& ref) const;
		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed& 	operator--(void);
		Fixed	operator--(int);
		
		static Fixed&		min(Fixed& num1, Fixed& num2);
		static const Fixed&	min(const Fixed& num1, const Fixed& num2);
		static Fixed&		max(Fixed& num1, Fixed& num2);
		static const Fixed&	max(const Fixed& num1, const Fixed& num2);
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

#endif