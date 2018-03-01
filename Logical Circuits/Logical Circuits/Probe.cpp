#include "Probe.h"

Probe Probe::_instance("PROBE");

Probe::Probe(const std::string& sID)
	: Port(sID)
{
}

int Probe::calculateOutput(std::vector<int> input)
{
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
