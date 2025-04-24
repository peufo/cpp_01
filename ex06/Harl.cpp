#include "Harl.hpp"

static std::size_t get_hash(const std::string& str)
{
    static std::size_t hash = 4242;

    for (std::size_t i = 0; i < str.size(); i++)
        hash = 33 * hash + (std::size_t)str[i];
    return hash;
}

static std::string str_touper(const std::string& str)
{
	std::string res(str);
	std::string::iterator it(res.begin());

	while (it != res.end())
	{
		*it = ::toupper(*it);
		it++;
	}
	return (res);
}

Harl::Harl(std::string level)
{
	std::size_t hash_level = get_hash(level);

	switch (hash_level)
	{
		case HASH_DEBUG:
			this->func_map["debug"] = &Harl::debug;
			__attribute__ ((fallthrough));
		case HASH_INFO:
			this->func_map["info"] = &Harl::info;
			__attribute__ ((fallthrough));
		case HASH_WARNING:
			this->func_map["warning"] = &Harl::warning;
			__attribute__ ((fallthrough));
		case HASH_ERROR:
			this->func_map["error"] = &Harl::error;
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
	Harl::log_func func = this->func_map[level];
	if (!func)
		return ;
	std::cout << "[" << str_touper(level) << "]" << std::endl;
	(this->*func)();
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
