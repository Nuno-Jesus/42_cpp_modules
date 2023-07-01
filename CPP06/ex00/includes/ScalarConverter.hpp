/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 20:28:30 by marvin            #+#    #+#             */
/*   Updated: 2023/06/11 20:28:30 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <iostream>
# include <iomanip>
# include <string>
# include <cstdlib>
# include <limits>

# define DIGITS "0123456789"
typedef enum
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	PSEUDO
}t_type;

class ScalarConverter
{

	public:
		static void convert(const std::string &str);
		
	private:		
		static void convertNumber(const std::string &str, long double number);
		//! Parser helpers
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isPseudo(const std::string &str);

		//! Conversions
		static void convertChar(char c, const std::string &input);
		static void convertInt(int num, const std::string &str);
		static void convertFloat(float num, const std::string &str);
		static void convertDouble(double num, const std::string &str);
		static void convertPseudo(const std::string &str);

		static bool overflows(const std::string &str, t_type type);
};

#endif
