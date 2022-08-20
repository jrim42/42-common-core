/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 17:31:01 by jrim              #+#    #+#             */
/*   Updated: 2022/08/20 19:13:34 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include "contact.hpp"

class PhoneBook
{
	private:
		Contact	contacts[8];
		int		length;

	public:

		PhoneBook(void);
		void	add_contact(void);
		void	search_contact(void);
		void	display_contact_head(void);
		void	display_contact_info(void);
		void	display_contact_field(std::string content);
		~PhoneBook(void);
};

#endif