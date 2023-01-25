#include <string>

#pragma once

class Matcher
{
public:
	virtual bool matches(std::string character);

	virtual bool isEpsilon();

	virtual std::string printLabel();

};

