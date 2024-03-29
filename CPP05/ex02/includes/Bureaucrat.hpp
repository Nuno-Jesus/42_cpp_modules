/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:44:22 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 15:36:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstdlib>
# include "AForm.hpp"

class AForm;

class Bureaucrat
{
	private:
		const std::string name;
		int grade;
		static const int MAX_GRADE = 1;
		static const int MIN_GRADE = 150;
	
	public:
		//! Constructors and Destructor
		Bureaucrat();
		~Bureaucrat();
		Bureaucrat(const Bureaucrat& copy);
		Bureaucrat(const std::string &name, int grade);
		
		//! Getters
		std::string getName(void) const;
		int getGrade(void) const;
		
		//! Others
		void incrementGrade(void);
		void decrementGrade(void);
		void signForm(AForm& f);
		void executeForm(AForm const& form);
			
		//! Operator overloading
		Bureaucrat& operator=(const Bureaucrat& right);

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

std::ostream& operator<<(std::ostream& out, const Bureaucrat& b);

#endif
