#pragma once
#include "Matcher.h"
#include <vector>


struct matcherRange {
    char start;

    char end;

    bool notNegated;

    matcherRange(char starting, char ending, bool notNeg) : start(starting), end(ending), notNegated(notNeg) {}

    bool matches(char character) {

        bool isInside = ((character >= start) and (character <= end));

        return (isInside == notNegated);
    }

};

class SpecialMatcher :
    public Matcher
{
public:

    std::vector<matcherRange> ranges;

	bool matches(std::string character);

	std::string printLabel();

    void setRanges(char starting, char ending, bool notNeg);
};

