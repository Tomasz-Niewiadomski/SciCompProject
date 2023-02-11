#include "Atom.h"
#include "Ast.h"
#include <string>

Atom::Atom(char character) 
{
	expression = character;
	typeName = "Atom";
	quantifier=0;

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

bool Atom::isAnAst()
{
	return false;
}

bool Atom::isAnAlternative()
{
	return false;
}
	 
bool Atom::isAnAtom()
{
	return true;
}

bool Atom::isItSpecial()
{
	return false;
}


