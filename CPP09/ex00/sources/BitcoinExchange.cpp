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
	while (1)
	{
		std::getline(infile, key, ',');
		std::getline(infile, value);
		if (infile.eof())
			break;
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
		return (ERROR_BAD_DATE(line), false);
	if (ammount < 0)
		return (ERROR_BAD_NUM(line), false);
	if (ammount > std::numeric_limits<int>::max())
		return (ERROR_NOT_INT(line), false);
	return (true);
}

bool BTC::isValidDate(const std::string &date)
{
	int					end;
	std::string 		tmp(date);
	std::stringstream	stream;
	struct tm 			t, norm;

	// Dates must have yyyy-mm-dd format to begin with
	if (date.size() != 10)
		return (false);

	end = tmp.find('-');
	while (end != -1)
	{
		stream << tmp.substr(0, end) + " ";
		if (tmp.substr(0, end) == "")
			return (false);
		tmp.erase(0, end + 1);
		end = tmp.find('-');
	}
	stream << tmp.substr(0, end);
	if (!(stream >> t.tm_year >> t.tm_mon >> t.tm_mday))
		return (false);
	
	t.tm_sec = 0;
	t.tm_min = 0;
	t.tm_hour = 0;
	t.tm_mon -= 1;
	t.tm_year -= 1900;
	t.tm_wday = 0;
	t.tm_yday = 0;
	t.tm_isdst = -1;

	norm = t;
	
	mktime(&norm);

	return (norm.tm_year == t.tm_year \
			&& norm.tm_mon == t.tm_mon \
			&& norm.tm_mday == t.tm_mday);
}

double BTC::findClosestDate(const std::string &date)
{
	std::map<std::string, float>::iterator it;
	std::map<std::string, float>::iterator prev;

	// If the date is older than the database
	if (date < conversions.begin()->first)
		return (0);

	// If the date is newer than the database
	if (date > conversions.rbegin()->first)
		return (conversions.rbegin()->second);

	prev = conversions.begin();
	it = conversions.begin();
	it++;
	while (it != conversions.end())
	{
		if (it->first > date)
			return (prev->second);
		prev = it;
		++it;
	}
	return (-1);
}


void BTC::convert(const char *filename)
{
	std::ifstream	infile;
	std::string		line, date;
	double			ammount, worth;

	// Attempts to open the file
	infile.open(filename, std::ios::in);
	if (infile.fail())
		throw MissingFileException();

	// Ignores the first line of the database
	std::getline(infile, date);
	while (!infile.eof())
	{
		std::getline(infile, line);
		if (line == "" || !extract(line, date, ammount))
			continue;
		if (conversions.find(date) == conversions.end())
			worth = findClosestDate(date);
		else
			worth = conversions[date];
		std::cout << date << " => " << ammount << " = " << ammount * worth << std::endl;
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
