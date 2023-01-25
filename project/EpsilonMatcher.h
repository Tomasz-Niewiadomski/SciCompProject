#pragma once
#include "Matcher.h"
#include "string"

class EpsilonMatcher :
    public Matcher
{
public:

	bool matches(std::string character) override;

	bool isEpsilon() override;

	std::string printLabel() override;

};

