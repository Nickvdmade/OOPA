#pragma once
#include "Observer.h"
#include "Subject.h"
#include <map>
#include <memory>
#include "Port.h"

class Node :
	public Observer, public Subject
{
private:
	std::map<std::shared_ptr<Node>, bool> inputReady_;
	int output_;
	Port* port_;

public:
	Node(const std::string& portType);
	~Node();
	void addInput(const std::shared_ptr<Node> node);
	void calculateOutput();
	int getOutput() const;
	void notify();
	void update(std::shared_ptr<Node> node);
};
