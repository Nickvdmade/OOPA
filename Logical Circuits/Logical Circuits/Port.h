#pragma once

#include <string>
#include <vector>

class Port
{
protected:
	Port(const std::string&);
public:
	virtual ~Port();
	virtual int calculateOutput(std::vector<int> input) = 0;
};
