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
	catch (std::exception &e)
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
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
}

void test_base_cases(void)
{
	try
	{
		Bureaucrat b("Vice-President", 2);
		std::cout << b;
		b.incrementGrade();
		std::cout << b;
	}
	catch (std::exception &e)
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
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
}

void test_constructors(void)
{
	try
	{
		Bureaucrat b("0 Grade Someone", 0);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
	
	try
	{
		Bureaucrat b("151 Grade Someone", 151);
	}
	catch (std::exception &e)
	{
		std::cout << RED << e.what() << RESET << "\n";
	}
}



int main(int argc, char **argv)
{
	int					testno;
	std::stringstream	stream;

	if (argc < 2)
		return (ERROR_USAGE(argv[0]), 1);
	stream << argv[1];
	if (!(stream >> testno))
		return (ERROR_NOT_INT, 1);
	if (testno == 0)
		test_edge_cases();
	else if (testno == 1)
		test_base_cases();
	else if (testno == 2)
		test_constructors();
	else
		return (ERROR_TESTNO, 1);
	return (0);
}
