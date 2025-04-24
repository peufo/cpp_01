#pragma once
#include <iostream>

class Harl
{
	typedef void (Harl::*log_func)();
	struct s_level
	{
		std::string name;
		log_func func;
	};
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		s_level levels[4];
	public:
		Harl();
		~Harl();
		void complain(std::string level);
};
