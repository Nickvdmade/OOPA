#include "Nand.h"

Nand Nand::_instance("NAND");

Nand::Nand(const std::string& sID)
	: Port(sID)
{
}

int Nand::calculateOutput()
{
	return 1;
}
