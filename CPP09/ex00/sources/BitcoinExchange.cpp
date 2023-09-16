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
	this->database = right.database;
	return (*this);
}

//! _____________________ MEMBER FUNCTIONS _______________________

bool BTC::convert(const char *filename)
{
	std::ifstream	infile;
	std::string		line, date;
	double			ammount, worth;

	// Attemps to open and read the database file
	if (!this->readExchangeRates())
		return (false);

	// Attempts to open the file
	infile.open(filename, std::ios::in);
	if (infile.fail())
		return (false);

	// Ignores the first line of the input file
	std::getline(infile, date);
	while (!infile.eof())
	{
		std::getline(infile, line);
		if (line == "" || !extract(line, date, ammount))
			continue;
		if (database.find(date) == database.end())
			worth = findClosestDate(date);
		else
			worth = database[date];
		std::cout << date << " => " << ammount << " = " << ammount * worth << std::endl;
	}
	infile.close();
	return (true);
}

bool BTC::readExchangeRates(void)
{
	std::ifstream		infile;
	std::string			key, value;

	// Attempts to open the file
	infile.open("data.csv", std::ios::in);
	if (infile.fail())
		return (ERROR_BAD_FILE("data.csv"), false);

	// Ignores the first line of the database
	std::getline(infile, key);
	while (1)
	{
		std::getline(infile, key, ',');
		std::getline(infile, value);
		if (infile.eof())
			break;
		database[key] = std::atof(value.c_str());
	}
	infile.close();
	return (true);
}

bool BTC::extract(const std::string &line, std::string &date, double &ammount)
{
	std::istringstream	stream(line);
	char				delimiter;

	if (!(stream >> date >> delimiter >> ammount))
		return (ERROR_BAD_INPUT(line), false);
	if (!isValidDate(date))
		return (ERROR_BAD_DATE(line), false);
	if (ammount < 0)
		return (ERROR_BAD_NUM(line), false);
	if (ammount > 1000)
		return (ERROR_NOT_INT(line), false);
	return (true);
}

bool BTC::isValidDate(const std::string &date)
{
	char 				hifen;
	std::stringstream	stream(date);
	struct tm 			old = {}, normalized = {};

	// Prevents something like '2001-09-3'
	if (date.size() != 10)
		return (false);

	// Assess if the string format is 'num-num-num'
	if (!(stream >> old.tm_year >> hifen >> old.tm_mon >> hifen >> old.tm_mday))
		return (false);

	old.tm_mon -= 1;
	old.tm_year -= 1900;
	normalized = old;
	mktime(&normalized);

	return (normalized.tm_year == old.tm_year \
			&& normalized.tm_mon == old.tm_mon \
			&& normalized.tm_mday == old.tm_mday);
}

double BTC::findClosestDate(const std::string &date)
{
	std::map<std::string, float>::iterator current;
	std::map<std::string, float>::iterator previous;

	// If the date is older than the database
	if (date < database.begin()->first)
		return (0);

	// If the date is newer than the database
	if (date > database.rbegin()->first)
		return (database.rbegin()->second);

	// Find the closest lower date by stopping at a bigger date 
	previous = database.begin();
	current = database.begin();
	current++;
	while (current != database.end())
	{
		if (current->first > date)
			return (previous->second);
		previous = current;
		++current;
	}
	return (0);	
}

void BTC::dump(void)
{
	std::map<std::string, float>::iterator it;

	for (it = database.begin(); it != database.end(); it++)
		std::cout << "Key = " + it->first + " Value = " << it->second << "\n";
	std::cout << std::endl;
}
