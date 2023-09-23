/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:07:17 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/22 17:22:29 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"

void testBadIdentify(void)
{
	std::cout << GREEN << "\n\t======== Testing bad identify ========\n\n" << RESET;
	
	Base *pointer = NULL;
	Base reference;
	
	identify(pointer);
	identify(reference);
}

void testCoolIdentify(void)
{
	std::cout << GREEN << "\n\t======== Testing cool identify ========\n\n" << RESET;

	Base *random;
	random = generate();

	identify(random);
	identify(*random);
	delete random;
}

int main(int argc, char **argv)
{
	int					testno;
	std::stringstream	stream;

	std::srand(time(NULL));
	if (argc < 2)
		return (ERROR_USAGE(argv[0]), 1);
	stream << argv[1];
	if (!(stream >> testno))
		return (ERROR_NOT_INT, 1);
	if (testno < 0 || testno > 1)
		return (ERROR_TESTNO, 1);
	if (testno == 0)
		testCoolIdentify();
	else
		testBadIdentify();
	return (0);
}
