/// @brief Parses a regular expression into an AST.
/// @details The parser is a recursive descent parser.

#pragma once
#include "Ast.h"
#include "AstAlternative.h"
#include "Atom.h"
#include "SpecialAst.h"
#include <string>


typedef std::shared_ptr<Ast> AstPointer;

int findOr(std::string& input);

int findClosure(std::string& input, int start);

int findSquaredClosure(std::string& input, int start);

bool isAQuantifier(char c);


bool isReserved(char c);

std::string correspondingString(char c);

SpecialAst specialAstAssembly(std::string& input);

AstPointer parser(std::string input);
