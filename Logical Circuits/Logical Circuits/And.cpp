#include "And.h"
#include "PortFactory.h"

And And::_instance("AND");

And::And( const std::string& sID)
	: Port( sID )
{
}

int And::calculateOutput(std::vector<int> input)
{
	int result = 1;
	for (int i = 0; i < input.size(); i++)
		result = result & input[i];
	return result;
}

bool And::isInput()
{
	return false;
}

bool And::isProbe()
{
	return false;
}
