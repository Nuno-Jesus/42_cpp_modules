/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:49:34 by crypto            #+#    #+#             */
/*   Updated: 2023/05/25 09:24:36 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address in str: " << &str << std::endl;
	std::cout << "stringPTR points to: " << stringPTR << std::endl;
	std::cout << "stringREF points to: " << &stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "Value in str: " << str << std::endl;
	std::cout << "stringPTR holds the value of: " << *stringPTR << std::endl;
	std::cout << "stringREF holds the value of: " << stringREF << std::endl;

	return (0);
}
