#pragma once
#include <string>
#include <vector>
#include "Matcher.h"

class State
{

	struct Transition
	{
		State& toState;
		Matcher& matcher;

		Transition(State& givenState, Matcher& givenMatcher) : toState(givenState), matcher(givenMatcher) {}
	};
public:

	std::string stateName;
	std::vector<Transition> stateTransitions;

	State(std::string name);

	void addTransition(State& givenToState, Matcher& givenMatcher);
};

