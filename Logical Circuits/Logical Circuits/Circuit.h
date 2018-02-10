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
	std::map<std::shared_ptr<Node>, std::string> nodes_;
};

