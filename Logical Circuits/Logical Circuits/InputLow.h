#pragma once
#include "Port.h"
class InputLow :
	public Port
{
private:
	InputLow(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;

private:
	static InputLow _instance;
};
