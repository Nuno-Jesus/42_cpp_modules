/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:44:22 by marvin            #+#    #+#             */
/*   Updated: 2023/06/11 19:56:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstdlib>

// # define DEBUG

# ifdef DEBUG
#  define LOG(str) std::cout << str << std::endl;
# else
#  define LOG(str)
# endif

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

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