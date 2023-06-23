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

void ScalarConverter::convert(const std::string &str)
{
	bool (ScalarConverter::*func)(const std::string&) = 
	ScalarConverter::parse(str);

}

void ScalarConverter::parse(const std::string &str)
{
	if (ScalarConverter::isChar(str))
		std::cout << str << " is char\n";
	else if (ScalarConverter::isInt(str))
		std::cout << str << " is int\n";
	else if (ScalarConverter::isFloat(str))
		std::cout << str << " is float\n";
	else if (ScalarConverter::isDouble(str))
		std::cout << str << " is double\n";
	else if (ScalarConverter::isPseudo(str))
		std::cout << str << " is pseudo\n";
	else
		std::cout <<"\n\t======== " <<  str << " is of UNKNOWN type ========\n\n";
}

bool ScalarConverter::isChar(const std::string &str)
{
	return (str.size() <= 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string &str)
{
	size_t signal = str.find('-');
	size_t index = 0;

	// If '-' exists and is not in the beginning, abort
	if (signal != std::string::npos && signal != 0)
		return (false);

	// If the string starts with a '-' the search index must start at 1
	if (signal == 0)
		index = 1;

	// Check if any of the chars is not a digit
	if (str.find_first_not_of(DIGITS, index) != std::string::npos)
		return (false);
	
	// If '-' exists, the string must have more than just the '-'
	return (signal == 0 ? str.size() > 1 : str.size() > 0);
}

bool ScalarConverter::isFloat(const std::string &str)
{
	size_t index = 0;
	size_t f = str.find('f');
	size_t dot = str.find('.');
	size_t signal = str.find('-');

	if (dot == std::string::npos || f == std::string::npos)
		return (false);
	if (signal != std::string::npos)
		index = 1;

	//Get a substring for both decimal and fractional part
	std::string decimalPart = str.substr(index, dot - index);
	std::string fractionalPart = str.substr(dot + 1, f - dot - 1);

	if (!decimalPart.size() || !fractionalPart.size())
		return (false);
	return (true);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	size_t index = 0;
	size_t dot = str.find('.');
	size_t signal = str.find('-');

	if (dot == std::string::npos)
		return (false);
	if (signal != std::string::npos)
		index = 1;

	//Get a substring for both decimal and fractional part
	std::string decimalPart = str.substr(index, dot - index);
	std::string fractionalPart = str.substr(dot + 1, std::string::npos);

	if (!decimalPart.size() || !fractionalPart.size())
		return (false);
	return (true);
}

bool ScalarConverter::isPseudo(const std::string &str)
{
	return (str == "-inff" || str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan");
}
