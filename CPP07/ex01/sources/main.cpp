/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:03:13 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 17:43:22 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/* ________________________ CALLBACKS ________________________ */

void print_integer(int number)
{
	std::cout << "Number: " << number << "\n";
}

void print_string(std::string str)
{
	std::cout << "String: " << str << "\n";
}

void print_alpha(char c)
{
	std::cout << (char)std::tolower(c);
}

/* ________________________ TESTS ________________________ */

void test_integers(void)
{
	std::cout << "\n\t =============== TEST INTEGERS ===============\n\n";
	int array[] = {1, 2, 3, 4, 5, 42, -1, 0};

	iter(array, sizeof(array)/sizeof(int), &print_integer);	
}

void test_strings(void)
{
	std::cout << "\n\t =============== TEST STRINGS ===============\n\n";
	std::string array[] = 
	{
		"Nuno",
		"Miguel",
		"Carvalho",
		"Jesus",
	};
	
	iter(array, sizeof(array)/sizeof(std::string), &print_string);	
}

void test_alphabet(void)
{	
	std::cout << "\n\t =============== TEST ALPHABET ===============\n\n";
	
	char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	
	iter(alphabet, sizeof(alphabet), &print_alpha);
	std::cout << std::endl;
}

int main(void)
{
	test_integers();
	test_strings();
	test_alphabet();
	return 0;
}
