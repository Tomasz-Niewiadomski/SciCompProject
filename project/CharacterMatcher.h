#pragma once
#include "Matcher.h"

class CharacterMatcher :
	public Matcher
{
public:
	std::string c;

	CharacterMatcher(std::string givenCharacter);

	bool matches(std::string character) override;

	bool isEpsilon() override;

	std::string printLabel() override;

};

