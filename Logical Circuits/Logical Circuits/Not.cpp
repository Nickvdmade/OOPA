#include "Not.h"

Not Not::_instance("XOR");

Not::Not(const std::string& sID)
	: Port(sID)
{
}

int Not::calculateOutput()
{
	return 1;
}
