#include <iostream>
#include "Circuit.h"

void main()
{
	Circuit circuit;
	circuit.createCircuit("circuit1.txt");
	circuit.calculateResult();
	circuit.showResult();

	std::cout << "Press a key" << std::endl;
	getchar();
}
