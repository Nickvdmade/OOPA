#pragma once
#include "Port.h"
class Nand :
	public Port
{
private:
	Nand(const std::string&);

public:
	int calculateOutput() override;

private:
	static Nand _instance;
};
