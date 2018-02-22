#pragma once
#include <memory>

class Node;

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(std::shared_ptr<Node> node) = 0;
};
