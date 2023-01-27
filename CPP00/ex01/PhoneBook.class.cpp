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

void PhoneBook::addContact()
{
	string fn, ln, nn, pn, ds;

	cout << "First Name: "; cin >> fn;
	cout << "Last Name: "; cin >> ln;
	cout << "Nickname: "; cin >> nn;
	cout << "Phone number: "; cin >> pn;
	cout << "Darkest Secret: "; cin >> ds;
	
	this->_contacts[(this->_i++) % MAX_CONTACTS] = Contact(fn, ln, nn, pn, ds);
}

void PhoneBook::displayContacts(void)
{
	for (int i = 0; i < MAX_CONTACTS; i++)
		cout << i << " " + _contacts[i].to_string() << endl;
}
