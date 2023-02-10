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

    ranges.push_back(Range(starting, ending, notNeg));

}

void SpecialAst::setRanges(Range range) {
    ranges.push_back(range);
}

SpecialAst::SpecialAst() {
    typeName = "special";
}

SpecialAst::SpecialAst(const SpecialAst& ast)
{
    typeName = "special";

    for (auto& element : ast.ranges) {
        setRanges(element);
    }
}
