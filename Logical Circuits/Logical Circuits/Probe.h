#pragma once
#include "Port.h"
class Probe :
	public Port
{
private:
	Probe(const std::string&);

public:
	int calculateOutput(std::vector<int> input) override;

private:
	static Probe _instance;
};

