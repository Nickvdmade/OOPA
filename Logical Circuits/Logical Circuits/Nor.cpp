#include "Nor.h"
#include <sstream>

Nor Nor::_instance("XOR");

Nor::Nor(const std::string& sID)
	: Port(sID)
{
}

int Nor::calculateOutput(std::vector<int> input)
{
	if (input.size() < 2)
	{
		std::stringstream errorMsg;
		errorMsg << std::endl << "ERROR: Nor port has less than 2 inputs";
		throw std::exception(errorMsg.str().c_str());
	}
	int result = 0;
	for (int i = 0; i < input.size(); i++)
		result = result | input[i];
	return !result;
}

bool Nor::isInput()
{
	return false;
}

bool Nor::isProbe()
{
	return false;
}
