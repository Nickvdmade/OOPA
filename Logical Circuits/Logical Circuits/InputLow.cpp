#include "InputLow.h"

InputLow InputLow::_instance("INPUT_LOW");

InputLow::InputLow(const std::string& sID)
	: Port(sID)
{
}

int InputLow::calculateOutput(std::vector<int> input)
{
	return 0;
}

bool InputLow::isInput()
{
	return true;
}

bool InputLow::isProbe()
{
	return false;
}
