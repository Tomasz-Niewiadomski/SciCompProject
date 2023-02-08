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
	std::string example5 = "bcd";
	
	// The string we search through (using regular expression selected above)
	std::string input("abcd");

	// Choose which example we run here
	std::string regularExpression = example5;


	EngineNFA nfa;
	AstPointer parsedRegularExpression = parser(regularExpression);
	nfa = engineCreator(parsedRegularExpression);
	
	std::cout << "Currently looking for the following regular expression: " << regularExpression << std::endl;
	std::cout << "Does it match the string: " << input << "?" << std::endl;
	std::cout << "The answer is: " << nfa.search(input) << std::endl;

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
