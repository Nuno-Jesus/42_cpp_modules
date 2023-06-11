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

void test_edge_cases(void)
{
	try
	{
		Bureaucrat b("President", 1);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
	
	try
	{
		Bureaucrat b("Citizen", 150);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
}

void test_increments(void)
{
	try
	{
		Bureaucrat b("Vice-President", 2);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
	
	try
	{
		Bureaucrat b("Worker", 149);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
}

int main(void)
{
	test_edge_cases();
	test_increments();
}