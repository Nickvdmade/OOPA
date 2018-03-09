#include "Not.h"
#include <sstream>

Not Not::_instance("NOT");

Not::Not(const std::string& sID)
	: Port(sID)
{
}

int Not::calculateOutput(std::vector<int> input)
{
	if (input.size() != 1)
	{
		std::stringstream errorMsg;
		errorMsg << std::endl << "ERROR: And port has less than 2 inputs";
		throw std::exception(errorMsg.str().c_str());
	}
	return !input[0];
}

bool Not::isInput()
{
	return false;
}

bool Not::isProbe()
{
	return false;
}
