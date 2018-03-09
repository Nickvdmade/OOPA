#include "Nand.h"
#include <sstream>

Nand Nand::_instance("NAND");

Nand::Nand(const std::string& sID)
	: Port(sID)
{
}

int Nand::calculateOutput(std::vector<int> input)
{
	if (input.size() < 2)
	{
		std::stringstream errorMsg;
		errorMsg << std::endl << "ERROR: Nand port has less than 2 inputs";
		throw std::exception(errorMsg.str().c_str());
	}
	int result = 1;
	for (int i = 0; i < input.size(); i++)
		result = result & input[i];
	return !result;
}

bool Nand::isInput()
{
	return false;
}

bool Nand::isProbe()
{
	return false;
}
