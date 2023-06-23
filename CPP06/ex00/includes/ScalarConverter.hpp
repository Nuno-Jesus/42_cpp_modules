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
# include <string>
# include <cstdlib>

# define DIGITS "0123456789"

class ScalarConverter
{
	public:
		static void convert(const std::string &str);
		
	private:
		static void parse(const std::string &str);
		
		//! Parser helpers
		static bool isChar(const std::string &str);
		static bool isInt(const std::string &str);
		static bool isFloat(const std::string &str);
		static bool isDouble(const std::string &str);
		static bool isPseudo(const std::string &str);

		//! Conversions
		// static void toDouble(const std::string &str);
		// static void toFloat(const std::string &str);
		// static void toInt(const std::string &str);
		// static void toChar(const std::string &str);
};

#endif
