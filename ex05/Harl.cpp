#include "Harl.hpp"

Harl::Harl()
{
	this->levels[0].name = "debug";
	this->levels[0].func = &Harl::debug;
	this->levels[1].name = "info";
	this->levels[1].func = &Harl::info;
	this->levels[2].name = "warning";
	this->levels[2].func = &Harl::warning;
	this->levels[3].name = "error";
	this->levels[3].func = &Harl::error;
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
	std::cout << "[" << level << "]" << std::endl;
	if (func)
		(this->*func)();
	else
		std::cout << "???" << std::endl;
	std::cout << std::endl;
}

void Harl::debug(void)
{
	std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger." << std::endl;
	std::cout << "I really do!" << std::endl;
}

void Harl::info(void)
{
	std::cout << "I cannot believe adding extra bacon costs more money." << std::endl;
	std::cout << "You didn’t put enough bacon in my burger!" << std::endl;
	std::cout << "If you did, I wouldn’t be asking for more!" << std::endl;
}

void Harl::warning(void)
{
	std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
	std::cout << "I’ve been coming for years, whereas you started working here just last month." << std::endl;
}

void Harl::error(void)
{
	std::cout << "This is unacceptable!" << std::endl;
	std::cout << "I want to speak to the manager now." << std::endl;
}
