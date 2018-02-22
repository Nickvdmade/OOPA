#include "Port.h"
#include "PortFactory.h"

Port::Port(const std::string& sID)
{
	PortFactory::instance().addPort(sID, *this);
}

Port::~Port()
{
}
