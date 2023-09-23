/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 17:23:30 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/23 19:03:46 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <limits>
# include <chrono>
# include <cmath>
# include <vector>
# include <list>
# include <algorithm>

# define UNUSED -1
# define A 0
# define B 1
# define MIN(a, b) ((a) < (b) ? (a) : (b))
# define MAX(a, b) ((a) > (b) ? (a) : (b))

class PmergeMe
{
	//! _______________________ PRIVATE FIELDS _______________________
	private:
		const std::string type;
		std::chrono::high_resolution_clock::time_point start, end;
		std::chrono::duration<double> elapsedTime;
		
	public:
	//! ________________________ CONSTRUCTORS ________________________
		PmergeMe();
		PmergeMe(const PmergeMe& copy);
		~PmergeMe();

	//! ____________________ OPERATOR OVERLOADING ____________________
		PmergeMe& operator=(const PmergeMe& right);
		
	//! __________________ PUBLIC MEMBER FUNCTIONS ___________________
	double mergeInsertionSort(std::vector<int> &nums);
	bool parse(char **argv, std::vector<int> &vec, std::list<int> &list);

	//! _________________ PRIVATE MEMBER FUNCTIONS ___________________
	private:
		std::vector<std::vector<int>> createPairs(const std::vector<int> &nums);
		std::vector<std::vector<int>> mergeSort(std::vector<std::vector<int>> &pairs);
		std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &left, std::vector<std::vector<int>> &right);
		void generateJacobsthalSequence(std::vector<size_t> &vec);
		void insertionSort(std::vector<int> &S, size_t n, const std::vector<std::vector<int>> &pairs);
		void binarySearch(std::vector<int> &S, int number);
};

#endif