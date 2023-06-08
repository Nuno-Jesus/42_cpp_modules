/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:44:25 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 18:48:09 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(150)
{
	LOG("Bureaucrat default constructor called.");
}

Bureaucrat::Bureaucrat(const Bureaucrat& copy)
{
	LOG("Bureaucrat copy constructor called.");
    *this = copy;
}

Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	LOG("Bureaucrat overloaded constructor called.");
	
	if (grade < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade = grade;
}

Bureaucrat::~Bureaucrat()
{
	LOG("Bureaucrat died.");
}

std::string Bureaucrat::getName(void) const
{
	return (this->name);
}

int Bureaucrat::getGrade(void) const
{
	return (this->grade);
}

void Bureaucrat::incrementGrade(void)
{
	LOG("Incrementing grade...");
	if (this->grade - 1 < Bureaucrat::MAX_GRADE)
		throw Bureaucrat::GradeTooHighException();
	this->grade--;
}

void Bureaucrat::decrementGrade(void)
{
	LOG("Decrementing grade...");
	if (this->grade + 1 > Bureaucrat::MIN_GRADE)
		throw Bureaucrat::GradeTooLowException();
	this->grade++;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& right)
{
	LOG("Bureaucrat assignment operator called.");
	if (this == &right)
		return (*this);
	this->grade = grade;
	return (*this);
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b)
{
	out << b.getName() << ", bureaucrat grade ";
	out << b.getGrade() << "." << std::endl;
	return (out);
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("\n\tThe grade cannot go higher than 1.\n");
}
const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("\n\tThe grade cannot go lower than 150.\n");
}
