#include "SpecialMatcher.h"
#include "Range.h"
#include <vector>
#include <string>
#include <iostream>

bool SpecialMatcher::matches(std::string character)
{
    std::cout << character<< std::endl;
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
    std::cout << "I match anything from: " << ranges[0].start << " to: " << ranges[0].end << std::endl;

    return "Special matcher";
}

void SpecialMatcher::setRanges(char starting, char ending, bool notNeg)
{
    ranges.push_back(Range(starting, ending, notNeg));
}

void SpecialMatcher::setRanges(Range range)
{
    ranges.push_back(range);
}
