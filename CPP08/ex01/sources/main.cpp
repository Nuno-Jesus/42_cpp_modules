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

void test_shortest_span(void)
{
	Span span(10);

	LOG("Shortest Span");
	span.fill();
	std::cout << span;
	std::cout << "Shortest span: " << span.shortestSpan() << "\n";
}

void test_longest_span(void)
{
	Span span(10);

	LOG("Longest Span");
	span.fill();
	std::cout << span;
	std::cout << "Longest span: " << span.longestSpan() << "\n";
}

void test_add_number(void)
{
	LOG("Add Number");

	try
	{
		Span fullSpan(10);

		fullSpan.addNumber(42);
		fullSpan.addNumber(24);
		fullSpan.addNumber(-1);
		fullSpan.addNumber(1);
		std::cout << fullSpan;

		std::cout << "Filling span until N=10...\n"; 
		fullSpan.fill();

		std::cout << "Trying to add an 11th number...\n"; 
		fullSpan.addNumber(333333);
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << "\n";
	}
}

void test_no_span(void)
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

void test_large_set(void)
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


void usage(char *command)
{
	std::cout << "Usage: " << command << " test\n";
	std::exit(1);
}

int main(int argc, char **argv)
{
	if (argc < 2)
		usage(argv[0]);

	std::srand(std::time(NULL));
	switch(std::atoi(argv[1]))
	{
		case 0: 
			test_shortest_span(); 
			break;
		case 1: 
			test_longest_span(); 
			break;
		case 2: 
			test_add_number(); 
			break;
		case 3: 
			test_no_span(); 
			break;
		case 4: 
			test_large_set(); 
			break;
	}
	return (0);
}
