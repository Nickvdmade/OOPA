#include "Circuit.h"
#include "FileReader.h"
#include <iostream>
#include <sstream>

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
	std::cout << "Creating circuit: " << fileName << std::endl;
	std::vector<std::string> info = FileReader::readFile(fileName);
	int index = createNodes(info, 0);
	createConnections(info, index);
	std::cout << "Circuit created" << std::endl << std::endl;
}

void Circuit::calculateResult()
{
	std::cout << "Calculating nodes:" << std::endl;
	for (auto it = nodes_.begin(); it != nodes_.end(); ++it)
	{
		if (it->second->isInput())
		{
			std::cout << "\tInput ";
			it->second->notify();
			//it->second->show();
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
				it->second->show();
			}
			else
			{
				std::stringstream errorMsg;
				errorMsg << std::endl << "ERROR: Probe does not have a correct output.";
				throw std::exception(errorMsg.str().c_str()); 
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
