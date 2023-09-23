/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:46:51 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 22:46:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
	
}

Intern::Intern(const Intern& copy)
{
	*this = copy;
}

Intern::~Intern()
{
	
}

Intern& Intern::operator=(const Intern& right)
{
	if (this == &right)
		return (*this);
	return (*this);
}

AForm *Intern::makeForm(const std::string& name, const std::string& target)
{
	AForm *(Intern::*factory[3])(const std::string&) =
	{
		&Intern::makePresidentialForm,
		&Intern::makeRobotomyForm,
		&Intern::makeShrubberyForm
	};
	std::string names[3] =
	{
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	for (int i = 0; i < 3; i++)
		if (name == names[i])
			return ((this->*factory[i])(target));
	throw FormNotFoundException();
}

AForm *Intern::makePresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}

AForm *Intern::makeRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makeShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

const char* Intern::FormNotFoundException::what() const throw()
{
	return ("\n\tIntern: Unknown form name\n");
}

