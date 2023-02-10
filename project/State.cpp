#include "State.h"
#include <string>
#include <vector>
#include <iostream>
#include "Matcher.h"
#include "SpecialMatcher.h"

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
	MatchPointer pointer;
	if (givenMatcher.isEpsilon())
	{
		pointer = MatchPointer(new EpsilonMatcher());
	}
	else
	{
		if (givenMatcher.printLabel() == "unidentified matcher")
			std::cout << "unidentified matcher" << std::endl;

		if (givenMatcher.printLabel() == "Special matcher") 
		{

			SpecialMatcher match = givenMatcher;

			pointer = MatchPointer(new SpecialMatcher(givenMatcher));
		}
		else
			pointer = MatchPointer(new CharacterMatcher(givenMatcher.printLabel()));
	}
	Transition transition(givenToState, pointer);
	
	stateTransitions.push_back(transition);
}


void State::moveTransitions(int traslation) {
	for (int i = 0; i < (int)stateTransitions.size(); i++) {
		stateTransitions[i].toState = stateTransitions[i].toState + traslation;
	}
}

void State::myState()
{ 
	std::cout << stateTransitions.size() << std::endl;
	if (stateTransitions.size() == 0)
		std::cout << "No transitions " << std::endl;
	else
		for (int i = 0; i < (int)stateTransitions.size(); i++) {
			std::string stato = stateTransitions[i].matcher->printLabel(); 
			std::cout << "-- " + stato ;
			std::cout << " transition to " << stateTransitions[i].toState << std::endl;
		}
}
