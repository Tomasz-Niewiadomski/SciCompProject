#include "AstAlternative.h"
#include "Ast.h"

typedef std::shared_ptr<Ast> AstPointer;

AstAlternative::AstAlternative(AstPointer reg1, AstPointer reg2) {
	
	addSubExpr(reg1);

	addSubExpr(reg2);

	typeName = "AstAlternative";

	quantifier = 0;
	
}
void AstAlternative::whoAmI()
{
	std::cout << "I am an " + typeName << std::endl;

	std::cout << "I have " << subExpr.size() << " subexpressions." << std::endl;

	if (quantifier != 0)
		std::cout << "I have the quantifier: " << quantifier << std::endl;
	else
		std::cout << "I don't have a quantifier" << std::endl;

	
	std::cout << "This is the state of my subexpressions:" << std::endl;
	
	std::cout << "First subExpression" << std::endl;
	subExpr[0]->whoAmI();
	std::cout << std::endl;

	std::cout << "Second subExpression" << std::endl;
	subExpr[1]->whoAmI();
	std::cout << std::endl;
	
	std::cout << "This is what I contain." << std::endl;
}
