#include "PortFactory.h"
#include <sstream>

void PortFactory::addPort(std::string name, Port port)
{
	if (ports_.find(name) == ports_.end())
	{
		ports_.insert(std::pair<std::string, std::shared_ptr<Port>>(name, std::make_shared<Port>(port)));
	}
}

std::shared_ptr<Port> PortFactory::create(std::string name)
{
	if (ports_.find(name) != ports_.end())
	{
		return ports_[name];
	}
	std::stringstream errorMsg;
	errorMsg << "Port name is not available";
	throw std::exception(errorMsg.str().c_str());
}
