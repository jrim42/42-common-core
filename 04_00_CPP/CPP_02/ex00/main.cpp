/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 16:20:33 by jrim              #+#    #+#             */
/*   Updated: 2022/11/22 16:28:23 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Fixed.hpp"

int main(void) 
{
	std::cout << "------------------ a ------------------" << std::endl;
	Fixed	a;
	std::cout << "------------------ b ------------------" << std::endl;
	Fixed	b(a);
	std::cout << "------------------ c ------------------" << std::endl;
	Fixed	c;

	c = b;
	std::cout << "---------------------------------------" << std::endl;
	std::cout << a.getRawBits() << std::endl;
	std::cout << b.getRawBits() << std::endl;
	std::cout << c.getRawBits() << std::endl;
	std::cout << "---------------------------------------" << std::endl;
	return (0);
}