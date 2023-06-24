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

# define DIGITS "0123456789"

class ScalarConverter
{
	//Typedef a pointer for a member function that returns a bool
	typedef enum
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		PSEUDO
	}t_type;

	public:
		static void convert(const std::string &str);
		static void convert(const std::string &str, ScalarConverter::t_type type);
		
	private:		
		//! Parser helpers
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isPseudo(const std::string &str);

		//! Conversions
		static void convertChar(const std::string &str);
		static void convertInt(const std::string &str);
		static void convertFloat(const std::string &str);
		static void convertDouble(const std::string &str);
		static void convertPseudo(const std::string &str);
};

#endif
