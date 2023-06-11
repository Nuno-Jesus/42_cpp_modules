/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 22:00:45 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 22:00:45 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMY_REQUEST_FORM_HPP
# define ROBOTOMY_REQUEST_FORM_HPP

# include <iostream>
# include <iomanip>
# include <fstream>

# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
	private:
		const std::string target;

	public:
		//! Constructors and destructor
		RobotomyRequestForm();
		RobotomyRequestForm(const std::string& target);
		RobotomyRequestForm(const RobotomyRequestForm& copy);
		~RobotomyRequestForm();

		//! Operator overloading
		RobotomyRequestForm& operator=(const RobotomyRequestForm& right);

		//! Others
		void executeHelper(void) const;
};

#endif