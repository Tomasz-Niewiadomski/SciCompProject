#include "State.h"
#include <string>
#include <vector>
#include "Matcher.h"

State::State()
{
	stateName = std::string(0);
}

State::State(std::string name)
{
	stateName = name;
}

void State::addTransition(int givenToState, Matcher& givenMatcher)
{
	Transition transition(givenToState, givenMatcher);
	stateTransitions.push_back(transition);
}
