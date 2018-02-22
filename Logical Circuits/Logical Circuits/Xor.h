#pragma once
#include "Port.h"
class Xor :
	public Port
{
private:
	Xor(const std::string&);

public:
	int calculateOutput() override;

private:
	static Xor _instance;
};

