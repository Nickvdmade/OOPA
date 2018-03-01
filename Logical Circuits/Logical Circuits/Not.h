#pragma once
#include "Port.h"

class Not :
	public Port
{
private:
	Not(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;
	bool isInput() override;
	bool isProbe() override;

private:
	static Not _instance;
};

