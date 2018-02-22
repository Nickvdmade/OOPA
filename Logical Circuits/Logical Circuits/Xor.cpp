#include "Xor.h"

Xor Xor::_instance("XOR");

Xor::Xor(const std::string& sID)
	: Port(sID)
{
}

int Xor::calculateOutput()
{
	return 1;
}
