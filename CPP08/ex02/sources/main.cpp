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
	std::cout << "Stack size: " << mstack.size() << std::endl;

	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);

	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Stack contents:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::stack<int> s(mstack);
}

void	test_lists(void)
{
	LOG("Lists");
	std::list<int> mstack;

	mstack.push_back(5);
	mstack.push_back(17);
	std::cout << "Stack top: " << mstack.back() << std::endl;

	mstack.pop_back();
	std::cout << "Stack size: " << mstack.size() << std::endl;

	mstack.push_back(3);
	mstack.push_back(5);
	mstack.push_back(737);
	mstack.push_back(0);

	std::list<int>::iterator it = mstack.begin();
	std::list<int>::iterator ite = mstack.end();

	++it;
	--it;

	std::cout << "Stack contents:" << std::endl;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::list<int> s(mstack);
}

int main()
{
	test_lists();
	test_mutant_stack();
	return 0;
}
