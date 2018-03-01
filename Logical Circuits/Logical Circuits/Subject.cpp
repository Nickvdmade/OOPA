#include "Subject.h"

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::addConnection(Observer* connection)
{
	connections_.push_back(connection);
}
