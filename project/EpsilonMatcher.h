/** @brief Epsilon transition matcher that matches any character and doesn't consume it.
*/
#pragma once
#include "Matcher.h"
#include "string"

class EpsilonMatcher :
    public Matcher
{
public:

	/// Overriden to return true no matter the input string.
	bool matches(std::string character) override;

	/// Overriden to return true.
	bool isEpsilon() override;

	/// Overriden to print "epsilon".
	std::string printLabel() override;

};

