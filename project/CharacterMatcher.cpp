#include "CharacterMatcher.h"

CharacterMatcher::CharacterMatcher(std::string givenCharacter) {
	c = givenCharacter;
};

bool CharacterMatcher::matches(std::string character) {
	return (c == character);
};

bool CharacterMatcher::isEpsilon() {
	return false;
};

std::string CharacterMatcher::printLabel() {
	return c + "transition";
};

