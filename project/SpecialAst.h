/** @brief Special expressions such as ranges.
*/
#pragma once
#include "Ast.h"
#include <vector>
#include "Range.h"


class SpecialAst :
    public Ast
{
public:

    SpecialAst();

    /// Used for creating a copy of the SpecialAst.
    SpecialAst(const SpecialAst& ast);

    /// Overrides to return false.
    bool isAnAst() override;

    /// Overrides to return true.
    bool isItSpecial() override;

    /// Creates a new range and pushes it into the vector of ranges. Takes the starting and ending characters and a boolean value that is false if the range is negated.
    void setRanges(char starting, char ending, bool notNeg);

    /// Pushes existing range into the vector of ranges.
    void setRanges(Range range);

};

