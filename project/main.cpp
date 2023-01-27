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

//	std::vector<State> states_vec{State("q0"), State("q1"), State("q2"), State("q3")};
//
//	nfa.declareStates(states_vec);
//
//	CharacterMatcher c01("a");
//	CharacterMatcher c12("b");
//	CharacterMatcher c22("b");
//	EpsilonMatcher c23;
//
//	nfa.addTransition(0, 1, c01);
//	nfa.addTransition(1, 2, c12);
//	nfa.addTransition(2, 2, c22);
//	nfa.addTransition(2, 3, c23);
//
//	bool test1 = nfa.compute("abbbbbb");
//	bool test2 = nfa.compute("aabbbbbb");
//	bool test3 = nfa.compute("ab");
//	bool test4 = nfa.compute("a");
//
//	std::cout << "Test 1: ['abb*' matches 'abbbbbb'?] (should be true): " << test1 << std::endl;
//	std::cout << "Test 2: ['abb*' matches 'aabbbbbb'?] (should be false): " << test2 << std::endl;
//	std::cout << "Test 3: ['abb*' matches 'ab'?] (should be true): " << test3 << std::endl;
//	std::cout << "Test 4: ['abb*' matches 'a'?] (should be false): " << test4 << std::endl;

	std::vector<State> states_vector{State("q0"), State("q1"), State("q2")};
	nfa.declareStates(states_vector);

	CharacterMatcher a("a");
	EpsilonMatcher eps;
	CharacterMatcher b("b");

	nfa.addTransition(0, 1, a);
	nfa.addTransition(1, 1, eps);
	nfa.addTransition(1, 2, b);
	std::cout<< "Should return true: " << nfa.compute("ab") << " ... and not be stuck forever" << std::endl;
}
