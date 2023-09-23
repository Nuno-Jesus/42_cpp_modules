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

template <typename T>
void test_container(T& container, const std::string& name, int tofind)
{	
	try
	{
		std::cout << GREEN << "\n\t======= TESTING " + name + " =======\n\n" << RESET;

		container.push_back(91);
		container.push_back(42);
		container.push_back(32768);
		container.push_back(std::numeric_limits<int>::max());
		container.push_back(-3);

		int pos = easyfind(container, tofind);		
		std::cout << "Found " << tofind << " in " << name + "[" << pos << "]\n";
	}
	catch(const std::exception& e)
	{
		std::cout << RED << "Couldn't find " << tofind << " in " << name << "\n" << RESET;
	}
	
}

int main(void)
{
	std::vector<int> vector;
	std::list<int> list;
	std::deque<int> deque;

	test_container(vector, "vector", 91);
	test_container(list, "list", 31);
	test_container(deque, "deque", -3);
	return (0);
}
