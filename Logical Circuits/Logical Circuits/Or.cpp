#include "Or.h"
#include <sstream>

Or Or::_instance("OR");

Or::Or(const std::string& sID)
	: Port(sID)
{
}

int Or::calculateOutput(std::vector<int> input)
{
	if (input.size() < 2)
	{
		std::stringstream errorMsg;
		errorMsg << std::endl << "ERROR: Or port has less than 2 inputs";
		throw std::exception(errorMsg.str().c_str());
	}
	int result = 0;
	for (int i = 0; i < input.size(); i++)
		result = result | input[i];
	return result;
}

bool Or::isInput()
{
	return false;
}

bool Or::isProbe()
{
	return false;
}
