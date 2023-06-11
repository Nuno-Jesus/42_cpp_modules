/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:37:08 by marvin            #+#    #+#             */
/*   Updated: 2023/06/11 20:37:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ScalarConverter.hpp"

void toChar(const char *str)
{
	std::cout << "char: ";
	try
	{
		char c = static_cast<char>(atoi(str));
		if (!isprint(c))
			std::cout << "Non displayable" << std::endl;
		else
			std::cout << "'" << c << "'" << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "impossible" << std::endl;
	}
}

void ScalarConverter::convert(const std::string &str)
{
	toChar(str.c_str());
}