#include "And.h"
#include <sstream>

And And::_instance("AND");

And::And( const std::string& sID)
	: Port( sID )
{
}

int And::calculateOutput(std::vector<int> input)
{
	if (input.size() < 2)
	{
		std::stringstream errorMsg;
		errorMsg << std::endl << "ERROR: And port has less than 2 inputs";
		throw std::exception(errorMsg.str().c_str());
	}
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
