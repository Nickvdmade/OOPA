#pragma once
#include "Port.h"
class And :
	public Port
{
private:
	And(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;

private:
	static And _instance;
};

