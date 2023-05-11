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

#include "PhoneBook.class.hpp"

int main(void)
{
	PhoneBook pb;
	std::string input;
	
	pb = PhoneBook();
	while (input != "EXIT")
	{
		std::cout << "Phonebook > ";
		std::cin >> input;
		
		if (input == "ADD")
			pb.add();
		else if (input == "SEARCH")
			pb.display();
		std::cout << "Your input was: " << input << std::endl;
	}
}