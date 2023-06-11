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

void test_form(AForm& form, Bureaucrat& bureaucrat)
{
	std::cout << GREEN << "\n\tTesting " + form.getName() + "\n\n" << RESET;
	bureaucrat.signForm(form);
	bureaucrat.executeForm(form);
}

int main(void)
{
	std::srand(time(NULL));

	try
	{
		PresedentialPardonForm form1("Donald Trump");
		Bureaucrat b1("Zaphod Beeblebrox", 1);
		test_form(form1, b1);

		ShrubberyCreationForm form2("tree");
		Bureaucrat b2("Picasso", 130);
		test_form(form2, b2);

		RobotomyRequestForm form3("Left Human Arm");
		Bureaucrat b3("Neuro-cientist", 40);
		test_form(form3, b3);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
	
}
