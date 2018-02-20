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
	PortFactory& portFactory = PortFactory::instance();
	Port highInput = Input(1);
	portFactory.addPort("INPUT_HIGH", highInput);
	Port lowInput = Input(0);
	portFactory.addPort("INPUT_LOW", lowInput);
	Port probe = Probe();
	portFactory.addPort("PROBE", probe);
	Port and = And();
	portFactory.addPort("AND", and);
	Port nand = Nand();
	portFactory.addPort("NAND", nand);
	Port or = Or();
	portFactory.addPort("OR", or);
	Port nor = Nor();
	portFactory.addPort("NOR", nor);
	Port xor = Xor();
	portFactory.addPort("XOR", xor);
	Port not = Not();
	portFactory.addPort("NOT", not);
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
