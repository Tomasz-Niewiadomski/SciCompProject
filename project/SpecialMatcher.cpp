#include "SpecialMatcher.h"
#include "Range.h"
#include <vector>
#include <string>
#include <iostream>

SpecialMatcher::SpecialMatcher()
{
}

SpecialMatcher::SpecialMatcher(Matcher& matcher)
{
    if (matcher.printLabel() != "Special matcher")
        std::cout << "You are calling SpecialMatcher(Matcher&) on a non Special Matcher! line 14, SpecialMatcher.cpp" << std::endl;

    for (auto& element : matcher.ranges) {
        setRanges(element);
    }
}

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
    ranges.push_back(Range(starting, ending, notNeg));
}

void SpecialMatcher::setRanges(Range range)
{
    ranges.push_back(range);
}
