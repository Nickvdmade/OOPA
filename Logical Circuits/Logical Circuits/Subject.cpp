#include "Subject.h"

Subject::Subject()
{
}

Subject::~Subject()
{
}

void Subject::addConnection(const std::shared_ptr<Observer> connection)
{
	connections_.push_back(connection);
}
