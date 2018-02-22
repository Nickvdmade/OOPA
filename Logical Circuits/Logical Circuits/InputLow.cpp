#include "InputLow.h"

InputLow InputLow::_instance("INPUT_LOW");

InputLow::InputLow(const std::string& sID)
	: Port(sID)
{
}

int InputLow::calculateOutput()
{
	return 1;
}
