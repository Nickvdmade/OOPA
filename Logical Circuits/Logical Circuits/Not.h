#pragma once
#include "Port.h"
class Not :
	public Port
{
private:
	Not(const std::string&);

public:
	int calculateOutput() override;

private:
	static Not _instance;
};

