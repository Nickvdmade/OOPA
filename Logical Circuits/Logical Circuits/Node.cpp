#include "Node.h"
#include "PortFactory.h"

Node::Node(const std::string& portType)
{
	PortFactory& portFactory = PortFactory::instance();
	port_ = portFactory.create(portType);
	output_ = 0;
}

Node::~Node()
{
}

void Node::addInput(const std::shared_ptr<Node> node)
{
	inputReady_[node] = false;
}

void Node::calculateOutput()
{
	output_ = port_->calculateOutput();
}

int Node::getOutput() const
{
	return output_;
}

void Node::notify()
{
}

void Node::update(std::shared_ptr<Node> node)
{
}
