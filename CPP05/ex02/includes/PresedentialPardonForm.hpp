/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresedentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 13:55:51 by marvin            #+#    #+#             */
/*   Updated: 2023/06/09 13:55:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESEDENTIAL_PARDON_FORM_HPP
# define PRESEDENTIAL_PARDON_FORM_HPP

# include <iostream>


# include "AForm.hpp"

class PresedentialPardonForm : public AForm
{
	private:
		const std::string target;

	public:
		//! Constructors and destructor
		PresedentialPardonForm();
		PresedentialPardonForm(const std::string& target);
		PresedentialPardonForm(const PresedentialPardonForm& copy);
		~PresedentialPardonForm();

		//! Operator overloading
		PresedentialPardonForm& operator=(const PresedentialPardonForm& right);

		//! Others
		void execute(void) const;

};

#endif
