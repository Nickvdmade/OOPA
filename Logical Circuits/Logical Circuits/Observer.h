#pragma once

class Node;

class Observer
{
public:
	Observer();
	virtual ~Observer();
	virtual void update(Node* node) = 0;
};
