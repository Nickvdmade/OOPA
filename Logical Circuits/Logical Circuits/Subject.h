#pragma once
#include "Observer.h"
#include <vector>

class Subject
{
protected:
	std::vector<std::shared_ptr<Observer>> connections_;
public:
	Subject();
	virtual ~Subject();
	void addConnection(const std::shared_ptr<Observer> connection);
	virtual void notify() = 0;
};
