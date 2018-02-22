#include "Nand.h"

Nand Nand::_instance("NAND");

Nand::Nand(const std::string& sID)
	: Port(sID)
{
}

int Nand::calculateOutput(std::vector<int> input)
{
	int result = 1;
	for (int i = 0; i < input.size(); i++)
		result = result & input[i];
	return (result + 1) % 2;
}
