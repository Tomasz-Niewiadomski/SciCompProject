#pragma once

#include<string>
#include<map>
#include "Matcher.h"
#include "State.h"

class EngineNFA
{
	public:

	std::vector<State> states;
	int startState;
	int endState;

	EngineNFA();
	
	void addState(State state); // adds a state to the NFA (not to be used explicitely)

	void declareStates(std::vector<State> declaredStates); 

	void addTransition(int fromState, int toState, Matcher &matcher);

	bool compute(std::string string); // true if regex found in the input string (anchored at the beginning)
	
	void concatenateNFA(EngineNFA nfaToConcat);  // represents Ast
	
	EngineNFA(EngineNFA nfa1, EngineNFA nfa2); // represents AstAlternative

	void myState(); // prints the states of the NFA

	bool search(std::string string); // true if regex found anywhere in the input string

	std::vector<int> findOccurances(std::string string); // returns a vector of indices where the regex is found in the input string 

	void printOccurances(std::string string); // prints the indices where the regex is found in the input string

	
};

