#include "Not.h"

Not Not::_instance("NOT");

Not::Not(const std::string& sID)
	: Port(sID)
{
}

int Not::calculateOutput(std::vector<int> input)
{
	return (input[0] + 1) % 2;
}
