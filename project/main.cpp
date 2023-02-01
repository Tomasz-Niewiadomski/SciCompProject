#include "Matcher.h"
#include "State.h"
#include "CharacterMatcher.h"
#include "EpsilonMatcher.h"
#include "EngineNFA.h"
#include "Ast.h"
#include "AstAlternative.h"
#include "Atom.h"

#include <cstdio>
#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <string>
#include <memory>


typedef std::shared_ptr<Ast> AstPointer;

int findOr(std::string& input);

int findClosure(std::string& input, int start);

bool isAQuantifier(char c);

AstPointer parser(std::string input);


EngineNFA oneStepNFA(Matcher matcher);

EngineNFA EpsTransition();

EngineNFA atomicNFA(std::string character, char quantifier);

EngineNFA addQuantifier(EngineNFA& input, char quantifier);

EngineNFA questionMark(EngineNFA& input);

EngineNFA plus(EngineNFA& input);

EngineNFA star(EngineNFA& input);

EngineNFA engineCreator(AstPointer input);


int main()
{
	//charactermatcher c01("a");
	//epsilonmatcher e;
	//	
	//std::cout << "starting state: " << onestepnfa(e).startstate << " and ending state: " << onestepnfa(e).endstate << std::endl;

	std::string provolone1 = "abc";

	EngineNFA nfa;

	nfa = engineCreator(parser(provolone1));

	nfa.myState();

//	std::vector<State> states_vec{State("q0"), State("q1"), State("q2"), State("q3")};
//
//	nfa.declareStates(states_vec);
//
//	CharacterMatcher c01("a");
//	CharacterMatcher c12("b");#include "EngineNFA.h"

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

	//std::vector<State> states_vector{State("q0"), State("q1"), State("q2")};
	//nfa.declareStates(states_vector);

	//CharacterMatcher a("a");
	//EpsilonMatcher eps;
	//CharacterMatcher b("b");

	//nfa.addTransition(0, 1, a);
	//nfa.addTransition(1, 1, eps);
	//nfa.addTransition(1, 2, b);
	//std::cout<< "Should return true: " << nfa.compute("ab") << " ... and not be stuck forever" << std::endl;




	return 0;
}

EngineNFA engineCreator(AstPointer input) {

	

	EngineNFA nfa;

	if (input->isAnAtom()) {

		
		std::string charact = input->expression;
		
		char quant = input->quantifier;
		
		nfa = atomicNFA(charact, quant);
	}
	if (input->isAnAlternative()) {
		nfa = EngineNFA(engineCreator(input->subExpr[0]), engineCreator(input->subExpr[1]));
	}
	else {
		int numExpr = static_cast<int>(input->subExpr.size());

		for (int i = 0; i < numExpr; i++) {
			nfa.concatenateNFA(engineCreator(input->subExpr[i]));
		}
	}


	return addQuantifier(nfa, input->quantifier);
}

EngineNFA addQuantifier(EngineNFA& input, char quantifier) {
	switch (quantifier)
	{
	case '?':
		return questionMark(input);
	case '+':
		return plus(input);
	case '*':
		return star(input);
	default:
		return input;
	}
}

EngineNFA questionMark(EngineNFA& input) {
	EngineNFA nfa;
	nfa = EpsTransition();
	nfa.concatenateNFA(input);
	nfa.concatenateNFA(EpsTransition());

	EpsilonMatcher eps;
	nfa.addTransition(nfa.startState, nfa.endState, eps);

	return nfa;
}

EngineNFA plus(EngineNFA& input) {
	EpsilonMatcher eps;
	input.addTransition(input.endState, input.startState, eps);
	return input;
}

EngineNFA star(EngineNFA& input) {
	EngineNFA ret = plus(input);

	return questionMark(ret);

}

EngineNFA atomicNFA(std::string character, char quantifier) {

	CharacterMatcher matcher = CharacterMatcher(character);

	EngineNFA nfa;

	nfa = oneStepNFA(matcher);

	return addQuantifier(nfa, quantifier);
}


EngineNFA oneStepNFA(Matcher matcher)
{
	EngineNFA nfa;
	std::vector<State> statesVector{ State("q0"), State("q1") };
	nfa.declareStates(statesVector);
	nfa.addTransition(0, 1, matcher);

	return nfa;
}

EngineNFA EpsTransition() {
	EpsilonMatcher eps;

	return oneStepNFA(eps);
}


AstPointer parser(std::string input) {
	
	int k = findOr(input);

	AstPointer tree;

	if (k > 0)
	{
		std::string string1 = input.substr(0, k);
		std::string string2 = input.substr(k + 1);


		tree = AstPointer(new AstAlternative(parser(string1), parser(string2)));
	}
	else
	{
		tree = AstPointer(new Ast(input));

		int max = static_cast<int>(input.length());

		for (int i = 0; i < max; )
		{
			if (input[i] == '(')
			{
				int k = findClosure(input, i);

				std::string substr = input.substr(i + 1, k - i - 1);

				AstPointer iter(new Ast);
				iter = parser(substr);
				tree->addSubExpr(iter);

				if ((k + 1 < max) and isAQuantifier(input[k + 1])) {
					k = k + 1;
					iter->quantifier = input[k];
				}


				i = k + 1;

				continue;
			}

			if (input[i] == '\\')
				i = i + 1;

			AstPointer car(new Atom(input[i]));

			if ((i + 1 < max) and (isAQuantifier(input[i + 1]))) {
				i = i + 1;
				car->quantifier = input[i];
			}

			tree->addSubExpr(car);

			i = i + 1;

		}

	}

	return tree;
}

int findOr(std::string& input) {
	int pos = -1;

	int length = static_cast<int>(input.length());

	for (int i = 0; i < length;) {
		if (input[i] == '(') {
			i = findClosure(input, i) + 1;
			continue;
		}
		if (input[i] == '\\') {
			i = i + 2;
			continue;
		}
		if (input[i] == '|') {
			pos = i;
			break;
		}
		i = i + 1;
	}


	return pos;
}

int findClosure(std::string& input, int start) {

	int i;

	int found = -1;

	int length = static_cast<int>(input.length());

	if (start + 1 > length)
	{
		std::cerr << "The Regex is badly written (find closure)" << std::endl;
	}

	for (i = start + 1; i < length; i = i + 1) {

		if (input[i] == '(')
			found = found - 1;

		if (input[i] == ')')
			found = found + 1;

		if (input[i] == '\\')
			i = i + 1;


		if (found == 0)
			break;

	}
	return i;
}

bool isAQuantifier(char c) {
	return ((c == '+') or (c == '*') or (c == '?'));
}
