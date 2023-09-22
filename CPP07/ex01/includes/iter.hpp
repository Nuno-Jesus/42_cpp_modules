/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarvalh <ncarvalh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 16:54:36 by ncarvalh          #+#    #+#             */
/*   Updated: 2023/09/22 18:13:45 by ncarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <sstream>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

# define ERROR(x) 		std::cout << x << std::endl
# define ERROR_USAGE(e)	ERROR("Usage: " << e << " test_number")
# define ERROR_NOT_INT	ERROR("Error: test number must be a number")
# define ERROR_TESTNO	ERROR("Error: test number must be bounded between 0 and 1")

template <typename T>
void iter(T *array, int len, void (*f)(T&))
{
	for (int i = 0; i < len; i++)
		(*f)(array[i]);	
}
