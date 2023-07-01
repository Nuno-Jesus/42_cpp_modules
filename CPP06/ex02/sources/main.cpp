/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:07:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 16:44:48 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void test_bad_identify(void)
{
	std::cout << "\n\t======== Testing bad identify ========\n\n";
	
	Base *pointer = NULL;
	Base reference;
	
	identify(pointer);
	identify(reference);
}


void test_cool_identify(void)
{
	std::cout << "\n\t======== Testing cool identify ========\n\n";

	Base *random;
	random = generate();

	std::cout << "Address of random: " << random << std::endl;
	identify(random);
	identify(*random);
	
	delete random;
}

int main(void)
{
	std::srand(time(NULL));
	test_cool_identify();
	test_bad_identify();
	return (0);
}
