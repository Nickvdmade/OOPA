#include <iostream>
#include "Circuit.h"
#include "PortFactory.h"
#include "Input.h"
#include "Probe.h"
#include "And.h"
#include "Nand.h"
#include "Or.h"
#include "Nor.h"
#include "Xor.h"
#include "Not.h"

void setup()
{
	//PortFactory portFactory = PortFactory::instance();
	Port highInput = Input(1);
	PortFactory::addPort("INPUT_HIGH", highInput);
	Port lowInput = Input(0);
	PortFactory::addPort("INPUT_LOW", lowInput);
	Port probe = Probe();
	PortFactory::addPort("PROBE", probe);
	Port and = And();
	PortFactory::addPort("AND", and);
	Port nand = Nand();
	PortFactory::addPort("NAND", nand);
	Port or = Or();
	PortFactory::addPort("OR", or);
	Port nor = Nor();
	PortFactory::addPort("NOR", nor);
	Port xor = Xor();
	PortFactory::addPort("XOR", xor);
	Port not = Not();
	PortFactory::addPort("NOT", not);
}

void main()
{
	setup();
	Circuit circuit;
	circuit.createCircuit("circuit1.txt");
	circuit.calculateResult();
	circuit.showResult();

	std::cout << "Press a key" << std::endl;
	getchar();
}
