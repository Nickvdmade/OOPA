#pragma once
#include "Port.h"
class InputLow :
	public Port
{
private:
	InputLow(const std::string&);

public:
	int calculateOutput() override;

private:
	static InputLow _instance;
};
