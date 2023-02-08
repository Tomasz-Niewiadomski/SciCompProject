#include "parser.h"
#include "engineCreator.h"
#include "EngineNFA.h"
#include <string>
#include <iostream>
#include <vector>
#include <string>
#include <memory>


typedef std::shared_ptr<Ast> AstPointer;

int main()
{

	std::string example1 = "a+bc";
	std::string example2 = "a|b";
	std::string example3 = "a*b*";
	std::string example4 = "a+b+c(ad)?d*d?";
	std::string example5 = "Georgio";
	std::string example6 = "NFA";
	
	// The string we search through (using regular expression selected above)
	std::string input("My name is Giovani Georgio, but everyone calls me Georgio.");
	std::string input2("You might have realized that since ComplexClass already has a matches method it could inherit from Matcher. The main reason I didn't do that is because they are at different layers of abstraction. First we parse the text to create a Parse Tree (PT), translate the PT to an Abstract Syntax Tree (AST) and finally create a NFA. Matchers are part of the NFA, so the AST shouldn't depend on the NFA.");


	// Choose which example we run here
	std::string regularExpression = example5;


	EngineNFA nfa;
	AstPointer parsedRegularExpression = parser(regularExpression);
	nfa = engineCreator(parsedRegularExpression);
	
	std::cout << " ------------------ " << std::endl;
	std::cout << "Currently looking for the following regular expression: '" << regularExpression << "'" << std::endl;
	std::cout << "Does it match the given string: '" << input << "'?" << std::endl;
	std::cout << "The answer is: " << nfa.search(input) << std::endl;
	std::cout << " ------------------ " << std::endl;
	nfa.printOccurances(input);

	//nfa.myState(); 
	//<- problems here
	//
	//parsedRegularExpression ->whoAmI(); // <- this works well
	////std::cout << std::endl;

	//regularExpression = example4;
	

	//std::cout << "We are representing the string: " + regularExpression << std::endl;
	//EngineNFA nfa2;
	//AstPointer parsedRegularExpression2 = parser(regularExpression);
	//nfa2 = engineCreator(parsedRegularExpression2);

	//nfa2.myState();
	
	return 0;
}
