#include "FileReader.h"
#include <fstream>
#include <sstream>

std::vector<std::string> FileReader::readFile(std::string name)
{
	std::vector<std::string> result;
	std::ifstream file(name);
	std::string line;
	if (!file.is_open())
	{
		std::stringstream errorMsg;
		errorMsg << "ERROR: File does not exist";
		throw std::exception(errorMsg.str().c_str());
	}
	while (getline(file,line))
	{
		result.push_back(line);
	}
	file.close();
	return result;
}
