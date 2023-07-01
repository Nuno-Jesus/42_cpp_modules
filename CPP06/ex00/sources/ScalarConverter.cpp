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

ScalarConverter::ScalarConverter()
{
	
}

ScalarConverter::ScalarConverter(const ScalarConverter& copy)
{
	*this = copy;
}

ScalarConverter::~ScalarConverter()
{
	
}

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& right)
{
	if (this == &right)
		return (*this);
	return (*this);
}

void ScalarConverter::convert(const std::string &str)
{
	if (ScalarConverter::isChar(str))
		ScalarConverter::convertNumber(str, str[0]);
	else if (ScalarConverter::isInt(str))
		ScalarConverter::convertNumber(str, std::atoi(str.c_str()));
	else if (ScalarConverter::isFloat(str))
		ScalarConverter::convertNumber(str, std::strtof(str.c_str(), NULL));
	else if (ScalarConverter::isDouble(str))
		ScalarConverter::convertNumber(str, std::strtod(str.c_str(), NULL));
	else if (ScalarConverter::isPseudo(str))
		ScalarConverter::convertPseudo(str);
	else
		std::cout <<"\n\t======== " << str << " is a weird type ========\n\n";
}

void ScalarConverter::convertNumber(const std::string& input, long double number)
{
	ScalarConverter::convertChar(static_cast<char>(number), input);
	ScalarConverter::convertInt(static_cast<int>(number), input);
	ScalarConverter::convertFloat(static_cast<float>(number), input);
	ScalarConverter::convertDouble(static_cast<double>(number), input);
}

void ScalarConverter::convertChar(char c, const std::string &input)
{
	if (ScalarConverter::overflows(input, CHAR))
		std::cout << "char: overflow\n";
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: Non displayable\n";
}

void ScalarConverter::convertInt(int num, const std::string &str)
{
	if (ScalarConverter::overflows(str, INT))
		std::cout << "int: overflow\n";
	else
		std::cout << "int: " << num << "\n";
}

void ScalarConverter::convertFloat(float num, const std::string &str)
{
	if (ScalarConverter::overflows(str, FLOAT))
		std::cout << "float: overflow\n";
	else
		std::cout << "float: " << std::fixed << num << "f\n";
}

void ScalarConverter::convertDouble(double num, const std::string &str)
{
	if (ScalarConverter::overflows(str, DOUBLE))
		std::cout << "double: overflow\n";
	else
		std::cout << "double: " << num << "\n";
}

void ScalarConverter::convertPseudo(const std::string &str)
{
	std::cout << "char: impossible\n";
	std::cout << "int: impossible\n";
	
	if (str.find("nan") != std::string::npos)
	{
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else
	{
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str.substr(0, str.size() - 1) << "\n";
	}
}

bool ScalarConverter::overflows(const std::string &str, t_type type)
{
	long double number;

	number = std::strtold(str.c_str(), NULL);
	switch (type)
	{
		case CHAR:
			return (number < std::numeric_limits<char>::min() \
				|| number > std::numeric_limits<char>::max());
		case INT:
			return (number < std::numeric_limits<int>::min() \
				|| number > std::numeric_limits<int>::max());
		case FLOAT:
			return (number < -std::numeric_limits<float>::max()  \
				|| number > std::numeric_limits<float>::max());
		case DOUBLE:
			return (number < -std::numeric_limits<double>::max() \
				|| number > std::numeric_limits<double>::max());
		default:
			return (false);
	}
	//! Note:
	// std::numeric_limits<float>::min() does not represent the minimum float value
	// but the smallest floating point positive number to be represented by a float
	// To find the lowest float value, use std::numeric_limits<float>::lowest()
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

	// If any of the characters is not a digit, the number is not an int
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

	//If either the dot or the f is not found, the number is not a float
	if (dot == std::string::npos || f == std::string::npos)
		return (false);
	if (signal != std::string::npos)
		index = 1;

	//Get a substring for both decimal and fractional part
	std::string decimalPart = str.substr(index, dot - index);
	std::string fractionalPart = str.substr(dot + 1, f - dot - 1);

	//The decimal and fractional part must have at least one digit
	return (decimalPart.size() > 0 && fractionalPart.size() > 0);
}

bool ScalarConverter::isDouble(const std::string &str)
{
	size_t index = 0;
	size_t dot = str.find('.');
	size_t signal = str.find('-');

	//If the dot is missing, the number is not a double
	if (dot == std::string::npos)
		return (false);
	if (signal != std::string::npos)
		index = 1;

	//Get a substring for both decimal and fractional part
	std::string decimalPart = str.substr(index, dot - index);
	std::string fractionalPart = str.substr(dot + 1, std::string::npos);

	//The decimal and fractional part must have at least one digit
	return (decimalPart.size() > 0 && fractionalPart.size() > 0);
}

bool ScalarConverter::isPseudo(const std::string &str)
{
	return (str == "-inff" || str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan");
}
