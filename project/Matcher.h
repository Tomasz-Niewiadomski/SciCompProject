#include <string>
#include "Range.h"
#include <vector>

#pragma once

class Matcher
{
public:
	virtual bool matches(std::string character);

	virtual bool isEpsilon();

	virtual std::string printLabel();

	std::vector<Range> ranges; // We only use this for the SpecialMatcher class

};

