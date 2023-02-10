#include "SpecialMatcher.h"

bool SpecialMatcher::matches(std::string character)
{
    char charact = character[0];

    int num = static_cast<int>(ranges.size());

    for (int i = 0; i < num; i++) {
        if (ranges[i].matches(charact))
            return true;
    }
    return false;
}

std::string SpecialMatcher::printLabel()
{
    return "Special matcher";
}

void SpecialMatcher::setRanges(char starting, char ending, bool notNeg)
{
    ranges.push_back(matcherRange(starting, ending, notNeg));
}
