#include <iostream>
#include <vector>
#include <string>
#include <map>

// Turn this into an abstract class or somethin
//
// Currently, there's a problem:
//
// 	child class of Matcher, doesn't overload its own functions
// 	instead, it defaults to the parent functions for some reason
// 	this is bad :(

class Matcher
{
	public:
		virtual bool matches(std::string character)
		{
			return false;
		}

		virtual bool isEpsilon()
		{
			return bool(0);
		}

		virtual std::string printLabel()
		{
			return "unidentified matcher";
		}

};

class CharacterMatcher: public Matcher
{
	public:
		std::string c;

		CharacterMatcher(std::string givenCharacter)
		{
			c = givenCharacter;
		}

		bool matches(std::string character) override
		{
			return (c == character);
		}

		bool isEpsilon() override
		{
			return false;
		}

		std::string printLabel() override
		{
			return c;
		}
};

class EpsilonMatcher: public Matcher
{
    public:
    	
    	bool matches(std::string character) override
    	{
    		return true;
    	}
                                                         
    	bool isEpsilon() override
    	{
    		return true;
    	}
                                                         
  	std::string printLabel() override
    	{
    		return "epsilon";
    	}
};


		
class State
{
	struct Transition
	{
		State toState;
		Matcher matcher;
		
		Transition(State givenState, Matcher givenMatcher) : toState(givenState), matcher(givenMatcher){}
	};
	
	public:
		
		std::string stateName;
		std::vector<Transition> stateTransitions;

		State(std::string name)
		{
			stateName = name;
		}

		void addTransition(State &givenToState, Matcher &givenMatcher)
		{
			Transition transition(givenToState, givenMatcher);
			stateTransitions.push_back(transition);
		}
};

 //To be finished 
//class EngineNFA
//{
  //public:
	
	//std::map<std::string, State> states;
	//State startState;
	//State endState;

	//void setStartState(State givenState)
	//{
	  //startState = givenState;
	//}

	//void setEndState(std::string name)
	//{
	 //states[name] = State(name); 
	//}

	//void addTransition(State fromState, State toState, Matcher matcher)
	//{
	  //// Uses the addTransition() from State class
	  //states[fromState].addTransition(states[toState], matcher);
	//}

	//void compute(std::string)
	//{

	//}

//};

	
int main()
{

	State s1("s1");
	State s2("s2");
	State s3("s3");
	
	CharacterMatcher c1("c");
	EpsilonMatcher c2;
	s1.addTransition(s2, c1); // transition from s1 -> s2 with matcher "c"
	
	
	//std::cout << "Transitions from the state: " << s1.stateName << " to the state: " << s1.stateTransitions[0].toState.stateName << " with matcher: " << s1.stateTransitions[0].matcher.printLabel() << std::endl;
	
	
	typedef std::map<std::string, State> Smap;
	Smap test_map;
	
	test_map["abc"] = s3;
	
	State c1_check = test_map["abc"];
	
	std:: cout << c1_check.stateName << std::endl;
	//std::cout << states["abc"].printLabel() << std::endl;
	//std::cout << states["s1"].stateName << std::endl;
}


