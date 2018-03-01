#pragma once
#include <string>
#include <map>
#include "Node.h"

class Circuit
{
public:
	Circuit();
	~Circuit();
	void createCircuit(std::string name);
	void calculateResult();
	void showResult();

private:
	std::map<std::string, Node*> nodes_;

	int createNodes(std::vector<std::string> info, int index);
	void createConnections(std::vector<std::string> info, int index);
};
