#include "Atom.h"
#include "Ast.h"
#include <string>

Atom::Atom(char caratt) 
{
	expression = caratt;
	typeName = "Atom";

}
void Atom::whoAmI()
{
	std::cout << "I am an " + typeName << std::endl;
	std::cout << "I contain " << expression << std::endl;
	if (quantifier != 0)
		std::cout << "I have the quantifier: " << quantifier << std::endl;
	else
		std::cout << "I don't have a quantifier" << std::endl;

}
;

