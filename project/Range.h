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

