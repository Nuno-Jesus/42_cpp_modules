#include "Harl.hpp"

Harl :: Harl(void)
{
	LOG("Harl default constructor called.");
}

Harl :: ~Harl(void)
{
	LOG("Harl died.");
}

void Harl :: complain (std::string level)
{
	//Array of member function pointers to functions of Harl class
	void (Harl::*funcs[4])() = 
	{
		&Harl::debug,
		&Harl::info,
		&Harl::warning,
		&Harl::error,
	};

	//Array of available levels
	std::string levels[4] = 
	{
		"DEBUG",
		"INFO",
		"WARNING",
		"ERROR"
	};
	
	for (int i = 0; i < 4; i++)
		if (levels[i] == level)
			(this->*funcs[i])();
}

void Harl :: debug( void )
{
	std::cout << "I love having extra bacon for my" \
		"7XL-double-cheese-triple-pickle-specialketchup" \
		"burger. I really do!" << std::endl;
}

void Harl :: info( void )
{
	std::cout << "I cannot believe adding extra bacon costs more money. ";
	std::cout << "You didn't put enough bacon in my burger! ";
	std::cout << "If you did, I wouldn't be asking for more!" << std::endl;
}

void Harl :: warning( void )
{
	std::cout << "I think I deserve to have some extra bacon for free. ";
	std::cout << "I've been coming for years whereas you started working here since last month." << std::endl;
}

void Harl :: error( void )
{
	std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}
