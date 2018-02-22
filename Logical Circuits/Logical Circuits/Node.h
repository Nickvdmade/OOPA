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
	std::string portType_;
	std::string name_;

public:
	Node(const std::string& portType, const std::string& name);
	~Node();
	void addInput(const std::shared_ptr<Node> node);
	void calculateOutput();
	int getOutput() const;
	void notify() override;
	void update(const std::shared_ptr<Node> node) override;
	bool isInput() const;
	bool isProbe() const;
	void show() const;
};
