#include "Xor.h"
#include <sstream>

Xor Xor::_instance("XOR");

Xor::Xor(const std::string& sID)
	: Port(sID)
{
}

int Xor::calculateOutput(std::vector<int> input)
{
	if (input.size() < 2)
	{
		std::stringstream errorMsg;
		errorMsg << std::endl << "ERROR: Xor port has less than 2 inputs";
		throw std::exception(errorMsg.str().c_str());
	}
	int result = 0;
	for (int i = 0; i < input.size(); i++)
		result = result ^ input[i];
	return result;
}

bool Xor::isInput()
{
	return false;
}

bool Xor::isProbe()
{
	return false;
}
