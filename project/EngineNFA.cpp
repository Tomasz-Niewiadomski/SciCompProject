#include "EngineNFA.h"
#include<string>
#include<map>
#include "Matcher.h"
#include "State.h"

EngineNFA::EngineNFA()
{
	startState = 0;
	startState = 0;
}

void EngineNFA::addState(State state)
{
	states.push_back(State(state));
};

void EngineNFA::declareStates(std::vector<State> declaredStates)
{
	for (int i = 0; i < declaredStates.size(); i++)
	{

		addState(declaredStates[i]);

	}
	if (states.size() != 0)
		{

			endState = states.size()-1;

		}
};

	// Stupid workaround: state q0 has index 0, q1 has index 1, etc...
void EngineNFA::addTransition(int fromState, int toState, Matcher &matcher)
{
	states[fromState].addTransition(states[toState], matcher);
};

void EngineNFA::compute(std::string)
{

};
