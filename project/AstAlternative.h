#pragma once
#include "Ast.h"

typedef std::shared_ptr<Ast> AstPointer;

/// @brief Alternatives (the 'or' operation) in a regular expression.
///  @details The 'or' operation splits the regular expression into two, 
///  that get represented by an Ast object with two subexpressions.
///

class AstAlternative :
    public Ast
{
public:

    AstAlternative(AstPointer reg1, AstPointer reg2);

    /// Overrides to print the type of the current node and the type of its subexpressions.
    void whoAmI() override;

	/// Overrides to return false.
    bool isAnAst() override;
	 
	/// Overrides to return true.
    bool isAnAlternative() override;
	
};