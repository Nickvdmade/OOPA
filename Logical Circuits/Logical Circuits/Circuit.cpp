#include "Circuit.h"
#include "FileReader.h"
#include <iostream>

Circuit::Circuit()
{
}

Circuit::~Circuit()
{
	for (auto it = nodes_.begin(); it != nodes_.end(); ++it)
	{
		delete it->second;
	}
}

void Circuit::createCircuit(std::string fileName)
{
	std::cout << "Circuit created: " << fileName << std::endl << std::endl;
	std::vector<std::string> info = FileReader::readFile(fileName);
	int index = createNodes(info, 0);
	createConnections(info, index);
}

void Circuit::calculateResult()
{
	std::cout << "Input nodes:" << std::endl;
	for (auto it = nodes_.begin(); it != nodes_.end(); ++it)
	{
		if (it->second->isInput())
		{
			std::cout << "\t";
			it->second->notify();
			it->second->show();
		}
	}
	std::cout << std::endl << "Results calculated" << std::endl << std::endl;
}

void Circuit::showResult()
{
	std::cout << "Output for all probe nodes:" << std::endl;
	for (auto it = nodes_.begin(); it != nodes_.end(); ++it)
	{
		if (it->second->isProbe())
		{
			if (it->second->checkOutput())
			{
				std::cout << "\t";
				it->second->show();
			}
			else
			{
				std::cout << std::endl <<  "ERROR: Probe does not have a correct output." << std::endl << std::endl;
				return;
			}
		}
	}
	std::cout << std::endl;
}

int Circuit::createNodes(std::vector<std::string> info, int index)
{
	for (; index < info.size(); index++)
	{
		std::string line = info[index];
		if (line[0] != '#')
		{
			if (line != "")
			{
				int startPosition = 0;
				int position = line.find(':');
				std::string name = line.substr(startPosition, position - startPosition);
				for (position++; (line[position] == ' ' || line[position] == '\t') && position < line.size(); position++);
				startPosition = position;
				position = line.find(';', position);
				std::string type = line.substr(startPosition, position - startPosition);
				nodes_[name] = new Node(type, name);
			}
			else
			{
				return index++;
			}
		}
	}
}

void Circuit::createConnections(std::vector<std::string> info, int index)
{
	for (; index < info.size(); index++)
	{
		std::string line = info[index];
		if (line[0] != '#' && line != "")
		{
			int startPosition = 0;
			int position = line.find(':');
			std::string name = line.substr(startPosition, position - startPosition);
			Node* node = nodes_[name];
			for (position++; (line[position] == ' ' || line[position] == '\t') && position < line.size(); position++);
			startPosition = position;
			position = line.find(',', startPosition);
			while (position != -1)
			{
				std::string connection = line.substr(startPosition, position - startPosition);
				Node* connectedNode = nodes_[connection];
				node->addConnection(connectedNode);
				connectedNode->addInput(node);
				startPosition = position + 1;
				position = line.find(',', startPosition);
			}
			position = line.find(';', startPosition);
			std::string connection = line.substr(startPosition, position - startPosition);
			Node* connectedNode = nodes_[connection];
			node->addConnection(connectedNode);
			connectedNode->addInput(node);
		}
	}
}
