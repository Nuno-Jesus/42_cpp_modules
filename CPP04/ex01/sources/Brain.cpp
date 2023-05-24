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
	LOG("Brain default constructor called.");

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
	LOG("Brain copy constructor called.");
	*this = brain;
}

Brain::~Brain(void)
{
	LOG("Brain died.");
}

Brain& Brain::operator=(const Brain& right)
{
	LOG("Brain assigment operator called.");

	if (this == &right)
		return (*this);
	for (int i = 0; i < NUM_IDEAS; i++)
		this->ideas[i] = right.ideas[i];
	return (*this);
}
