#pragma once
#include <string>
#include <map>
#include "Node.h"
#include <memory>

class Circuit
{
public:
	Circuit();
	~Circuit();
	void createCircuit(std::string name);
	void calculateResult();
	void showResult();

private:
	std::map<std::string, std::shared_ptr<Node>> nodes_;

	int createNodes(std::vector<std::string> info, int index);
	void createConnections(std::vector<std::string> info, int index);
};
