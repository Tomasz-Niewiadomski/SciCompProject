#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>

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
		int toState;
		Matcher &matcher;
		Transition(int givenState, Matcher &givenMatcher) : toState(givenState), matcher(givenMatcher){}
	};
	public:
		std::string stateName;
		std::vector<Transition> stateTransitions;
	    State()
			{
				stateName = std::string(0);
			}
		State(std::string name)
		{
			stateName = name;
		}
		void addTransition(int givenToState, Matcher &givenMatcher)
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
	int startState;
	int endState;
	EngineNFA()
	{
		startState = 0;
		endState = 0;
	}
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
			states[fromState].addTransition(toState, matcher);
		}
	bool compute(std::string string)
		{
			struct Pair{
				int iterator;
				int state;
				Pair(int givenInt, int givenState) : iterator(givenInt), state(givenState){}
			};

			std::stack<Pair> stack;
			Pair stackMember(0, startState);

			stack.push(stackMember);

			while (not stack.empty())
			{
				int i = stack.top().iterator;
				int currentState = stack.top().state;
				stack.pop();

				if (endState == currentState)
				{
					return true;
				}

				std::string input(1, string[i]);

				for (int c = states[currentState].stateTransitions.size()-1; c >= 0; c--)
				{
					int toState = states[currentState].stateTransitions[c].toState;

					if (states[currentState].stateTransitions[c].matcher.matches(input) == true)
					{
						int nextIterator;
						if (states[currentState].stateTransitions[c].matcher.isEpsilon())
						{
							nextIterator = i;
						}
						else
						{
							nextIterator = i+1;
						}
						Pair newStackMember(nextIterator, toState);
						stack.push(newStackMember);
					}

				}
			}
			return false;
		}
};
int main()
{
	EngineNFA nfa;

	std::vector<State> states_vec{State("q0"), State("q1"), State("q2"), State("q3")};

	nfa.declareStates(states_vec);

	CharacterMatcher c01("a");
	CharacterMatcher c12("b");
	CharacterMatcher c22("b");
	EpsilonMatcher c23;

	nfa.addTransition(0, 1, c01);
	nfa.addTransition(1, 2, c12);
	nfa.addTransition(2, 2, c22);
	nfa.addTransition(2, 3, c23);

	bool test1 = nfa.compute("abbbbbb");
	bool test2 = nfa.compute("aabbbbbb");
	bool test3 = nfa.compute("ab");
	bool test4 = nfa.compute("a");
	bool test5 = nfa.compute("abc");

	std::cout << "Test 1: ['abb*' matches 'abbbbbb'?] (should be true): " << test1 << std::endl;
	std::cout << "Test 2: ['abb*' matches 'aabbbbbb'?] (should be false): " << test2 << std::endl;
	std::cout << "Test 3: ['abb*' matches 'ab'?] (should be true): " << test3 << std::endl;
	std::cout << "Test 4: ['abb*' matches 'a'?] (should be false): " << test4 << std::endl;
	std::cout << "Test 5: ['abb*' matches 'abc'?](should be false): " << test5 << " -> needs 'memory' feature " << std::endl;
}
