#include "InputHigh.h"

InputHigh InputHigh::_instance("INPUT_HIGH");

InputHigh::InputHigh(const std::string& sID)
	: Port(sID)
{
}

int InputHigh::calculateOutput()
{
	return 1;
}
