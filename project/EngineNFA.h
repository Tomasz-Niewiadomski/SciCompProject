#pragma once

#include<string>
#include<map>
#include "Matcher.h"
#include "State.h"

class EngineNFA
{
	public:

	std::map<std::string, State> states;
	State startState;
	State endState;

	void setStartState(State givenState);
	

	void setEndState(std::string name);
	

	void addTransition(State fromState, State toState, Matcher matcher);
	

	void compute(std::string);
	

};

