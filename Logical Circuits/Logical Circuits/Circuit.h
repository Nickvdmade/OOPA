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
	std::map<Node*, std::string> nodes_;
};

