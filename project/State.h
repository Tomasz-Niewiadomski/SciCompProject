#pragma once
#include <string>
#include <vector>
#include "Matcher.h"
#include "CharacterMatcher.h"
#include "EpsilonMatcher.h"
#include <memory>

typedef std::shared_ptr<Matcher> MatchPointer;

struct Transition
	{
		int toState;
		MatchPointer matcher;

		Transition(int givenState, MatchPointer givenMatcher) : toState(givenState){
			matcher = givenMatcher;
		}
};

class State
{

	
public:

	std::string stateName;
	std::vector<Transition> stateTransitions;

	State();
	State(std::string name);

	void addTransition(int givenToState, Matcher& givenMatcher);

	void moveTransitions(int traslation);

	void myState();
	
};

