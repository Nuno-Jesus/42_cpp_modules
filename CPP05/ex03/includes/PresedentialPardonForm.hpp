/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:55:51 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 13:55:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIAL_PARDON_FORM_HPP
# define PRESIDENTIAL_PARDON_FORM_HPP

# include <iostream>

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	private:
		const std::string target;

	public:
		//! Constructors and destructor
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string& target);
		PresidentialPardonForm(const PresidentialPardonForm& copy);
		~PresidentialPardonForm();

		//! Operator overloading
		PresidentialPardonForm& operator=(const PresidentialPardonForm& right);

		//! Others
		void execute(void) const;

};

#endif
