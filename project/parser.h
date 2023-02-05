#pragma once
#include "Ast.h"
#include "AstAlternative.h"
#include "Atom.h"
#include <string>


typedef std::shared_ptr<Ast> AstPointer;

int findOr(std::string& input);

int findClosure(std::string& input, int start);

bool isAQuantifier(char c);

AstPointer parser(std::string input);