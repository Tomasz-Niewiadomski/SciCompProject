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


EngineNFA oneStepNFA(Matcher& matcher);

EngineNFA EpsTransition();

EngineNFA addQuantifier(EngineNFA& input, char quantifier);

EngineNFA questionMark(EngineNFA& input);

EngineNFA plus(EngineNFA& input);

EngineNFA star(EngineNFA& input);

EngineNFA engineCreator(AstPointer input);


int main()
{

	std::string example1 = "a+bc";
	std::string example2 = "a|b";
	std::string example3 = "a*b*";
	std::string example4 = "a+b+c(ad)?d*d?";
	std::string example5 = "a?";
	
	// The string we search through (using regular expression selected above)
	std::string input("aaabbbbc");

	// Choose which example we run here
	std::string regularExpression = example2;


	std::cout << "We are representing the string: " + regularExpression << std::endl;
	EngineNFA nfa;
	AstPointer parsedRegularExpression = parser(regularExpression);
	nfa = engineCreator(parsedRegularExpression);
	
	nfa.myState(); 
	//<- problems here
	//
	//std::cout << "Currently looking for the following regular expression: " << regularExpression << std::endl;
	//parsedRegularExpression ->whoAmI(); // <- this works well
	////std::cout << std::endl;

	regularExpression = example4;
	

	std::cout << "We are representing the string: " + regularExpression << std::endl;
	EngineNFA nfa2;
	AstPointer parsedRegularExpression2 = parser(regularExpression);
	nfa2 = engineCreator(parsedRegularExpression2);

	nfa2.myState();
	
	return 0;
}

EngineNFA engineCreator(AstPointer input) {

	

	EngineNFA nfa;

	if (input->isAnAtom()) {

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
