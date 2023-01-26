#include <cstdio>
#include "EngineNFA.h"
#include<string>
#include<map>
#include "Matcher.h"
#include "State.h"
#include "CharacterMatcher.h"
#include "EpsilonMatcher.h"
#include <iostream>
#include <vector>


int main()
{
	EngineNFA nfa;
	std::vector<State> states_vec{State("q0"), State("q1"), State("q2")};

	nfa.declareStates(states_vec);

	CharacterMatcher c1("c");
	EpsilonMatcher c2;

	nfa.addTransition(0, 1, c1);
	nfa.addTransition(1, 0, c2);
	std::cout << nfa.states[0].stateTransitions[0].matcher.printLabel() << std::endl;
	std::cout << nfa.states[1].stateTransitions[0].matcher.printLabel();

}
