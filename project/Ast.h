#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>
#include "Range.h"


class Ast
{
public:

	typedef std::shared_ptr<Ast> AstPointer;
	typedef std::vector<AstPointer> AstVector;


	AstVector subExpr;

	std::string expression;

	char quantifier;

	Ast();

	Ast(std::string input);

	void addSubExpr(AstPointer point);

	void virtual whoAmI();

	std::string typeName;
	
	bool virtual isAnAst();
	 
	bool virtual isAnAlternative();
	
	bool virtual isAnAtom();

	bool virtual isItSpecial();

	std::vector<Range> ranges; // for the specialAst class. We know this isn't really correct, but it is definetely the easiest way.

};

