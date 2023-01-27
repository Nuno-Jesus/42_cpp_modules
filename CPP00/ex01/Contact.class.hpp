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

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Contact
{
	public:
		Contact();
		~Contact();
		Contact(string fn, string ln, string nn, string pn, string ds);

		string	to_string();

	private:
		string _firstName;
		string _lastName;
		string _nickName;
		string _phoneNumber;
		string _darkestSecret;
};

#endif