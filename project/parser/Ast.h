#pragma once
#include <string>
#include <vector>
#include <memory>
#include <iostream>


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


};

