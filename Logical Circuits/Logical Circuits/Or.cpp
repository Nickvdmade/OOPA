#include "Or.h"

Or Or::_instance("XOR");

Or::Or(const std::string& sID)
	: Port(sID)
{
}

int Or::calculateOutput()
{
	return 1;
}
