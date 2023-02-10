#pragma once
#include "Matcher.h"
#include <vector>
#include "Range.h"


class SpecialMatcher :
    public Matcher
{
public:

    SpecialMatcher();

    SpecialMatcher(Matcher& matcher);

	bool matches(std::string character) override;

	std::string printLabel();

    void setRanges(char starting, char ending, bool notNeg);

    void setRanges(Range range);
};

