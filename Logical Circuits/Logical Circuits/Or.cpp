#include "Or.h"

Or Or::_instance("OR");

Or::Or(const std::string& sID)
	: Port(sID)
{
}

int Or::calculateOutput(std::vector<int> input)
{
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
