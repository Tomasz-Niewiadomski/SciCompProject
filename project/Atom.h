/** @brief Atomic characters (non-splittable expressions) in a regular expression.
 *  @details 
 *  
*/
#pragma once
#include "Ast.h"
#include <string>

class Atom :
    public Ast
{
public:
    /// Constructor that sets the atomic character and the type of the node.
    Atom(char caratt);
    
    /// Overrides to print its atomic character and its quantifier (if any).
    void whoAmI() override;
    
    /// Overrides to return false.
    bool isAnAst() override;
	
    /// Overrides to return true.
	bool isAnAtom() override;

};

