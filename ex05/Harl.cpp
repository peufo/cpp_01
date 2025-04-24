#include "Harl.hpp"

Harl::Harl()
{
	this->func_map["debug"] = &Harl::debug;
	this->func_map["info"] = &Harl::info;
	this->func_map["warning"] = &Harl::warning;
	this->func_map["error"] = &Harl::error;
}

Harl::~Harl()
{
}

void Harl::complain(std::string level)
{
	Harl::log_func func = this->func_map[level];

	std::cout << "[" << level << "]\t";
	if (func)
		(this->*func)();
	else
		std::cout << "???" << std::endl;
}

void Harl::debug(void)
{
	std::string msg = "I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!";
	std::cout << msg << std::endl;
}

void Harl::info(void)
{
	std::string msg = "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!";
	std::cout << msg << std::endl;
}

void Harl::warning(void)
{
	std::string msg = "I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.";
	std::cout << msg << std::endl;
}

void Harl::error(void)
{
	std::string msg = "This is unacceptable! I want to speak to the manager now.";
	std::cout << msg << std::endl;
}