/** @brief Class for a range of characters in a regular expression.
 *  @details Storing a range of characters in a regular expression e.g [a-z] or [^a-z] or [a-z0-9] or [^a-z0-9]. It is used to store the ranges in a special matcher. 
 *  @param start The starting character of the range.
 *  @param end The ending character of the range.
 *  @param notNegated A boolean value that is false if the range is negated.
 *  @return A boolean value that is true if the character matches the range.
 *  @file Range.h 
*/

#pragma once
class Range
{
public:

    char start;

    char end;

    bool notNegated;

    Range(char starting, char ending, bool notNeg); 

    bool matches(char character);
};

