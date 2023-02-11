/** @brief General abstract syntax tree.
 *  @details This class is the base class for all the other Ast classes. 
 *  The virtual identifier functions are subsequentely overridden in the derived classes. 
 *  The Ast class is used to store the regular expression in a tree structure.
*/

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

	/// A vector of AstPointers that are the subexpressions (branches) of the current expression (tree). 
	AstVector subExpr;
	/// A string that is the expression of the current node.  
	std::string expression;
	/// Quantifier of a given expression.  
	char quantifier;
	
	Ast();

	Ast(std::string input);

	/// Pushes back a subexpression to the subExpr vector.
	void addSubExpr(AstPointer point);

	/// Prints the type of the current node and the type of its subexpressions.
	void virtual whoAmI();

	/// The name of the type of the Ast. Either "AstAlternative" or "Ast" or "Atom" or "Special"
	std::string typeName;
	
	/// Returns true if the current node is an Ast.
	bool virtual isAnAst();
	 
	/// Returns true if the current node is an AstAlternative.
	bool virtual isAnAlternative();
	
	///  Returns true if the current node is an Atom.
	bool virtual isAnAtom();

	///  Returns true if the current node is a SpecialAst.
	bool virtual isItSpecial();

	/// Vector of ranges for the specialAst class. We know this isn't really correct, but it is definetely the easiest way.
	std::vector<Range> ranges; 

};

