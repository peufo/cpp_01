#ifndef HARL_HPP
#define HARL_HPP

#include <iostream>

class Harl
{
	typedef void (Harl::*logFunc)();
	struct s_level
	{
		std::string name;
		logFunc func;
	};
	private:
		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
		s_level levels[4];
	public:
		Harl(std::string level);
		~Harl();
		void complain(std::string level);
};

#endif
