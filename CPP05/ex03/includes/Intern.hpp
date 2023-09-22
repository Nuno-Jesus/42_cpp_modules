/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:45:37 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 22:45:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <sstream>

# include "PresedentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern
{
	public:
		//! Constructors and destructor
		Intern();
		Intern(const Intern& copy);
		~Intern();

		//! Operator overloading
		Intern& operator=(const Intern& right);

		//! Others
		AForm *makeForm(const std::string& name, const std::string& target);
		AForm *makePresedentialForm(const std::string &target);
		AForm *makeRobotomyForm(const std::string &target);
		AForm *makeShrubberyForm(const std::string &target);

		class FormNotFoundException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

#endif
