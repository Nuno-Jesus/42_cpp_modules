/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:02:18 by marvin            #+#    #+#             */
/*   Updated: 2023/06/04 01:09:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int requestedSignGrade;
		const int requestedExecutionGrade;
	
	public:
		Form();
		~Form();
		Form(const Form& copy);
		Form& operator=(const Form& right);

		//! Others
		void beSigned(const Bureaucrat& b);

		//! Getters
		std::string getName(void) const;
		bool isSigned(void) const;
		int getRequestedSignGrade(void) const;
		int getRequestedExecutionGrade(void) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif