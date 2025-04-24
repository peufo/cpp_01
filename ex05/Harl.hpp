#pragma once
#include <iostream>
#include <map>

class Harl
{
	typedef void (Harl::*log_func)();
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		std::map<const std::string, log_func> func_map;
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};

