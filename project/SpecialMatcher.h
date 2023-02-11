/** @brief Special transitions matcher for ranges and special characters.
*/
#pragma once
#include "Matcher.h"
#include <vector>
#include "Range.h"


class SpecialMatcher :
    public Matcher
{
public:

    SpecialMatcher();

    /// Used for creating a copy of the SpecialMatcher.
    SpecialMatcher(Matcher& matcher);

	/// Overriden to return true if the input string lies in the range of the ranges attribute of this matcher.
    bool matches(std::string character) override;

	/// Overriden to print "Special matcher".
    std::string printLabel();

    /// Creates a new range and pushes it into the vector of ranges. Takes the starting and ending characters and a boolean value that is false if the range is negated.
    void setRanges(char starting, char ending, bool notNeg);

    /// Pushes existing range into the vector of ranges.
    void setRanges(Range range);
};

