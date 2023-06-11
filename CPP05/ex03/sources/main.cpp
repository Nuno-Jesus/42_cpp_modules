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

int main(void)
{
	std::srand(time(NULL));
	try
	{
		AForm* rrf;
		Intern someRandomIntern;
		Bureaucrat b("God", 1);
		
		rrf = someRandomIntern.makeForm("robotomy request", "Bender");
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
