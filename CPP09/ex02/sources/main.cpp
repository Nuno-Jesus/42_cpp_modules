/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:22:07 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/16 18:34:28 by ncarvalh         ###   ########.fr       */
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


void mergeInsertionSortVector(int n, std::vector<int> &nums)
{
	std::vector<std::vector<int>> vec(n / 2, std::vector<int>(2));

	std::cout << "Before: ";
	print(nums);

	std::cout << "After: ";
	// print(vec);
	
	// for (int i = 0; i < n; i++)
	
}

int main(int argc, char **argv)
{
	std::vector<int>	vec;
	std::list<int>		list;
	
	if (argc < 2)
		return (-1);
	if (!parse(argv + 1, vec, list))	
		std::cout << "Error\n";
	mergeInsertionSortVector(std::ceil(argc / 2), vec);
	return (0);
}