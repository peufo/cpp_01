#include "Harl.hpp"

static std::string toLower(std::string str)
{
	for (std::string::iterator it = str.begin(); it != str.end(); it++)
		if ('A' <= *it && *it <= 'Z')
			*it += 32;
	return (str);
}

Harl::Harl(std::string level)
{
	std::string level_name = toLower(level);
	int level_index = -1;

	this->levels[0].name = "debug";
	this->levels[0].func = NULL;
	this->levels[1].name = "info";
	this->levels[1].func = NULL;
	this->levels[2].name = "warning";
	this->levels[2].func = NULL;
	this->levels[3].name = "error";
	this->levels[3].func = NULL;

	for (int i = 0; i < 4 && level_index  == -1; i++)
		if (this->levels[i].name == level_name)
			level_index = i;

	switch (level_index)
	{
		case 0:
			this->levels[0].func = &Harl::debug;
			__attribute__ ((fallthrough));
		case 1:
			this->levels[1].func = &Harl::info;
			__attribute__ ((fallthrough));
		case 2:
			this->levels[2].func = &Harl::warning;
			__attribute__ ((fallthrough));
		case 3:
			this->levels[3].func = &Harl::error;
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	Harl::logFunc func(NULL);

	for (int i = 0; i < 4 && !func; i++)
		if (this->levels[i].name == level)
			func = this->levels[i].func;
	if (!func)
		return ;
	(this->*func)();
}

void Harl::debug(void)
{
	std::cout << "[DEBUG]" << std::endl;
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "[INFO]" << std::endl;
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[WARNING]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ERROR]" << std::endl;
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl;
}
