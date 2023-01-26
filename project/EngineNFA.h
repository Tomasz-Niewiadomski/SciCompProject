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

	void addState(State state);

	void declareStates(std::vector<State> declaredStates);

	void addTransition(int fromState, int toState, Matcher &matcher);

	void compute(std::string);
	

};

