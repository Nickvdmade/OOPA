#include "Nor.h"

Nor Nor::_instance("XOR");

Nor::Nor(const std::string& sID)
	: Port(sID)
{
}

int Nor::calculateOutput(std::vector<int> input)
{
	int result = 0;
	for (int i = 0; i < input.size(); i++)
		result = result | input[i];
	return (result + 1) % 2;
}
