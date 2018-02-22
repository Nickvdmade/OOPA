#pragma once
#include "Port.h"
class Or :
	public Port
{
private:
	Or(const std::string&);

public:
	int calculateOutput() override;

private:
	static Or _instance;
};
