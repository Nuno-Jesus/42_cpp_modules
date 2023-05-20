/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 11:49:34 by crypto            #+#    #+#             */
/*   Updated: 2023/05/20 17:18:36 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Address in str: " << &str << std::endl;
	std::cout << "Address in stringPTR: " << stringPTR << std::endl;
	std::cout << "Address in stringREF: " << &stringREF << std::endl;

	std::cout << std::endl;
	
	std::cout << "Value in str: " << str << std::endl;
	std::cout << "Value in stringPTR: " << *stringPTR << std::endl;
	std::cout << "Value in stringREF: " << stringREF << std::endl;

	return (0);
}
