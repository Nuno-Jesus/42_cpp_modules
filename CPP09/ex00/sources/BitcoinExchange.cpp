#include "BitcoinExchange.hpp"

//! ________________________ CONSTRUCTORS ________________________

BitcoinExchange::BitcoinExchange()
{
	
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& copy)
{
	*this = copy;
}

BitcoinExchange::~BitcoinExchange()
{
	
}

//! ____________________ OPERATOR OVERLOADING ____________________

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& right)
{
	if (this == &right)
		return (*this);
	this->stock = right.stock;
	this->input = right.input;
	return (*this);
}

//! _____________________ MEMBER FUNCTIONS _______________________



void BitcoinExchange::readStockDatabase(void)
{
	std::string			str;
	std::ifstream		infile;

	infile.open("data.csv", std::ios::in);
	if (infile.fail())
		throw MissingFileException();

	// Ignores the first line of the database
	std::getline(infile, str);
	while (!infile.eof())
	{
		std::getline(infile, str);
		
	}
	infile.close();
}

const char * BitcoinExchange::MissingFileException::what(void) const throw()
{
	return (RED "Error opening a database (missing file perhaps?)" RESET);
}
