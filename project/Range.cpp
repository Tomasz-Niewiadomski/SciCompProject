#include "Range.h"

Range::Range(char starting, char ending, bool notNeg): start(starting), end(ending), notNegated(notNeg)
{
}

bool Range::matches(char character)
{

    bool isInside = ((character >= start) and (character <= end));

    return (isInside == notNegated);
}
