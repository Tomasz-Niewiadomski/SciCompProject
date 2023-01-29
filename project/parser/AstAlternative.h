#pragma once
#include "Ast.h"

typedef std::shared_ptr<Ast> AstPointer;

class AstAlternative :
    public Ast
{
public:

    AstAlternative(AstPointer reg1, AstPointer reg2);

    void whoAmI() override;


};

