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

class ScalarConverter
{
	private:
		// void toDouble(const std::string &str) const;
		// void toFloat(const std::string &str) const;
		// void toInt(const std::string &str) const;
		// void toChar(const std::string &str) const;

	public:
		static void convert(const std::string &str);
};

#endif