/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 21:44:22 by marvin            #+#    #+#             */
/*   Updated: 2023/09/21 14:22:59 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <cstdlib>
# include <sstream>

# define DEBUG

# ifdef DEBUG
#  define LOG(str) std::cout << str << std::endl;
# else
#  define LOG(str)
# endif

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

# define ERROR(x) 		std::cout << x << std::endl
# define ERROR_USAGE	ERROR("Usage: ./ex00 test_number")
# define ERROR_NOT_INT	ERROR("Error: test number must be a number")
# define ERROR_TESTNO	ERROR("Error: test number must be bounded between 0 and 2")


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