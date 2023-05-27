/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 03:31:55 by marvin            #+#    #+#             */
/*   Updated: 2023/05/24 03:31:55 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor called." << std::endl;

	const std::string ideas[] = 
	{
		"I am hungry",
		"I want to play",
		"I need to pee",
		"I want pets!",
		"RAWRRRR",
		"..."
	};

	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = ideas[rand() % 6];
}

Brain::Brain(const Brain& brain)
{
	std::cout << "Brain copy constructor called." << std::endl;
	*this = brain;
}

Brain::~Brain(void)
{
	std::cout << "Brain died." << std::endl;
}

Brain& Brain::operator=(const Brain& right)
{
	std::cout << "Brain assigment operator called." << std::endl;

	if (this == &right)
		return (*this);
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = right.ideas[i];
	return (*this);
}

void Brain::use(void) const
{
	for (int i = 0; i < 10; i++)
		std::cout << i << ":" + this->ideas[i] << std::endl;
}
