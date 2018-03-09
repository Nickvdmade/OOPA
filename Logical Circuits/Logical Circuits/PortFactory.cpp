#include "PortFactory.h"
#include <sstream>

std::unique_ptr<PortFactory> PortFactory::instance_;

PortFactory::PortFactory()
{
}

PortFactory& PortFactory::instance()
{
	if (instance_ == nullptr)
	{
		PortFactory factory;
		instance_ = std::make_unique<PortFactory>(factory);
	}
	return *instance_;
}

void PortFactory::addPort(const std::string& name, Port& port)
{
	if (ports_.find(name) == ports_.end())
	{
		ports_[name] = &port;
	}
}

Port* PortFactory::create(const std::string& name)
{
	if (ports_.find(name) != ports_.end())
	{
		return ports_[name];
	}
	std::stringstream errorMsg;
	errorMsg << "ERROR: Port name is not available";
	throw std::exception(errorMsg.str().c_str());
}
