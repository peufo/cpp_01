#include "Harl.hpp"

int main()
{
	Harl harl;

	harl.complain("not_exist");
	harl.complain("debug");
	harl.complain("info");
	harl.complain("warning");
	harl.complain("error");
	return (0);
}