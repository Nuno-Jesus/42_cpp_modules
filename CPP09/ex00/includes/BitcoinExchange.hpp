/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:20:55 by crypto            #+#    #+#             */
/*   Updated: 2023/09/12 18:55:37 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <fstream>
# include <sstream>
# include <string>
# include <cstring>
# include <cstdlib>
# include <ctime>
# include <map>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"
// # define DEBUG

# define ERROR(str)			std::cout << str << "\n"
# define ERROR_BAD_INPUT(x)	ERROR("Error: missing fields => '" + x + "'")
# define ERROR_BAD_DATE(x)	ERROR("Error: weird date => '" + x + "'")
# define ERROR_NOT_INT (x)	ERROR("Error: ammount must be an integer => '" + x + "'")

class BTC
{
	private:
		std::map<std::string, float> conversions;

	public:
		//! Constructors and destructor
		BTC();
		BTC(const BTC& copy);
		~BTC();

		//! Operator overloading
		BTC& operator=(const BTC& right);

		//! Member functions
		void readExchangeRates(void);
		void convert(const char *filename);
		void dump(void);
	
	private:
		bool extract(const std::string &line, std::string &date, double &ammount);
		bool isValidDate(const std::string &date);

	class MissingFileException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif