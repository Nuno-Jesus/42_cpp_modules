/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 16:58:50 by marvin            #+#    #+#             */
/*   Updated: 2023/07/02 16:58:50 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <iomanip>
# include <limits>
# include <ctime>
# include <algorithm>
# include <vector>

# define RED "\033[1;31m"
# define GREEN "\033[1;32m"
# define RESET "\033[0m"

class Span
{
	private:
		unsigned int N;
		std::vector<int> storage;

	public:
		//! Constructors and destructor
		Span();
		Span(unsigned int N);
		Span(const Span& copy);
		~Span();

		//! Operator overloading
		Span& operator=(const Span& right);

		//! Member functions
		void addNumber(int number);
		int shortestSpan(void);
		int longestSpan(void);
		void fill(void);

		//! Getters
		unsigned int size(void) const;
		std::vector<int> getStorage(void) const;

		class FullSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};

		class NoSpanException : public std::exception
		{
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator <<(std::ostream& out, const Span& span);

#endif
