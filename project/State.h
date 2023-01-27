#pragma once
#include <string>
#include <vector>
#include "Matcher.h"

struct Transition
	{
		int toState;
		Matcher& matcher;

		Transition(int givenState, Matcher& givenMatcher) : toState(givenState), matcher(givenMatcher) {}
};

class State
{

	
public:

	std::string stateName;
	std::vector<Transition> stateTransitions;

	State();
	State(std::string name);

	void addTransition(int givenToState, Matcher& givenMatcher);
};

