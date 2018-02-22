#include "Probe.h"

Probe Probe::_instance("PROBE");

Probe::Probe(const std::string& sID)
	: Port(sID)
{
}

int Probe::calculateOutput()
{
	return 1;
}
