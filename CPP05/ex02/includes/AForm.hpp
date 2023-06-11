/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 01:02:18 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 23:19:16 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <iostream>
# include "Bureaucrat.hpp"

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

class Bureaucrat;

class AForm
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
		AForm(void);
		AForm(const AForm& copy);
		AForm(const std::string& name, int signGrade, int execGrade);
		AForm& operator=(const AForm& right);
		virtual ~AForm(void);

		//! Others
		void beSigned(const Bureaucrat& b);
		void execute(Bureaucrat const& executor) const;
		virtual void executeHelper(void) const = 0;

		//! Getters
		std::string getName(void) const;
		bool hasBeenSigned(void) const;
		int getSignGrade(void) const;
		int getExecutionGrade(void) const;

		//! Setters
		void setIsSigned(bool isSigned);

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
	class UnsignedFormException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
	class BureaucratGradeTooLow : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

std::ostream& operator<<(std::ostream& out, const AForm& form);

#endif
