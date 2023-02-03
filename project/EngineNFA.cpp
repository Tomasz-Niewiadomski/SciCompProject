#include "EngineNFA.h"
#include "Matcher.h"
#include "State.h"
#include "EpsilonMatcher.h"
#include <string>
#include <map>
#include <stack>
#include <algorithm>
#include<iostream>

EngineNFA::EngineNFA()
{
	startState = 0;
	endState = 0;
}

void EngineNFA::addState(State state)
{	//before, it was:
	//states.push_back(State(state));
	states.push_back(state);
	if (states.size() > 1)
		endState++;
};

void EngineNFA::declareStates(std::vector<State> declaredStates)
{
	for (int i = 0; i < (int) declaredStates.size(); i++)
	{

		addState(declaredStates[i]);

	}
};

	// Stupid workaround: state q0 has index 0, q1 has index 1, etc...
void EngineNFA::addTransition(int fromState, int toState, Matcher &matcher)
{
	states[fromState].addTransition(toState, matcher);
};


bool EngineNFA::compute(std::string string)
{
	struct Triple
	{
		int iterator;
		int state;
		std::vector<int> memory;
		// Two constructors, one without vector, one with vector
		Triple(int givenI, int givenState) : iterator(givenI), state(givenState), memory(0){}
		Triple(int givenI, int givenState, std::vector<int> givenMemory) : iterator(givenI), state(givenState), memory(givenMemory){}
	};

	std::stack<Triple> stack;
	Triple stackMember(0, startState);

	stack.push(stackMember);

	while (not stack.empty())
	{
		int i = stack.top().iterator;
		int currentState = stack.top().state;
		std::vector<int> memory = stack.top().memory;
		stack.pop();

		// Check if we reached the end
		if (endState == currentState)
		{
			return true;
		}

		// take i-th element of input string
		// Has to be done this way, because char cannot conver to
		// string in a normal way
		std::string input(1, string[i]);

		// Iterate through all transitions in each state
		for (int c = states[currentState].stateTransitions.size()-1; c >= 0; c--)
		{
			int toState = states[currentState].stateTransitions[c].toState;

			// Check if matcher matches the input character
			// cannot define the matcher to other variable
			// - constructor issues
			if (states[currentState].stateTransitions[c].matcher->matches(input) == true)
			{
				// Locally store memory
				std::vector<int> copyMemory = memory;
				// Check if the matcher is an epsilon
				if (states[currentState].stateTransitions[c].matcher->isEpsilon())
				{
					// Checks if toState is in memory vector
					if (std::count(memory.begin(), memory.end(), toState))
						{
							continue;
						}
					copyMemory.push_back(currentState);
				}
				else
				{
					copyMemory.clear();
				}

				int nextIterator;

				if (states[currentState].stateTransitions[c].matcher->isEpsilon())
				{
					nextIterator = i;
				}
				else
				{
					nextIterator = i + 1;
				}

				Triple newStackMember(nextIterator, toState, copyMemory);
				stack.push(newStackMember);
			}
		}
	}
	// If stack empty
	return false;
};

void EngineNFA::concatenateNFA(EngineNFA nfaToConcat)
{

	nfaToConcat.states[0].moveTransitions(endState);

	if (!states.empty()) {

		for (int i = 0; i < (int)nfaToConcat.states[0].stateTransitions.size(); i++) {
			
			int toState = nfaToConcat.states[0].stateTransitions[i].toState;
			
			Matcher& match = *nfaToConcat.states[0].stateTransitions[i].matcher;
			
			states[endState].addTransition(toState, match);
			
		}

	}
	else
	{

		addState(nfaToConcat.states[0]);
	}
	int initEnd = endState;
	for (int i = 1; i < (int) nfaToConcat.states.size(); i++)
	{
		nfaToConcat.states[i].moveTransitions(initEnd);
		addState(nfaToConcat.states[i]);
	}
}

EngineNFA::EngineNFA(EngineNFA nfa1, EngineNFA nfa2) : EngineNFA() {
	
	addState(State("q0"));
	addState(State("q1")); // we need 2 states because concatenateNFA substitutes the last one 
	
	concatenateNFA(nfa1);

	int startState1 = 1;
	int endState1 = endState;

	addState(State("qFake")); // this is a fake state just to trick (again) concatenateNFA

	concatenateNFA(nfa2);
	
	
	int startState2 = endState1 + 1;
	int endState2 = endState;

	addState(State("qfinal"));

	EpsilonMatcher eps = EpsilonMatcher(); 

	addTransition(0, startState1, eps);
	addTransition(0, startState2, eps);
	
	addTransition(endState1, endState, eps);
	addTransition(endState2, endState, eps);
}

void EngineNFA::myState()
{
	std::cout << "Number of states (endState+1): " << endState + 1 << std::endl;

	std::cout << "Number of states (states.size()): " << states.size() << " (they should be the same)" << std::endl;

	std::cout << std::endl;


	for (int i = 0; i < (int)states.size(); i++) {
		std::cout << "State " << i << std::endl;
		std::cout << "Transitions: ";
		
		states[i].myState();
	}

	std::cout<<std::endl;
}
