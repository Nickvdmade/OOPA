#pragma once
#include <memory>
#include <string>
#include <map>
//#include "Port.h"

class Port;

class PortFactory
{
private:
	static std::unique_ptr<PortFactory> instance_;
	std::map<std::string, Port*> ports_;

protected:
	PortFactory();

public:
	static PortFactory& instance();
	Port* create(const std::string& name);

private:
	void addPort(const std::string& name, Port& port);

	friend class Port;
};
