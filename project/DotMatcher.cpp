#include "DotMatcher.h"

DotMatcher::DotMatcher()
{
  c = ".";
};

bool DotMatcher::matches(std::string character)
{
  return true;
};

bool DotMatcher::isEpsilon()
{
  return false;
};

std::string DotMatcher::printLabel()
{
  return "dot";
};
