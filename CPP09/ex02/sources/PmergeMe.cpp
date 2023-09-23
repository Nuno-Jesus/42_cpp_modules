/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/23 18:11:32 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/23 19:04:13 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

//! ________________________ CONSTRUCTORS ________________________

PmergeMe::PmergeMe() : type("none")
{
	
}

PmergeMe::PmergeMe(const PmergeMe& copy) : type(copy.type)
{
	*this = copy;
}

PmergeMe::~PmergeMe()
{

}

//! ____________________ OPERATOR OVERLOADING ____________________

PmergeMe& PmergeMe::operator=(const PmergeMe& right)
{
	if (this == &right)
		return (*this);
	this->start = right.start;
	this->end = right.end;
	this->elapsedTime = right.elapsedTime;
	return (*this);
}

bool PmergeMe::parse(char **argv, std::vector<int> &vec, std::list<int> &list)
{
	int					number;
	std::stringstream	stream;
	std::string 		total;

	total = std::string(argv[0]);	
	for (int i = 1; argv[i]; i++)
		total += " " + std::string(argv[i]);	
	stream << total;
	while (!stream.eof())
	{
		if (!(stream >> number))
			return (false);
		if (number < 0)
			return (false);
		vec.push_back(number);
		list.push_back(number);
	}
	return (true);
}

std::vector<std::vector<int>> PmergeMe::merge(std::vector<std::vector<int>> &left, std::vector<std::vector<int>> &right)
{
	std::vector<std::vector<int>> result;

	while (!left.empty() && !right.empty())
	{
		if (left[0][A] < right[0][A] || right[0][A] == UNUSED)
		{
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}	
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}
	return(result);
}

std::vector<std::vector<int>> PmergeMe::mergeSort(std::vector<std::vector<int>> &pairs)
{
	std::vector<std::vector<int>> left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::vector<std::vector<int>> right(pairs.begin() + pairs.size() / 2, pairs.end());

	if (pairs.size() == 1)
		return (pairs);
	left = mergeSort(left);
	right = mergeSort(right);
	return (merge(left, right));
}

std::vector<std::vector<int>> PmergeMe::createPairs(const std::vector<int> &nums)
{
	size_t							numPairs = std::ceil(nums.size() / 2.0);
	std::vector<std::vector<int>>	pairs(numPairs, std::vector<int>(2));

	for (size_t i = 0; i < pairs.size(); i++)
	{
		if ((2 * i + 1) == nums.size())
		{
			pairs[i][A] = UNUSED;		
			pairs[i][B] = nums[2 * i];			
		}
		else
		{
			pairs[i][A] = MIN(nums[2 * i], nums[2 * i + 1]);
			pairs[i][B] = MAX(nums[2 * i], nums[2 * i + 1]);			
		}
	}
	return (pairs);
}

void PmergeMe::generateJacobsthalSequence(std::vector<size_t> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] = (pow(2, i + 2) - pow(-1, i + 2)) / 3;
}

void PmergeMe::binarySearch(std::vector<int> &S, int number)
{
	int start, middle, end;

	start = 0;
	end = S.size() - 1;
	while (start <= end)
	{
		middle = start + (end - start) / 2;
		if (number > S[middle])
			start = middle + 1;
		else if (number < S[middle])		
			end = middle - 1;
	}
	S.insert(S.begin() + start, number);
}

void PmergeMe::insertionSort(std::vector<int> &S, size_t n, const std::vector<std::vector<int>> &pairs)
{
	std::vector<size_t>	jacobSequence(pairs.size());

	generateJacobsthalSequence(jacobSequence);
	binarySearch(S, pairs[0][B]);
	binarySearch(S, pairs[1][B]);
	for (size_t i = 1; i < jacobSequence.size(); i++)
	{
		for (size_t k = jacobSequence[i]; k > jacobSequence[i - 1]; k--)
		{
			if (k >= pairs.size())
				continue ;
			binarySearch(S, pairs[k][B]);
			if (S.size() == n)
				return ;
		}
	}
}

double PmergeMe::mergeInsertionSort(std::vector<int> &nums)
{
	std::vector<std::vector<int>>	pairs;
	std::vector<int>				S;
	
	start = std::chrono::high_resolution_clock::now();
	pairs = createPairs(nums);
	pairs = mergeSort(pairs);	
	for (size_t i = 0 ; i < pairs.size() && pairs[i][A] != UNUSED; i++)
		S.push_back(pairs[i][A]);
	insertionSort(S, nums.size(), pairs);
	end = std::chrono::high_resolution_clock::now();
	elapsedTime = end - start;
	nums = S;
	return (elapsedTime.count());
}