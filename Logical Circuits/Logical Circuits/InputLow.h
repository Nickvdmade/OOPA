#pragma once
#include "Port.h"

class InputLow :
	public Port
{
private:
	InputLow(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;
	bool isInput() override;
	bool isProbe() override;

private:
	static InputLow _instance;
};
