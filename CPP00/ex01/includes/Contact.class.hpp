/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:16:24 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 23:16:24 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <iomanip>

# define CLEAR_SCREEN "\033[2J\033[H"

class Contact
{
	public:
		Contact(void);
		~Contact(void);
		Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds);
		void display(void);
		
		std::string getFirstName(void);
		std::string getLastName(void);
		std::string getNickName(void);

		static std::string formatField(std::string field);

	private:
		std::string _firstName;
		std::string _lastName;
		std::string _nickName;
		std::string _phoneNumber;
		std::string _darkestSecret;
};

#endif