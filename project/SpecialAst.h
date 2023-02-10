#pragma once
#include "Ast.h"
#include <vector>

struct range {

    char start;

    char end;

    bool notNegated;

    range(char starting, char ending, bool notNeg) : start(starting), end(ending), notNegated(notNeg) {}

};

class SpecialAst :
    public Ast
{
public:

    SpecialAst();

    bool isAnAst() override;

    bool isItSpecial() override;

    std::vector<range> ranges;

    void setRanges(char starting, char ending, bool notNeg);

};

