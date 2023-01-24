#include "State.hpp"
#include "Matcher.cpp"

State(std::string name)
{
	stateName = name;
}
void addTransition(std::string toState, Matcher matcher)
{
	std::tuple<State, Matcher> transition;
	transition = {toState, matcher};	
	stateTransitions.push_back(transition);
}
