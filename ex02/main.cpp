#include <string>
#include <iostream>

int main()
{
	std::string str = "HI THIS IS BRAIN";
	std::string *stringPTR = &str;
	std::string &stringREF = str;

	std::cout << "Adrress of string variable:\t" << static_cast<void*>(&str) << std::endl;
	std::cout << "Adrress held by stringPTR:\t" << static_cast<void*>(stringPTR) << std::endl;
	std::cout << "Adrress held by stringREF:\t" << static_cast<void*>(&stringREF) << std::endl;

	std::cout << "Value of string variable:\t" << str << std::endl;
	std::cout << "value pointed to by stringPTR:\t" << *stringPTR << std::endl;
	std::cout << "value pointed to by stringREF:\t" << stringREF << std::endl;
}
