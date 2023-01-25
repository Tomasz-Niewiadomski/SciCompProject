#include "EngineNFA.h"
#include<string>
#include<map>
#include "Matcher.h"
#include "State.h"

void EngineNFA::setStartState(State givenState)
{
	startState = givenState;
};

void EngineNFA::setEndState(std::string name)
{
	states[name] = State(name);
};

void EngineNFA::addTransition(State fromState, State toState, Matcher matcher)
{
	//// Uses the addTransition() from State class
	//states[fromState].addTransition(states[toState], matcher);
};

void EngineNFA::compute(std::string)
{

};