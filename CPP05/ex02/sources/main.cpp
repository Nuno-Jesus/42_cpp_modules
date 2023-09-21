/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 22:18:08 by marvin            #+#    #+#             */
/*   Updated: 2023/06/03 22:18:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Bureaucrat.hpp"
#include "PresedentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

void testForm(AForm& form, Bureaucrat &bureaucrat)
{
	try
	{
		bureaucrat.executeForm(form);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
}

void testPresedentialPardonForm(void)
{
	std::cout << GREEN << "\n\tTesting Presedential Pardon Form\n\n" << RESET;
	PresedentialPardonForm form("Donald Trump");
	Bureaucrat b("Zaphod Beeblebrox", 1);
	b.signForm(form);
	testForm(form, b);
}

void testShrubberyCreationForm(void)
{
	std::cout << GREEN << "\n\tTesting Shrubbery Creation Form\n\n" << RESET;
	ShrubberyCreationForm form("tree");
	Bureaucrat b("Picasso", 130);
	b.signForm(form);
	testForm(form, b);
}

void testRobotomyRequestForm(void)
{
	std::cout << GREEN << "\n\tTesting Robotomy Request Form\n\n" << RESET;
	RobotomyRequestForm form("Left Human Arm");
	Bureaucrat b("Neuro-cientist", 40);
	b.signForm(form);
	testForm(form, b);
}

void testExecutingUnsignedForm(void)
{
	std::cout << GREEN << "\n\tTesting executing unsigned form\n\n" << RESET;
	RobotomyRequestForm form("Brain");
	Bureaucrat b("Neuro-cientist", 40);
	testForm(form, b);
}

void testExecutingWithLowGrade(void)
{
	std::cout << GREEN << "\n\tTesting bureaucrat without grade to execute\n\n" << RESET;
	PresedentialPardonForm form("Prisoner");
	Bureaucrat b("Judicial Court", 5);
	Bureaucrat b2("Junky", 150);
	b.signForm(form);
	testForm(form, b2);
}

int main(int argc, char **argv)
{
	int					testno;
	std::stringstream	stream;
	void (*testers[])() = 
	{
		testPresedentialPardonForm,
		testRobotomyRequestForm,
		testShrubberyCreationForm,
		testExecutingUnsignedForm,
		testExecutingWithLowGrade
	};

	std::srand(time(NULL));
	if (argc < 2)
		return (ERROR_USAGE, 1);
	stream << argv[1];
	if (!(stream >> testno))
		return (ERROR_NOT_INT, 1);
	if (testno < 0 || testno > 4)
		return (ERROR_TESTNO, 1);
	testers[testno]();
	return (0);
}
