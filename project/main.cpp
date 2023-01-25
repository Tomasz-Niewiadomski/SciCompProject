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

typedef std::map<std::string, Matcher> Mmap;


Mmap states(std::string& key, Matcher& value)
{
	std::map<std::string, Matcher> map_to_be_returned;
	map_to_be_returned[key] = value;
	return map_to_be_returned;
}

int main()
{
	std::map<std::string, Matcher> states;
	State s1("s1");
	State s2("s2");
	CharacterMatcher c1("c");
	EpsilonMatcher c2;
	s1.addTransition(s2, c1); // transition from s1 -> s2 with matcher "c"


	//std::cout << "Transitions from the state: " << s1.stateName << " to the state: " << s1.stateTransitions[0].toState.stateName << " with matcher: " << s1.stateTransitions[0].matcher.printLabel() << std::endl;



	Mmap test_map;
	std::string input_text = "abc";
	// Matcher c1_check = test_map["abc"];

	//std::cout << c1_check.printLabel() << std::endl;
	//std::cout << states["abc"].printLabel() << std::endl;
	//std::cout << states["s1"].stateName << std::endl;
}