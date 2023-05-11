/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:58:33 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 23:58:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.class.hpp"

PhoneBook::PhoneBook()
{
	this->_i = 0;
}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::add()
{
	std::string fn, ln, nn, pn, ds;

	std::cout << "First Name: "; 
	std::cin >> fn;
	std::cout << "Last Name: "; 
	std::cin >> ln;
	std::cout << "Nickname: "; 
	std::cin >> nn;
	std::cout << "Phone number: "; 
	std::cin >> pn;
	std::cout << "Darkest Secret: "; 
	std::cin >> ds;
	
	this->_contacts[this->_i++ % MAX_CONTACTS] = Contact(fn, ln, nn, pn, ds);
}

void PhoneBook::display(void)
{
	std::cout << "Index    |First Name|Last Name |Nickname  |" << std::endl;
	for (int i = 0; i < MAX_CONTACTS; i++)
	{
		std::cout << std::setw(10) << Contact::formatField(this->_contacts[i])
	}
}
