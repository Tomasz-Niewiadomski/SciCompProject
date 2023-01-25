#include "Matcher.h"
#include <string>

bool Matcher::matches(std::string character) {

	return false;

};

bool Matcher::isEpsilon() {
	return bool(0);
};

std::string Matcher::printLabel()
{
	return "unidentified matcher";
};
