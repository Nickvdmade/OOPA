#pragma once
#include <memory>
#include <string>
#include <map>
#include "Port.h"

class PortFactory
{
private:
	static std::map<std::string, std::shared_ptr<Port>> ports_;

public:
	static void addPort(std::string name, Port port);
	static std::shared_ptr<Port> create(std::string name);
};
