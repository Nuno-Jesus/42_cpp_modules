/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:57:23 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 13:57:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : \
	AForm("Presidential Pardon Form", 25, 5), target("Someone")
{
	
}

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : \
	AForm("Presidential Pardon Form", 25, 5), target(target)
{

}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& copy) : \
	AForm(copy), target(copy.target)
{

}

PresidentialPardonForm::~PresidentialPardonForm()
{
	
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& right)
{
	if (this == &right)
		return (*this);
	this->setIsSigned(right.hasBeenSigned());
	return (*this);
}

void PresidentialPardonForm::execute(void) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
