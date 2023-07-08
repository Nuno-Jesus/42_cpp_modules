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

#define LOG(x) std::cout << "\n\t======= TESTING " << x << " =======\n\n"

template <typename T>
void test_container(T& container, const std::string& name, int tofind)
{	
	int	pos;

	LOG(name);
	container.push_back(91);
	container.push_back(42);
	container.push_back(32768);
	container.push_back(INT_MAX);
	container.push_back(-3);

	pos = easyfind(container, tofind);
	if (pos == -1)
		std::cout << "Couldn't find " << tofind << " in " << name << "\n";
	else
		std::cout << "Found " << tofind << " in " << name + "[" << pos << "]\n";
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
