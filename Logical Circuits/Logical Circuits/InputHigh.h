#pragma once
#include "Port.h"
class InputHigh :
	public Port
{
private:
	InputHigh(const std::string&);

public:
	int calculateOutput() override;

private:
	static InputHigh _instance;
};

