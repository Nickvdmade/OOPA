#pragma once
#include "Port.h"

class Nor :
	public Port
{
private:
	Nor(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;
	bool isInput() override;
	bool isProbe() override;

private:
	static Nor _instance;
};

