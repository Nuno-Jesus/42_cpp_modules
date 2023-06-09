/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresedentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:57:23 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 13:57:23 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresedentialPardonForm.hpp"

PresedentialPardonForm::PresedentialPardonForm() : \
	AForm("Presedential Pardon Form", 25, 5), target("Someone")
{
	
}

PresedentialPardonForm::PresedentialPardonForm(const std::string& target) : \
	AForm("Presedential Pardon Form", 25, 5), target(target)
{

}

PresedentialPardonForm::PresedentialPardonForm(const PresedentialPardonForm& copy) : \
	AForm(copy), target(copy.target)
{

}

PresedentialPardonForm::~PresedentialPardonForm()
{
	
}

PresedentialPardonForm& PresedentialPardonForm::operator=(const PresedentialPardonForm& right)
{
	if (this == &right)
		return (*this);
	this->setIsSigned(right.hasBeenSigned());
	return (*this);
}

void PresedentialPardonForm::executeHelper(void) const
{
	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
