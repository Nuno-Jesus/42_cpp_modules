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
#include "Intern.hpp"

void testMakingInvalidForm(void)
{
	try
	{
		AForm* rrf;
		Intern someRandomIntern;
		
		rrf = someRandomIntern.makeForm("presedential form", "Bender");
		std::cout << *rrf << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}
}

void testMakingValidForm(const std::string &name, const std::string &target)
{
	try
	{
		AForm* rrf;
		Intern someRandomIntern;
		Bureaucrat b("Joe Biden", 1);
		
		rrf = someRandomIntern.makeForm(name, target);
		std::cout << *rrf << std::endl;

		b.signForm(*rrf);
		std::cout << *rrf << std::endl;
		b.executeForm(*rrf);
		delete rrf;
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << '\n';
	}
}

int main(int argc, char **argv)
{
	int					testno;
	std::stringstream	stream;

	std::srand(time(NULL));
	if (argc < 2)
		return (ERROR_USAGE, 1);
	stream << argv[1];
	if (!(stream >> testno))
		return (ERROR_NOT_INT, 1);
	if (testno < 0 || testno > 3)
		return (ERROR_TESTNO, 1);
	if (testno == 0)
		testMakingValidForm("presedential pardon", "Bender");
	else if (testno == 1)
		testMakingValidForm("robotomy request", "Brain");
	else if (testno == 2)
		testMakingValidForm("shrubbery creation", "tree");
	else
		testMakingInvalidForm();
	return (0);
}
