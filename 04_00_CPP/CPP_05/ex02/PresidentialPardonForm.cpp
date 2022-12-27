/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrim <jrim@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/25 16:16:09 by jrim              #+#    #+#             */
/*   Updated: 2022/12/27 14:44:50 by jrim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//-------------- orthodox canonical form ----------------//
PresidentialPardonForm::PresidentialPardonForm(void) 
	: AForm("PresidentialPardonForm", 25, 5, "undefined")
{
	// std::cout << GRY << "(PresidentialPardonForm: default constructor)" << DFT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target)
	: AForm("PresidentialPardonForm", 25, 5, target)
{
	// std::cout << GRY << "(PresidentialPardonForm: constructor)" << DFT << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& ref) 
{
	// std::cout << GRY << "(PresidentialPardonForm: copy constructor)" << DFT << std::endl;
	*this = ref;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& ref)
{
	// std::cout << GRY << "(PresidentialPardonForm: copy assignment)" << DFT << std::endl;
	if (this != &ref) {}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
	// std::cout << GRY << "(PresidentialPardonForm: destructor)" << DFT << std::endl;
}

//----------------------- utils -------------------------//
void	PresidentialPardonForm::execute(const Bureaucrat& b) const
{
	if (this->getSigned() == false)
		throw NotSignedException();
	if (this->getExecGrade() < b.getGrade())
		throw GradeTooLowException();

	std::cout << GRY << "(PresidentialPardonForm is excuted)" << DFT << std::endl;
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
