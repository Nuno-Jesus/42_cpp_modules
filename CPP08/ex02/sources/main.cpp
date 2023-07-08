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

#include "MutantStack.hpp"

#define LOG(x) std::cout << "\n\t======= TESTING " << x << " =======\n\n"

void test_mutant_stack(void)	
{
	LOG("Mutant Stack");
	MutantStack<int> mstack;

	mstack.push(5);
	mstack.push(17);
	std::cout << "Stack top: " << mstack.top() << std::endl;

	mstack.pop();
	mstack.pop();
	std::cout << "Stack size: " << mstack.size() << std::endl;

	mstack.push(-1);
	mstack.push(42);
	mstack.push(24);
	mstack.push(1);

	MutantStack<int>::iterator begin = mstack.begin();
	MutantStack<int>::iterator end = mstack.end();

	++begin;
	--begin;

	std::cout << "Stack contents:" << std::endl;
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}

	std::stack<int> s(mstack);
}

void	test_lists(void)
{
	LOG("Lists");
	std::list<int> list;

	list.push_back(5);
	list.push_back(17);
	std::cout << "Stack top: " << list.back() << std::endl;

	list.pop_back();
	list.pop_back();
	std::cout << "Stack size: " << list.size() << std::endl;

	list.push_back(-1);
	list.push_back(42);
	list.push_back(24);
	list.push_back(1);

	std::list<int>::iterator begin = list.begin();
	std::list<int>::iterator end = list.end();

	++begin;
	--begin;

	std::cout << "Stack contents:" << std::endl;
	while (begin != end)
	{
		std::cout << *begin << std::endl;
		++begin;
	}

	std::list<int> s(list);
}

int main()
{
	test_lists();
	test_mutant_stack();
	return 0;
}
