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
		Bureaucrat b("HighestBureaucrat", 1);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b("LowestBureaucrat", 150);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

void test_edge_cases_2(void)
{
	try
	{
		Bureaucrat b("SecondHighestBureaucrat", 2);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat b("SecondLowestBureaucrat", 149);
		std::cout << b;
		b.decrementGrade();
		std::cout << b;
	}
	catch (const Bureaucrat::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
}

int main(void)
{
	test_edge_cases();
	test_edge_cases_2();
}