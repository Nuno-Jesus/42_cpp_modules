/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:22:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/18 14:11:30 by crypto           ###   ########.fr       */
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

void swap(int &a, int &b)
{
	int aux = a;
	a = b;
	b = aux;
}

void merge(std::vector<std::vector<int>> &pairs, int start, int mid, int end)
{
	return ;
}

void mergesort(std::vector<std::vector<int>> &pairs, int start, int end)
{
	int mid;

	if (start > end)
		return ;
	mid = start + (start + end) / 2; 
	mergesort(pairs, start, mid);
	mergesort(pairs, mid + 1, end);
	merge(pairs, start, mid, end);
}

// Sort the vector of pairs in ascending order using merge sort and comparing the a value
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
	
	for (size_t i = 0; i < pairs.size(); i++)
	{
		std::cout << "PAIR (A B) [" << i << "]\n";
		print(pairs.at(i));
	}
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