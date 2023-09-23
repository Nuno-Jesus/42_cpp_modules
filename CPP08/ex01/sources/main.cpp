/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:26:56 by marvin            #+#    #+#             */
/*   Updated: 2023/07/02 18:26:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

#define LOG(title) std::cout << GREEN "\n\t===== Testing " << title << " =====\n\n" RESET;

void testShortestSpan(void)
{
	Span span(3);

	LOG("Shortest Span");
	std::cout << "Filling span until N=3...\n"; 
	span.fill();
	std::cout << span;
	std::cout << "Shortest span: " << span.shortestSpan() << "\n";
}

void testLongestSpan(void)
{
	Span span(10);

	LOG("Longest Span");
	std::cout << "Filling span until N=10...\n"; 
	span.fill();
	std::cout << span;
	std::cout << "Longest span: " << span.longestSpan() << "\n";
}

void testAddNumber(void)
{
	LOG("Add Number");

	try
	{
		Span fullSpan(10);

		std::cout << "Filling span until N=10...\n"; 
		fullSpan.fill();
		std::cout << fullSpan;

		std::cout << "Trying to add an 11th number...\n"; 
		fullSpan.addNumber(333333);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

void testNoSpan(void)
{
	LOG("Empty Span");
	try
	{
		Span emptySpan;
		emptySpan.shortestSpan();
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

void testLargeSet(void)
{
	LOG("Large Span Set");
	try
	{
		Span largeSpan(15000);

		largeSpan.fill();
		std::cout << largeSpan;
		std::cout << "Shortest span: " << largeSpan.shortestSpan() << "\n";
		std::cout << "Longest span: " << largeSpan.longestSpan() << "\n";
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}


int main(int argc, char **argv)
{
	int					testno;
	std::stringstream	stream;
	void (*testers[])() = 
	{
		&testShortestSpan,
		&testLongestSpan,
		&testAddNumber,
		&testLargeSet,
		&testNoSpan,
	};

	std::srand(std::time(NULL));
	if (argc < 2)
		return (ERROR_USAGE(argv[0]), 1);
	stream << argv[1];
	if (!(stream >> testno))
		return (ERROR_NOT_INT, 1);
	if (testno < 0 || testno > 4)
		return (ERROR_TESTNO, 1);
	testers[testno]();
	return (0);
}
