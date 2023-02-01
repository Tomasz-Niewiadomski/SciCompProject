#include "EpsilonMatcher.h"
#include <string>

bool EpsilonMatcher::matches(std::string character)
{
	return true;
};

bool EpsilonMatcher::isEpsilon()
{
	return true;
};

std::string EpsilonMatcher::printLabel()
{
	return "epsilon transition";
};
