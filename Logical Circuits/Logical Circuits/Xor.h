#pragma once
#include "Port.h"

class Xor :
	public Port
{
private:
	Xor(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;
	bool isInput() override;
	bool isProbe() override;

private:
	static Xor _instance;
};

