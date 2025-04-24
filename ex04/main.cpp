#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>

static void terminate(std::string error)
{
	if (error.data())
	{
		std::cerr << error << std::endl;
		std::exit(1);
		return ;
	}
	std::exit(0);
}

static std::string readFile(std::string filename)
{
	std::ifstream input(filename.c_str());
	std::string line("");
	std::string	content("");

	if (!input)
		terminate("Input file access error");
	while (std::getline(input, line))
		content += line + "\n";
	input.close();
	return (content);
}

static void sed(std::string filename, std::string search, std::string replace)
{
	std::string content = readFile(filename);
	std::string filename_out(filename + ".replace");
	std::ofstream output(filename_out.c_str());
	size_t next_found = content.find(search);
	size_t cursor = 0;

	if (!search.length())
		terminate("Search pattern can't be empty");
	if (!output)
		terminate("File access error");
	while (next_found != std::string::npos)
	{
		output << content.substr(cursor, next_found - cursor);
		output << replace;
		cursor = next_found + search.length();
		next_found = content.find(search, cursor);
	}
	output << content.substr(cursor);
	output.close();
}

int main(int ac, char **av)
{
	if (ac != 4)
		terminate("Usage: ./prog <filename> <search> <replace>");
	sed(av[1], av[2], av[3]);
	return (0);
}
