#include "SpecialAst.h"
#include "string"

bool SpecialAst::isAnAst()
{
    return false;
}

bool SpecialAst::isItSpecial()
{
    return true;
}

void SpecialAst::setRanges(char starting, char ending, bool notNeg)
{

    ranges.push_back(range(starting, ending, notNeg));

}

SpecialAst::SpecialAst() {
    typeName = "special";
}