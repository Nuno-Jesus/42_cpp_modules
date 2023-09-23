/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:22:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/23 16:48:27 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

# define A 0
# define B 1

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
		if (left[0][A] < right[0][A] || right[0][A] == UNUSED)
		{
			std::cout << "L" << std::endl;
			result.push_back(left.front());
			left.erase(left.begin());
		}
		else
		{
			std::cout << "R" << std::endl;
			result.push_back(right.front());
			right.erase(right.begin());
		}
	}
	
	// Empty out left vector, if the right vector had the lowest values
	while (!left.empty())
	{
		result.push_back(left.front());
		left.erase(left.begin());
	}
	
	// Empty out right vector, if the left vector had the lowest values
	while (!right.empty())
	{
		result.push_back(right.front());
		right.erase(right.begin());
	}

	// std::cout << "\tAFTER MERGING" << std::endl;
	// print(result);
	std::cout << "\n\t==============\n" << std::endl;
	return(result);
}

std::vector<std::vector<int>> mergeSort(std::vector<std::vector<int>> &pairs)
{
	std::vector<std::vector<int>> left(pairs.begin(), pairs.begin() + pairs.size() / 2);
	std::vector<std::vector<int>> right(pairs.begin() + pairs.size() / 2, pairs.end());

	if (pairs.size() == 1)
		return (pairs);
	left = mergeSort(left);
	right = mergeSort(right);
	return (merge(left, right));
}

std::vector<std::vector<int>> matrify(const std::vector<int> &nums)
{
	size_t							numPairs = std::ceil(nums.size() / 2.0);
	std::vector<std::vector<int>>	pairs(numPairs, std::vector<int>(2, UNUSED));

	for (size_t i = 0; i < pairs.size(); i++)
	{
		if ((2 * i + 1) < nums.size())
		{
			pairs[i][A] = nums[2 * i];
			pairs[i][B] = nums[2 * i + 1];			
		}
		else
			pairs[i][B] = nums[2 * i];
			
		// Sort each pair of ints in ascending order (a, b)
		if (pairs[i][B] < pairs[i][A])
			swap(pairs[i][B], pairs[i][A]);
	}
	return (pairs);
}

void generateJacobsthalSequence(std::vector<size_t> &vec)
{
	for (size_t i = 0; i < vec.size(); i++)
		vec[i] = (pow(2, i + 2) - pow(-1, i + 2)) / 3;
}

void qq(void)
{
	/* 		int k = jacobSequence[i];
		int start = 0;
		int end = pairs.size() - 1;
		int middle;
		while (end - start > 1)
		{
			middle = start + (end - start) / 2;
			if (pairs[k][B] > S[middle])
				start = middle;
			else if (pairs[k][1] < S[middle])		
				end = middle;
			if (end - start == 1)
				S.insert(S.begin() + end, pairs[k][B]);
		}
 */
}

void binaryInsertionSort(std::vector<int> &S, size_t n, const std::vector<std::vector<int>> &pairs)
{
	(void)S;
	std::vector<size_t>	jacobSequence(pairs.size());

	generateJacobsthalSequence(jacobSequence);
	print(jacobSequence);
	S.push_back(pairs[0][B]);
	S.push_back(pairs[1][B]);
	for (size_t i = 1; i < jacobSequence.size(); i++)
	{
		for (size_t k = jacobSequence[i]; k > jacobSequence[i - 1]; k--)
		{
			std::cout << "k = " << k << std::endl;
			if (k >= pairs.size())
				continue ;
			S.push_back(pairs[k][B]);
			std::cout << S.size() << std::endl;
			if (S.size() == n)
				return ;
		}
	}
}


void mergeInsertionSort(const std::vector<int> &nums)
{
	std::vector<std::vector<int>>	pairs;
	std::vector<int> 				S;
	
	// Split the vector in pairs of ints
	pairs = matrify(nums);
	// Sort the vector of pairs in ascending order using merge sort and comparing the a value
	pairs = mergeSort(pairs);	
	
	std::cout << "FINAL RESULT" << std::endl;
	print(pairs);

	for (size_t i = 0 ; i < pairs.size() && pairs[i][A] != UNUSED; i++)
		S.push_back(pairs[i][A]);
	std::cout << "Size of nums: " << nums.size() << std::endl;

	std::cout << "S = ";
	print(S);
	
	// Use binary search to insert the b values in the chain of S
	binaryInsertionSort(S, nums.size(), pairs);
	std::cout << "S = ";
	print(S);
	
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