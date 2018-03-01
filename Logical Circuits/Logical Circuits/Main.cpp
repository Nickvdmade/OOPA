#include <iostream>
#include "Circuit.h"

#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  

void main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	Circuit circuit;
	circuit.createCircuit("circuit4.txt");
	circuit.calculateResult();
	circuit.showResult();

	std::cout << "Press a key to exit" << std::endl;
	getchar();
}
