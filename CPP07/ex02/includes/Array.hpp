/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 17:46:31 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/07/01 19:05:21 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <iomanip>

template <typename T>
class Array
{
	private:
		T *array;
		unsigned int n;

	public:
		//! Constructors and destructor
		Array();
		Array(unsigned int n);
		Array(const Array& copy);
		~Array();

		//! Member functions
		unsigned int size(void) const;

		//! Operator overloading
		Array& operator=(const Array& right);
		T& operator[](unsigned int index);

	class IndexOutOfBoundsException : public std::exception
	{
		public:
			virtual const char* what() const throw();
	};
		
};

#include "Array.tpp"

#endif
