/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 12:44:51 by marvin            #+#    #+#             */
/*   Updated: 2023/07/02 12:44:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

void test_vectors(void)
{
	std::cout << "\n\t======= TESTING VECTORS =======\n\n";

	std::vector<int> vec;
	int	pos;
	int tofind;

	vec.push_back(91);
	vec.push_back(42);
	vec.push_back(32768);
	vec.push_back(INT_MAX);
	vec.push_back(-3);

	tofind = 42;
	pos = easyfind(vec, tofind);
	if (pos == -1)
		std::cout << "Couldn't find " << tofind << " in vector\n";
	else
		std::cout << "Found " << tofind << " in vector[" << pos << "]\n";
}

void test_lists(void)
{
	std::cout << "\n\t======= TESTING LISTS =======\n\n";
	
	std::list<int> list;
	int	pos;
	int tofind;

	list.push_back(91);
	list.push_back(42);
	list.push_back(32768);
	list.push_back(INT_MAX);
	list.push_back(-3);

	tofind = INT_MAX;
	pos = easyfind(list, tofind);
	if (pos == -1)
		std::cout << "Couldn't find " << tofind << " in list\n";
	else
		std::cout << "Found " << tofind << " in list[" << pos << "]\n";
}

void test_deques(void)
{
	std::cout << "\n\t======= TESTING DEQUES =======\n\n";
	
	std::deque<int> deque;
	int	pos;
	int tofind;

	deque.push_back(91);
	deque.push_back(42);
	deque.push_back(32768);
	deque.push_back(INT_MAX);
	deque.push_back(-3);

	tofind = -4;
	pos = easyfind(deque, tofind);
	if (pos == -1)
		std::cout << "Couldn't find " << tofind << " in deque\n";
	else
		std::cout << "Found " << tofind << " in deque[" << pos << "]\n";
}


int main(void)
{
	test_vectors();
	test_lists();
	test_deques();
	return (0);
}