#pragma once
#include "Port.h"
class InputHigh :
	public Port
{
private:
	InputHigh(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;

private:
	static InputHigh _instance;
};

