/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 23:23:00 by marvin            #+#    #+#             */
/*   Updated: 2023/01/26 23:23:00 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "PhoneBook.class.hpp"

int main(void)
{
	PhoneBook pb = PhoneBook();
	string input;
	
	while (input != "EXIT")
	{
		cin >> input;
		
		if (input == "ADD")
			pb.addContact();
		else if (input == "SEARCH")
			pb.displayContacts();
		cout << "Your input was: " << input << endl;
	}
}