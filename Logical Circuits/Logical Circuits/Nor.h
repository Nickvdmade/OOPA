#pragma once
#include "Port.h"
class Nor :
	public Port
{
private:
	Nor(const std::string&);

public:
	int calculateOutput() override;

private:
	static Nor _instance;
};

