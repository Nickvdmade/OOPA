#pragma once
#include <memory>
#include <string>
#include <map>
#include "Port.h"

class PortFactory
{
private:
	static std::unique_ptr<PortFactory> instance_;
	std::map<std::string, std::shared_ptr<Port>> ports_;

protected:
	PortFactory();

public:
	static PortFactory& instance();
	void addPort(std::string name, Port port);
	std::shared_ptr<Port> create(std::string name);
};
