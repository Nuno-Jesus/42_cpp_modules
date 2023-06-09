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

int main(void)
{
	try
	{
		Bureaucrat b("President", 1);
		PresedentialPardonForm form("Barack Obama");

		b.signForm(form);
		form.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}

	try
	{
		Bureaucrat b("Artist", 137);
		ShrubberyCreationForm form("Picasso");

		b.signForm(form);
		form.execute(b);
	}
	catch(const std::exception& e)
	{
		std::cout << RED << e.what() << RESET << std::endl;
	}


}
