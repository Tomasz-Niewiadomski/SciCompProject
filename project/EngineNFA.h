/// @brief The highest level representation of the NFA
///  @details 
///
#pragma once

#include<string>
#include<map>
#include "Matcher.h"
#include "State.h"

class EngineNFA
{
	public:

	/// Vector containing all states of 'State' type present in the instance of an NFA.
	std::vector<State> states;
	/// Starting state of the NFA. By default is 0.
	int startState;
	/// Ending state of the NFA.
	int endState;

	EngineNFA();
	
	/// adds a state to the NFA (not to be used explicitely)
	void addState(State state); 

	/// Initialises the NFA with the given states.
	void declareStates(std::vector<State> declaredStates); 

	/// @brief  Adds a from one state to another with a given matcher.
	/// @param fromState Int representing the index of a state from which the transition is made.
	/// @param toState  Int representing the index of a state to which the transition is made.
	/// @param matcher (Character/Epsilon/Special-) Matcher object corresponding to the transition.
	void addTransition(int fromState, int toState, Matcher &matcher);

	/// @brief Checks if the input string is accepted by this NFA.
	/// @details Returns true if regex found in the input string. The search is anchored at the beginning of the string.
	/// @param string String to be checked.
	bool compute(std::string string); 
	
	/// Given an NFA, concatenates it to the current NFA. 
	void concatenateNFA(EngineNFA nfaToConcat);
	
	/// Constructs an engine in the AlternativeAst case.
	EngineNFA(EngineNFA nfa1, EngineNFA nfa2); 

	/// Prints state information for debugging purposes.
	void myState(); 

	/// Iterates through the input string removing a character at a time and checking if the regex is found in the remaining string with the compute() function.
	bool search(std::string string);

	/// Returns a vector of indices where the regex is found in the entirety of the input string.
	std::vector<int> findOccurances(std::string string); // returns a vector of indices where the regex is found in the input string 

	/// Prints the indices where the regex is found in the entirety of the input string.
	void printOccurances(std::string string); // prints the indices where the regex is found in the input string

	
};

