/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:02:19 by marvin            #+#    #+#             */
/*   Updated: 2023/09/21 21:29:33 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(void) : name("default_form"), signGrade(1), execGrade(1)
{
	this->isSigned = false;
}

AForm::AForm(const AForm& copy) : name(copy.name), signGrade(copy.signGrade), \
	execGrade(copy.signGrade)
{
	this->isSigned = copy.isSigned;
}

AForm::AForm(const std::string& name, int signGrade, int execGrade) : name(name), \
	signGrade(signGrade), execGrade(execGrade)
{
	if (signGrade < AForm::MAX_GRADE || execGrade < AForm::MAX_GRADE)
		throw AForm::GradeTooHighException();
	else if (signGrade > AForm::MIN_GRADE || execGrade > AForm::MIN_GRADE)
		throw AForm::GradeTooLowException();
	this->isSigned = false;
	std::cout << this->name << " was created." << std::endl;
}

AForm::~AForm(void)
{
	
}

AForm& AForm::operator=(const AForm& right)
{
	if (this == &right)
		return (*this);
	this->isSigned = right.isSigned;
	return (*this);
}

void AForm::beSigned(const Bureaucrat& b)
{
	if (b.getGrade() > this->signGrade)
		throw AForm::GradeTooLowException();
	this->isSigned = true;
}

void AForm::execute(Bureaucrat const& executor) const
{
	if (!this->hasBeenSigned())
		throw AForm::UnsignedFormException();
	else if (executor.getGrade() > this->getExecutionGrade())
		throw AForm::BureaucratGradeTooLow();
	
	std::cout << executor.getName() << " executed " << this->name << std::endl;
	this->execute();
}

std::string AForm::getName(void) const
{
	return (this->name);
}

bool AForm::hasBeenSigned(void) const
{
	return (this->isSigned);
}

int AForm::getSignGrade(void) const
{
	return (this->signGrade);
}

int AForm::getExecutionGrade(void) const
{
	return (this->execGrade);
}

void AForm::setIsSigned(bool isSigned)
{
	this->isSigned = isSigned;	
}

std::ostream& operator<<(std::ostream& out, const AForm& form)
{
	std::string sign = form.hasBeenSigned() ? " ✅ " : " ❌ ";
	
	out << "AForm: " + form.getName() + ", signed:" + sign + ", sign. grade: ";
	out << form.getSignGrade() << ", exec. grade: " << form.getExecutionGrade();
	out << std::endl;
	return (out);
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("\n\tForm Exception: using grades above 150.\n");
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("\n\tForm Exception: using low grades.\n");
}

const char *AForm::UnsignedFormException::what() const throw()
{
	return ("\n\tForm Exception: this form wasn't signed so it can't be executed.\n");
}

const char *AForm::BureaucratGradeTooLow::what() const throw()
{
	return ("\n\tForm Exception: unsufficient grade to execute.\n");
}
