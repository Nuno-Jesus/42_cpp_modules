/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: crypto <crypto@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 18:20:55 by crypto            #+#    #+#             */
/*   Updated: 2023/09/05 19:07:00 by crypto           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOIN_EXCHANGE_HPP
# define BITCOIN_EXCHANGE_HPP

# include <iostream>
# include <iomanip>
# include <fstream>
# include <sstream>
# include <map>

# define RED	"\033[1;31m"
# define GREEN	"\033[1;32m"
# define RESET	"\033[0m"

class BitcoinExchange
{
	private:
		std::map<std::string, double> stock;
		std::map<std::string, double> input;

	public:
		//! Constructors and destructor
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange& copy);
		~BitcoinExchange();

		//! Operator overloading
		BitcoinExchange& operator=(const BitcoinExchange& right);

		//! Member functions
		void readStockDatabase(void);
	
	private:
		void updateMap(const std::string &str);

	class MissingFileException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif