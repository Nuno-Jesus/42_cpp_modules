#include "BitcoinExchange.hpp"

//! ________________________ CONSTRUCTORS ________________________

BTC::BTC()
{
	
}

BTC::BTC(const BTC& copy)
{
	*this = copy;
}

BTC::~BTC()
{
	
}

//! ____________________ OPERATOR OVERLOADING ____________________

BTC& BTC::operator=(const BTC& right)
{
	if (this == &right)
		return (*this);
	this->conversions = right.conversions;
	return (*this);
}

//! _____________________ MEMBER FUNCTIONS _______________________

void BTC::readExchangeRates(void)
{
	std::ifstream		infile;
	std::string			key, value;

	// Attempts to open the file
	infile.open("data.csv", std::ios::in);
	if (infile.fail())
		throw MissingFileException();

	// Ignores the first line of the database
	std::getline(infile, key);
	while (!infile.eof())
	{
		std::getline(infile, key, ',');
		std::getline(infile, value);
		conversions[key] = std::atof(value.c_str());
	}
	infile.close();
}

bool BTC::extract(const std::string &line, std::string &date, double &ammount)
{
	std::istringstream	stream(line);
	std::string			delimiter;

	if (!(stream >> date >> delimiter >> ammount))
		return (ERROR_BAD_INPUT(line), false);
	if (!isValidDate(date))
		return (false);
	// return (false);
	return (true);
}

bool BTC::isValidDate(const std::string &date)
{
	int					end;
	std::string 		tmp(date);
	std::stringstream	stream;
	struct tm 			t;

	end = tmp.find('-');
	while (end != -1)
	{
		stream << tmp.substr(0, end) + " ";
		tmp.erase(0, end + 1);
		end = tmp.find('-');
	}
	stream << tmp.substr(0, end);
	if (!(stream >> t.tm_year >> t.tm_mon >> t.tm_mday))
		return (false);
	
	t.tm_year -= 1900;
	t.tm_mon -= 1;

	time_t x = mktime(&t);
	const struct tm *norm = localtime(&x);

	if (norm->tm_year == t.tm_year && norm->tm_mon == t.tm_mon && norm->tm_mday == t.tm_mday)
		std::cout << date << " is a valid date" << std::endl;
	else
		std::cout << date << " is an invalid date" << std::endl;
	return (true);
}

void BTC::convert(const char *filename)
{
	std::ifstream	infile;
	std::string		line, date;
	double			value;

	// Attempts to open the file
	infile.open(filename, std::ios::in);
	if (infile.fail())
		throw MissingFileException();

	// Ignores the first line of the database
	std::getline(infile, date);
	while (!infile.eof())
	{
		std::getline(infile, line);
		if (!extract(line, date, value))
			continue;
	}
	infile.close();
}

// void BTC::dump(void)
// {
// 	std::map<std::string, float>::iterator it;

// 	for (it = conversions.begin(); it != conversions.end(); it++)
// 		std::cout << "Key = " + it->first + " Value = " << it->second << "\n";
// 	std::cout << std::endl;
// }

const char * BTC::MissingFileException::what(void) const throw()
{
	return (RED "Error opening a database (missing file perhaps?)" RESET);
}
