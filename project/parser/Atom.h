#pragma once
#include "Ast.h"
#include <string>

class Atom :
    public Ast
{
public:
    Atom(char caratt);

    void whoAmI() override;

};

