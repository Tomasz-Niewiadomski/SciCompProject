#include "Ast.h"

typedef std::shared_ptr<Ast> AstPointer;

Ast::Ast()
{
	typeName = "Ast";
}

Ast::Ast(std::string input)
{
	expression = input;
	typeName = "Ast";
}


void Ast::addSubExpr(AstPointer point)
{
	subExpr.push_back(point);
}
void Ast::whoAmI()
{
	std::cout << "I am an " + typeName << std::endl;
	std::cout << "I have "<< subExpr.size() << " subexpressions." << std::endl;
	if (quantifier != 0)
		std::cout << "I have the quantifier: " << quantifier << std::endl;
	else 
		std::cout << "I don't have a quantifier"<< std::endl;

	std::cout << "This is the state of my subexpressions:" << std::endl;
	for (int i = 0; i < (int)subExpr.size(); i++)
	{
		std::cout << "Subexpression number " << i + 1 <<":" << std::endl;
		subExpr[i]->whoAmI();
		std::cout << std::endl;
	}
	std::cout << "This is what I contain." << std::endl;
}
