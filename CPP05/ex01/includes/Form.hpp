/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:02:18 by marvin            #+#    #+#             */
/*   Updated: 2023/06/08 19:01:51 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

class Bureaucrat;

class Form
{
	private:
		const std::string name;
		bool isSigned;
		const int signGrade;
		const int execGrade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
	
	public:
		//! Constructors and destructor
		Form(void);
		Form(const Form& copy);
		Form(const std::string& name, int signGrade, int execGrade);
		Form& operator=(const Form& right);
		~Form(void);

		//! Others
		void beSigned(const Bureaucrat& b);

		//! Getters
		std::string getName(void) const;
		bool hasBeenSigned(void) const;
		int getSignGrade(void) const;
		int getExecutionGrade(void) const;

	class GradeTooHighException : public std::exception
	{
		public:
			virtual const char *what() const throw();

	};
	class GradeTooLowException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
