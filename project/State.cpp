#include "State.h"
#include <string>
#include <vector>
#include <iostream>
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

void State::myState()
{
	for (int i = 0; i < (int)stateTransitions.size(); i++) {
		std::cout << "-- ";
		stateTransitions[i].matcher.printLabel();
		std::cout << " to " << stateTransitions[i].toState << std::endl;
	}
}
