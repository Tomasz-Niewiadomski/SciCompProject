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

void State::moveTransitions(int traslation) {
	for (int i = 0; i < (int)stateTransitions.size(); i++) {
		stateTransitions[i].toState = stateTransitions[i].toState + traslation;
	}
}

void State::myState()
{ 
	if (stateTransitions.size() == 0)
		std::cout << "No transitions " << std::endl;
	else
		for (int i = 0; i < (int)stateTransitions.size(); i++) {
			std::cout << stateTransitions.size() << std::endl;
			std::string stato = stateTransitions[i].matcher.printLabel(); 
			// the current segmentation fault problem is up here ^, I have 0 idea why
			std::cout << "whyyyyy" << std::endl;

			std::cout << "-- " + stato ;
			std::cout << " transition to " << stateTransitions[i].toState << std::endl;
		}
}
