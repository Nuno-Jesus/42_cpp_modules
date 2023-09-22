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
	if (isChar(str))
		convertNumber(str, str[0]);
	else if (isInt(str))
		convertNumber(str, std::atoi(str.c_str()));
	else if (isFloat(str))
		convertNumber(str, std::strtof(str.c_str(), NULL));
	else if (isDouble(str))
		convertNumber(str, std::strtod(str.c_str(), NULL));
	else if (isPseudo(str))
		convertPseudo(str);
	else
		std::cout <<"\n\t======== " << str << " is a weird type ========\n\n";
}

void ScalarConverter::convertNumber(const std::string& input, long double number)
{
	convertChar(static_cast<char>(number), input);
	convertInt(static_cast<int>(number), input);
	convertFloat(static_cast<float>(number), input);
	convertDouble(static_cast<double>(number), input);
}

void ScalarConverter::convertChar(char c, const std::string &input)
{
	if (overflows(input, CHAR))
		std::cout << "char: overflow\n";
	else if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: Non displayable\n";
}

void ScalarConverter::convertInt(int num, const std::string &str)
{
	if (overflows(str, INT))
		std::cout << "int: overflow\n";
	else
		std::cout << "int: " << num << "\n";
}

void ScalarConverter::convertFloat(float num, const std::string &str)
{
	if (overflows(str, FLOAT))
		std::cout << "float: overflow\n";
	else
		std::cout << "float: " << num << "f\n";
}

void ScalarConverter::convertDouble(double num, const std::string &str)
{
	if (overflows(str, DOUBLE))
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
		std::cout << "float: " << str[0] << "inff" << "\n";
		std::cout << "double: " << str[0] << "inf" << "\n";
	}
}

//! Note:
// std::numeric_limits<float>::min() does not represent the minimum float value
// but the smallest floating point positive number to be represented by a float
// To find the lowest float value, use std::numeric_limits<float>::lowest()
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
}

bool ScalarConverter::isChar(const std::string &str)
{
	return (str.size() <= 1 && std::isprint(str[0]) && !std::isdigit(str[0]));
}

bool ScalarConverter::isInt(const std::string &str)
{
	size_t signal = str.find('-');
	size_t index = 0;

	if (signal != std::string::npos && signal != 0)
		return (false);
	if (signal == 0)
		index = 1;
	if (str.find_first_not_of(DIGITS, index) != std::string::npos)
		return (false);
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

	std::string decimalPart = str.substr(index, dot - index);
	std::string fractionalPart = str.substr(dot + 1, f - dot - 1);

	if (fractionalPart.find('.') != std::string::npos)
		return (false);
	return (decimalPart.size() > 0 && fractionalPart.size() > 0);
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

	std::string decimalPart = str.substr(index, dot - index);
	std::string fractionalPart = str.substr(dot + 1, std::string::npos);

	if (fractionalPart.find('.') != std::string::npos)
		return (false);
	return (decimalPart.size() > 0 && fractionalPart.size() > 0);
}

bool ScalarConverter::isPseudo(const std::string &str)
{
	return (str == "-inff" || str == "+inff" || str == "nanf" 
		|| str == "-inf" || str == "+inf" || str == "nan");
}
