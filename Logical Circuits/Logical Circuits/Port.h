#pragma once

#include <string>

class Port
{
protected:
	Port(const std::string&);
public:
	virtual ~Port();
	virtual int calculateOutput() = 0;
};
