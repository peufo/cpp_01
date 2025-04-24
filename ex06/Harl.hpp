#pragma once
#include <iostream>
#include <map>
#include <algorithm>
#define HASH_DEBUG 166095534137
#define HASH_INFO 5033387614
#define HASH_WARNING 180902436753032
#define HASH_ERROR 166097204476

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
		Harl(std::string level);
		~Harl();
		void complain(std::string level);
};

