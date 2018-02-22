#pragma once
#include "Port.h"
class Probe :
	public Port
{
private:
	Probe(const std::string&);

public:
	int calculateOutput() override;

private:
	static Probe _instance;
};

