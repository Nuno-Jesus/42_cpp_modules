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

#include "Bureaucrat.hpp"

void test_form_signing(void)
{
	std::cout << GREEN << "\n\t\t\tTesting Form Signing\n" << RESET << std::endl;

	Bureaucrat president("President", 1);
	Form nuclearForm("Nuclear Explosion Form", 1, 1);
	try
	{
		president.signForm(nuclearForm);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	std::cout << nuclearForm;
	
	Bureaucrat citizen("Citizen", 150);
	Form allowanceForm("Allowance", 42, 42);
	try
	{
		citizen.signForm(allowanceForm);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	std::cout << allowanceForm;
}

void test_form_constructor(void)
{
	std::cout << GREEN << "\n\t\tTesting Form Constructor\n" << RESET << std::endl;

	try
	{
		Form allowance("Allowance", 1, 1);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	try
	{
		Form allowance("Allowance", 0, 0);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
	
	try
	{
		Form allowance("Allowance", 150, 150);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Form allowance("Allowance", 151, 151);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}
}

int main(int argc, char **argv)
{
	int					testno;
	std::stringstream	stream;

	if (argc < 2)
		return (ERROR_USAGE, 1);
	stream << argv[1];
	if (!(stream >> testno))
		return (ERROR_NOT_INT, 1);
	if (testno == 0)
		test_form_constructor();
	else if (testno == 1)
		test_form_signing();
	else
		return (ERROR_TESTNO, 1);
	return (0);
}
