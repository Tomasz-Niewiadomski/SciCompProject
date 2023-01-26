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
		State &toState;
		Matcher &matcher;

		Transition(State &givenState, Matcher &givenMatcher) : toState(givenState), matcher(givenMatcher){}
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

// How about we assume that the first vec element is the starting state & the last vec element is the ending state?
class EngineNFA
{
	public:

	std::vector<State> states;
	int startState = 0;
	int endState = 0;

	void addState(State state)
	{
		states.push_back(State(state));
	}

	void declareStates(std::vector<State> declaredStates)
	{
		for (int i = 0; i < declaredStates.size(); i++)
		{
			addState(declaredStates[i]);
		}
		if (states.size() != 0)
			{
				endState = states.size()-1;
			}
	}
	// Stupid workaround: state q0 has index 0, q1 has index 1, etc...
	void addTransition(int fromState, int toState, Matcher &matcher)
		{
			states[fromState].addTransition(states[toState], matcher);
		}

	void compute(std::string)
		{

		}
};

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
