#include "FileReader.h"
#include <fstream>

std::vector<std::string> FileReader::readFile(std::string name)
{
	std::vector<std::string> result;
	std::ifstream file(name);
	std::string line;
	while (getline(file,line))
	{
		result.push_back(line);
	}
	file.close();
	return result;
}
