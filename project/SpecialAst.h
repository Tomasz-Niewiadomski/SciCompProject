#pragma once
#include "Ast.h"
#include <vector>
#include "Range.h"


class SpecialAst :
    public Ast
{
public:

    SpecialAst();

    SpecialAst(const SpecialAst& ast);

    bool isAnAst() override;

    bool isItSpecial() override;

    void setRanges(char starting, char ending, bool notNeg);

    void setRanges(Range range);

};

