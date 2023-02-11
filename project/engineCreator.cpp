#include "engineCreator.h"
#include "Matcher.h"
#include "State.h"
#include "CharacterMatcher.h"
#include "EpsilonMatcher.h"
#include "SpecialMatcher.h"

#include "EngineNFA.h"
#include "Ast.h"
#include "SpecialAst.h"

#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <memory>


typedef std::shared_ptr<Ast> AstPointer;


EngineNFA engineCreator(AstPointer input) {



	EngineNFA nfa;
	if (input->isItSpecial()) { // returns oneStepNFA with a special matcher

		SpecialMatcher matcher;

		for (auto& element : input->ranges) { // for each range in the vector of ranges, add it to the special matcher	
			matcher.setRanges(element); 
		}
		
		nfa = oneStepNFA(matcher);
	}
	if (input->isAnAtom()) { // returns oneStepNFA with a character matcher

		std::string character = input->expression;


		CharacterMatcher matcher = CharacterMatcher(character);


		nfa = oneStepNFA(matcher);


	}
	if (input->isAnAlternative()) {
		nfa = EngineNFA(engineCreator(input->subExpr[0]), engineCreator(input->subExpr[1]));
	}
	if (input->isAnAst()) {
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
	EpsilonMatcher eps;
	EngineNFA epsNFA = oneStepNFA(eps);

	nfa = oneStepNFA(eps);

	nfa.concatenateNFA(input);
	nfa.concatenateNFA(epsNFA);

	nfa.addTransition(nfa.startState, nfa.endState, eps);

	return nfa;
}

EngineNFA plus(EngineNFA& input) {
	EpsilonMatcher eps = EpsilonMatcher();
	input.addTransition(input.endState, input.startState, eps);
	return input;
}

EngineNFA star(EngineNFA& input) {
	EngineNFA ret = plus(input);

	return questionMark(ret);

}

EngineNFA oneStepNFA(Matcher& matcher)
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

