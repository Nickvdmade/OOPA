#pragma once
#include "Observer.h"
#include "Subject.h"
#include <map>
#include "Port.h"

class Node :
	public Observer, public Subject
{
private:
	std::map<Node*, bool> inputReady_;
	int output_;
	Port* port_;
	std::string name_;

public:
	Node(const std::string& portType, const std::string& name);
	~Node();
	void addInput(Node* node);
	void calculateOutput();
	int getOutput() const;
	void notify() override;
	void update(Node* node) override;
	bool isInput() const;
	bool isProbe() const;
	bool checkOutput() const;
	void show() const;
};
