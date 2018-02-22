#include "Nor.h"

Nor Nor::_instance("XOR");

Nor::Nor(const std::string& sID)
	: Port(sID)
{
}

int Nor::calculateOutput()
{
	return 1;
}
