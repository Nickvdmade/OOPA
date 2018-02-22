#include "And.h"
#include "PortFactory.h"

And And::_instance("AND");

And::And( const std::string& sID)
	: Port( sID )
{
}

int And::calculateOutput()
{
	return 1;
}
