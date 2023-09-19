/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:22:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/19 18:07:41 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool parse(char **argv, std::vector<int> &vec, std::list<int> &list)
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
template <class T>
void print(T &container)
{
	typename T::iterator it;

	for (it = container.begin(); it != container.end(); it++)
		std::cout << *it << " ";
	std::cout << std::endl;
}

void print(std::vector<std::vector<int>> &pairs)
{
	for (size_t i = 0; i < pairs.size(); i++)
		print(pairs[i]);
}

void swap(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &left, std::vector<std::vector<int>> &right)
{
	std::vector<std::vector<int>> result;

	std::cout << "\tLEFT" << std::endl;
	print(left);
	std::cout << "\tRIGHT" << std::endl;
	print(right);

	// Find out the minimum values between left and right vectors
	// The loop ends when one of the vectors is emptied out
	while (!left.empty() && !right.empty())
	{
		if (left[0][0] < right[0][0] || right[0][0] == UNUSED)
		{
			std::cout << "L" << std::endl;
			result.push_back(left[0]);
			left.erase(left.begin());
		}
		else
		{
			std::cout << "R" << std::endl;
			result.push_back(right[0]);
			right.erase(right.begin());
		}
	}
	
	// Empty out left vector, if the right vector had the lowest values
	while (!left.empty())
	{
		result.push_back(left[0]);
		left.erase(left.begin());
	}
	
	// Empty out right vector, if the left vector had the lowest values
	while (!right.empty())
	{
		result.push_back(right[0]);
		right.erase(right.begin());
	}

	// std::cout << "\tAFTER MERGING" << std::endl;
	// print(result);
	std::cout << "\n\t==============\n" << std::endl;
	return(result);
}

std::vector<std::vector<int>> mergesort(std::vector<std::vector<int>> &pairs)
{
	std::vector<std::vector<int>> left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::vector<std::vector<int>> right(pairs.begin() + pairs.size() / 2, pairs.end());

	if (pairs.size() == 1)
		return (pairs);
	left = mergesort(left);
	right = mergesort(right);
	return (merge(left, right));
}

// Use binay search to insert the b values in the chain of S
void mergeInsertionSort(std::vector<int> &nums)
{
	std::vector<std::vector<int>> pairs(std::ceil(nums.size() / 2.0), std::vector<int>(2, UNUSED));
	
	// Split the vector in pairs of ints
	for (size_t i = 0; i < pairs.size(); i++)
	{
		if ((2 * i + 1) < nums.size())
		{
			pairs[i][0] = nums[2 * i];
			pairs[i][1] = nums[2 * i + 1];			
		}
		else
			pairs[i][1] = nums[2 * i];
			
		// Sort each pair of ints in ascending order (a, b)
		if (pairs[i][1] < pairs[i][0])
			swap(pairs[i][1], pairs[i][0]);
	}
	std::cout << "Grouping integers into sorted (a, b) pairs" << std::endl;
	print(pairs);
	// Sort the vector of pairs in ascending order using merge sort and comparing the a value
	pairs = mergesort(pairs);	
	std::cout << "FINAL RESULT" << std::endl;
	print(pairs);

	// merge(pairs, 0, (pairs.size() - 1) / 2, pairs.size() - 1);
}

int main(int argc, char **argv)
{
	std::vector<int>	vec;
	std::list<int>		list;
	
	if (argc < 2)
		return (-1);
	if (!parse(argv + 1, vec, list))
		return (std::cout << "Error\n", 1);
	mergeInsertionSort(vec);
	return (0);
}