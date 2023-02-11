/** @brief General matcher in a transition.
*/

#include <string>
#include "Range.h"
#include <vector>

#pragma once

class Matcher
{
public:
	/// Returns true if the input string matches this matcher.
	virtual bool matches(std::string character);

	/// Returns true if the matcher is an epsilon matcher.
	virtual bool isEpsilon();

	/// Prints a label corresponding to the matcher type. Generic: "unidentified matcher".
	virtual std::string printLabel();

	/// Vector of ranges only to be used for the SpecialMatcher class
	std::vector<Range> ranges; 

};

