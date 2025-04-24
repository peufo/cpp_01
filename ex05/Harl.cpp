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