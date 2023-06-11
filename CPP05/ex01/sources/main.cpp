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

void test_form_sign(void)
{
	std::cout << GREEN << "\n\t\t\tTesting form signing\n" << RESET << std::endl;

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
	Form allowanceForm("Allowance", 89, 89);
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

void test_form_creation(void)
{
	std::cout << GREEN << "\n\t\t\tTesting creating forms\n" << RESET << std::endl;

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

int main(void)
{
	test_form_creation();
	test_form_sign();
}
