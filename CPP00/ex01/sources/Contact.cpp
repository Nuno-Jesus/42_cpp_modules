/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:17:40 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 23:17:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

Contact :: Contact(void)
{

}

Contact :: ~Contact(void)
{

}

Contact :: Contact(std::string fn, std::string ln, std::string nn, std::string pn, std::string ds)
{
	this->_firstName = fn;
	this->_lastName = ln;
	this->_nickName = nn;
	this->_phoneNumber = pn;
	this->_darkestSecret = ds;
}

void Contact::display(void)
{
	std::cout << std::endl;
	std::cout << "First name: \"" << this->_firstName << "\"" << std::endl;
	std::cout << "Last name: \"" << this->_lastName << "\"" << std::endl;
	std::cout << "Nickname: \"" << this->_nickName << "\"" << std::endl;
	std::cout << "Phone Number: \"" << this->_phoneNumber << "\"" << std::endl;
	std::cout << "Darkest Secret: \"" << this->_darkestSecret << "\"" << std::endl;
	std::cout << std::endl;
}

std::string Contact::formatField(std::string field)
{
	if (field.length() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

std::string Contact::getFirstName(void)
{
	return (this->_firstName);
}

std::string Contact::getLastName(void)
{
	return (this->_lastName);
}

std::string Contact::getNickName(void)
{
	return (this->_nickName);
}
