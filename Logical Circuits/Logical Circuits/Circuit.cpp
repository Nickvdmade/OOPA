#include "Circuit.h"
#include "FileReader.h"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

void Circuit::createCircuit(std::string name)
{
	std::vector<std::string> info = FileReader::readFile(name);
}

void Circuit::calculateResult()
{
}

void Circuit::showResult()
{
}
