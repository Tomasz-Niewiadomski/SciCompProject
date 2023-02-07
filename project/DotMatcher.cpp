#include "DotMatcher.h"

DotMatcher::DotMatcher()
{
  c = ".";
};

bool DotMatcher::matches()
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
