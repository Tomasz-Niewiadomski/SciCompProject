/** @brief Ranges of characters in a regular expression.
 *  @details Storing a range of characters in a regular expression 
 * e.g [a-z] or [^a-z] or [a-z0-9] or [^a-z0-9]. 
 * It is used to store the ranges in a special matcher. 
 * All Ast objects have a vector of ranges, but only the SpecialAst should use it.
*/

#pragma once
class Range
{
public:

    /// The starting character of the range.
    char start;
    /// The ending character of the range.
    char end;
    ///  A boolean value that is false if the range is negated.
    bool notNegated;

    Range(char starting, char ending, bool notNeg); 

    /// A boolean value that is true if the character matches the range.
    bool matches(char character); 
};

