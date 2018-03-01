#include "InputHigh.h"

InputHigh InputHigh::_instance("INPUT_HIGH");

InputHigh::InputHigh(const std::string& sID)
	: Port(sID)
{
}

int InputHigh::calculateOutput(std::vector<int> input)
{
	return 1;
}

bool InputHigh::isInput()
{
	return true;
}

bool InputHigh::isProbe()
{
	return false;
}
