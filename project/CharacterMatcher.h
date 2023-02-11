/** @brief Simple character transition matcher that consumes the character if it matches.
*/
#pragma once
#include "Matcher.h"

class CharacterMatcher :
	public Matcher
{
public:
	/// Character attribute of this matcher.
	std::string c;

	/// Constructor that sets the character attribute of this matcher.
	CharacterMatcher(std::string givenCharacter);

	/// Overriden to return true if the input string matches the character ( c ) attribute of this matcher.
	bool matches(std::string character) override;

	/// Overriden to return false.
	bool isEpsilon() override;

	/// Overriden to print the character ( c ) attribute of this matcher.
	std::string printLabel() override;

};

