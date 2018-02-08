#pragma once
#include "Observer.h"
#include "Subject.h"

class Node :
	public Observer, public Subject
{
public:
	Node();
	~Node();
};

