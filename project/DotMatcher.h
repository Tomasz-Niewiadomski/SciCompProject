#pragma once
#include "Matcher.h"
#include "string"

class DotMatcher :
   public Matcher
{
public:

  std::string c;

  bool matches(std::string character) override;

  bool isEpsilon() override;

  std::string printLabel() override;
};
