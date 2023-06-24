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
	if (ScalarConverter::isChar(str))
	{
		std::cout << str << " is char\n";
		ScalarConverter::convertChar(str);
	}
	else if (ScalarConverter::isInt(str))
	{
		std::cout << str << " is int\n";
		ScalarConverter::convertInt(str);
	}
	else if (ScalarConverter::isFloat(str))
	{
		std::cout << str << " is float\n";
		ScalarConverter::convertFloat(str);
	}
	else if (ScalarConverter::isDouble(str))
	{
		std::cout << str << " is double\n";
		ScalarConverter::convertDouble(str);
	}
	else if (ScalarConverter::isPseudo(str))
	{
		std::cout << str << " is pseudo\n";
		ScalarConverter::convertPseudo(str);
	}
	else
		std::cout <<"\n\t======== " <<  str << " is of UNKNOWN type ========\n\n";
}

void ScalarConverter::convertChar(const std::string &str)
{
	char c = str[0];

	if (std::isprint(c))
		std::cout << "char: '" << c << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(c) << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: "  << static_cast<float>(c) << "f\n";
	std::cout << "double: " << static_cast<double>(c) << "\n";
}

void ScalarConverter::convertInt(const std::string &str)
{
	int num = std::atoi(str.c_str());

	//Attempt to cast a string to an int and print impossible if the conversion overflows


	if (std::isprint(static_cast<char>(num)))
		std::cout << "char: '" << static_cast<char>(num) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << num << "\n";
	std::cout << std::fixed << std::setprecision(1);
	std::cout << "float: "  << static_cast<float>(num) << "f\n";
	std::cout << "double: " << static_cast<double>(num) << "\n";
}

void ScalarConverter::convertFloat(const std::string &str)
{
	float num = std::strtof(str.c_str(), NULL);

	if (std::isprint(static_cast<char>(num)))
		std::cout << "char: '" << static_cast<char>(num) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(num) << "\n";
	std::cout << "float: "  << num << "f\n";
	std::cout << "double: " << static_cast<double>(num) << "\n";
}

void ScalarConverter::convertDouble(const std::string &str)
{
	double num = std::strtod(str.c_str(), NULL);

	if (std::isprint(static_cast<char>(num)))
		std::cout << "char: '" << static_cast<char>(num) << "'\n";
	else
		std::cout << "char: Non displayable\n";
	std::cout << "int: " << static_cast<int>(num) << "\n";
	std::cout << "float: "  << static_cast<float>(num) << "f\n";
	std::cout << "double: " << num << "\n";
}

void ScalarConverter::convertPseudo(const std::string &str)
{
	if (str.find("nan") != std::string::npos)
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: nanf\n";
		std::cout << "double: nan\n";
	}
	else
	{
		std::cout << "char: impossible\n";
		std::cout << "int: impossible\n";
		std::cout << "float: " << str << "\n";
		std::cout << "double: " << str << "\n";
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
