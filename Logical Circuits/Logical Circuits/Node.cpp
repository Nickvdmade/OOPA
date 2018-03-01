#include "Node.h"
#include "PortFactory.h"
#include <iostream>

Node::Node(const std::string& portType, const std::string& name)
{
	PortFactory& portFactory = PortFactory::instance();
	port_ = portFactory.create(portType);
	name_ = name;
	output_ = -1;
}

Node::~Node()
{
}

void Node::addInput(Node* node)
{
	for (auto it = inputReady_.begin(); it != inputReady_.end(); ++it)
	{
		if (it->first == node)
			return;
	}
	inputReady_[node] = false;
}

void Node::calculateOutput()
{
	std::vector<int> inputs;
	for (auto it = inputReady_.begin(); it != inputReady_.end(); ++it)
	{
		inputs.push_back(it->first->getOutput());
	}
	output_ = port_->calculateOutput(inputs);
}

int Node::getOutput() const
{
	return output_;
}

void Node::notify()
{
	calculateOutput();
	//std::cout << name_ << ":\t" << output_ << std::endl;
	for (int i = 0; i < connections_.size(); i++)
	{
		connections_[i]->update(this);
	}
}

void Node::update(Node* node)
{
	for (auto it = inputReady_.begin(); it != inputReady_.end(); ++it)
	{
		if (it->first == node)
			it->second = true;
	}
	for (auto it = inputReady_.begin(); it != inputReady_.end(); ++it)
	{
		if (!it->second)
			return;
	}
	notify();
}

bool Node::isInput() const
{
	if (port_->isInput())
		return true;
	return false;
}

bool Node::isProbe() const
{
	if (port_->isProbe())
		return true;
	return false;
}

bool Node::checkOutput() const
{
	if (output_ < 0)
		return false;
	return true;
}

void Node::show() const
{
	std::cout << name_ << ": " << output_ << std::endl;
}
