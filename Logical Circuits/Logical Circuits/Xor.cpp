#include "Xor.h"

Xor Xor::_instance("XOR");

Xor::Xor(const std::string& sID)
	: Port(sID)
{
}

int Xor::calculateOutput(std::vector<int> input)
{
	int result = 0;
	for (int i = 0; i < input.size(); i++)
		result = result ^ input[i];
	return result;
}

bool Xor::isInput()
{
	return false;
}

bool Xor::isProbe()
{
	return false;
}
