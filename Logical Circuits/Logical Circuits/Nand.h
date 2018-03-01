#pragma once
#include "Port.h"

class Nand :
	public Port
{
private:
	Nand(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;
	bool isInput() override;
	bool isProbe() override;

private:
	static Nand _instance;
};
