#pragma once
#include "Port.h"

class Or :
	public Port
{
private:
	Or(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;
	bool isInput() override;
	bool isProbe() override;

private:
	static Or _instance;
};
