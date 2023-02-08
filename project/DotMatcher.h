#pragma once
#include "Matcher.h"
#include "string"

class DotMatcher : // represents the dot character
   public Matcher
{
public:

  std::string c;

  DotMatcher();

  bool matches(std::string character) override;

  bool isEpsilon() override;

  std::string printLabel() override;
};
