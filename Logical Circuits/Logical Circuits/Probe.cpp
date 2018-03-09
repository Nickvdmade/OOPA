#include "Probe.h"
#include <sstream>

Probe Probe::_instance("PROBE");

Probe::Probe(const std::string& sID)
	: Port(sID)
{
}

int Probe::calculateOutput(std::vector<int> input)
{
	if (input.size() != 1)
	{
		std::stringstream errorMsg;
		errorMsg << std::endl << "ERROR: Probe port has less than 2 inputs";
		throw std::exception(errorMsg.str().c_str());
	}
	return input[0];
}

bool Probe::isInput()
{
	return false;
}

bool Probe::isProbe()
{
	return true;
}
