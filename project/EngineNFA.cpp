#include "EngineNFA.h"
#include<string>
#include<map>
#include "Matcher.h"
#include "State.h"
#include<stack>

EngineNFA::EngineNFA()
{
	startState = 0;
	endState = 0;
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
	states[fromState].addTransition(toState, matcher);
};

bool EngineNFA::compute(std::string string)
{
	struct Pair
	{
		int iterator;
		int state;
		Pair(int givenInt, int givenState) : iterator(givenInt), state(givenState){}
	};

	std::stack<Pair> stack;
	Pair stackMember(0, startState);

	stack.push(stackMember);

	while (not stack.empty())
	{
		int i = stack.top().iterator;
		int currentState = stack.top().state;

		stack.pop();

		if (endState == currentState)
		{
			return true;
		}

		std::string input(1, string[i]);

		for (int c = states[currentState].stateTransitions.size()-1; c >= 0; c--)
		{
			int toState = states[currentState].stateTransitions[c].toState;

			if (states[currentState].stateTransitions[c].matcher.matches(input) == true)
			{
				int nextIterator;
				if (states[currentState].stateTransitions[c].matcher.isEpsilon())
				{
					nextIterator = i;
				}
				else
				{
					nextIterator = i+1;
				}
				Pair newStackMember(nextIterator, toState);
				stack.push(newStackMember);
			}

		}
	}
	return false;
}
