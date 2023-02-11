#pragma once
#include "Ast.h"
#include <string>

class Atom :
    public Ast
{
public:
    Atom(char character);

    void whoAmI() override;
    
	bool isAnAst() override;
	
	bool isAnAlternative() override;
    
    bool isAnAtom() override;

    bool isItSpecial() override;

};

