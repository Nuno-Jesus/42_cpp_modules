/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 18:26:59 by marvin            #+#    #+#             */
/*   Updated: 2023/07/02 18:26:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span() : N(0)
{
	
}

Span::Span(const Span& copy)
{
	*this = copy;
}

Span::Span(unsigned int N) : N(N)
{
	
}

Span::~Span()
{
	
}

Span& Span::operator=(const Span& right)
{
	if (this == &right)
		return (*this);
	this->N = right.N;
	this->storage = right.storage;
	return (*this);
}

void Span::addNumber(int number)
{
	if (this->storage.size() == this->N)
		throw FullSpanException();
	this->storage.push_back(number);
}

int Span::shortestSpan(void)
{
	int difference;
	std::vector<int>::const_iterator curr;

	if (this->storage.size() < 2)
		throw NoSpanException();
	
	std::sort(this->storage.begin(), this->storage.end());
	difference = std::numeric_limits<int>::max();
	for (curr = this->storage.begin() + 1; curr != this->storage.end(); curr++)
		if (*curr - *(curr - 1) < difference)
			difference = *curr - *(curr - 1);
	return (difference);
}

int Span::longestSpan(void)
{
	std::vector<int>::const_iterator min;
	std::vector<int>::const_iterator max;

	if (this->storage.size() < 2)
		throw NoSpanException();
		
	min = std::min_element(this->storage.begin(), this->storage.end());
	max = std::max_element(this->storage.begin(), this->storage.end());
	return (*max - *min);
}

int fillHelper(void)
{
	return (rand() % 50000); 
}

void Span::fill(void)
{
	this->storage.resize(N);	
	std::generate(this->storage.begin(), this->storage.end(), &fillHelper);
	std::sort(this->storage.begin(), this->storage.end());
}

unsigned int Span::size(void) const
{
	return (this->storage.size());
}

std::vector<int> Span::getStorage(void) const
{
	return (this->storage);
}

const char *Span::FullSpanException::what() const throw()
{
	return (RED "Can't add numbers to a full span." RESET);
}

const char *Span::NoSpanException::what() const throw()
{
	return (RED "Can't find spans with less than 2 integers." RESET);
}

std::ostream& operator <<(std::ostream& out, const Span& span)
{
	std::vector<int> vec;

	vec = span.getStorage();
	for (unsigned int i = 0; i < span.size(); i++)
		out << "vector[" << i << "] = " << vec[i] << "\n";
	out << std::endl;
	return (out);
}
