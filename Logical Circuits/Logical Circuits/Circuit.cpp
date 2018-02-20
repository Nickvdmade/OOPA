#include "Circuit.h"
#include "FileReader.h"

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
}

void Circuit::createCircuit(std::string fileName)
{
	std::vector<std::string> info = FileReader::readFile(fileName);
	for (int i = 0; i < info.size(); i++)
	{
		std::string line = info[i];
		if (line[0] != '#')
		{
			int startposition = 0;
			int position = line.find(':');
			std::string name = line.substr(startposition, position - 1 - startposition);
			for (; (line[position] == ' ' || line[position] == '\t') && position < line.size(); position++);
			startposition = position;
			position = line.find(';', position);
			std::string type = line.substr(startposition, position - 1 - startposition);

		}
	}
}

void Circuit::calculateResult()
{
}

void Circuit::showResult()
{
}
