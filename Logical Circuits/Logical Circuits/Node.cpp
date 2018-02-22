#include "Node.h"
#include "PortFactory.h"
#include <iostream>

Node::Node(const std::string& portType, const std::string& name)
{
	PortFactory& portFactory = PortFactory::instance();
	port_ = portFactory.create(portType);
	portType_ = portType;
	name_ = name;
	output_ = 0;
}

Node::~Node()
{
}

void Node::addInput(const std::shared_ptr<Node> node)
{
	for (auto it = inputReady_.begin(); it != inputReady_.end(); ++it)
	{
		if (it->first->name_ == node->name_)
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
	for (int i = 0; i < connections_.size(); i++)
	{
		connections_[i]->update(std::make_shared<Node>(*this));
	}
}

void Node::update(const std::shared_ptr<Node> node)
{
	for (auto it = inputReady_.begin(); it != inputReady_.end(); ++it)
	{
		if (it->first->name_ == node->name_)
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
	if (portType_ == "INPUT_HIGH" || portType_ == "INPUT_LOW")
		return true;
	return false;
}

bool Node::isProbe() const
{
	if (portType_ == "PROBE")
		return true;
	return false;
}

void Node::show() const
{
	std::cout << name_ << ": " << output_ << std::endl;
}
