#include "State.h"
#include <string>
#include <vector>
#include "Matcher.h"

State::State(std::string name)
{
	stateName = name;
}

void State::addTransition(State& givenToState, Matcher& givenMatcher)
{
	Transition transition(givenToState, givenMatcher);
	stateTransitions.push_back(transition);
}
