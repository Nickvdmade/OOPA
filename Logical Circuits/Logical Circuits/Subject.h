#pragma once
#include "Observer.h"
#include <vector>

class Subject
{
protected:
	std::vector<Observer*> connections_;
public:
	Subject();
	virtual ~Subject();
	void addConnection(Observer* connection);
	virtual void notify() = 0;
};
