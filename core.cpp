#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <algorithm>

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
			struct Triple
			{
				int iterator;
				int state;
				std::vector<int> memory;
				Triple(int givenI, int givenState) : iterator(givenI), state(givenState), memory(0){}
				Triple(int givenI, int givenState, std::vector<int> givenMemory) : iterator(givenI), state(givenState), memory(givenMemory){}
			};

			std::stack<Triple> stack;
			Triple stackMember(0, startState);

			stack.push(stackMember);

			while (not stack.empty())
			{
				int i = stack.top().iterator;
				int currentState = stack.top().state;
				std::vector<int> memory = stack.top().memory;
				stack.pop();

				if (endState == currentState)
				{
					return true;
				}

				std::string input(1, string[i]);

				for (int c = states[currentState].stateTransitions.size()-1; c >= 0; c--)
				{
					int toState = states[currentState].stateTransitions[c].toState;

					// Check if matcher matches the input character
					if (states[currentState].stateTransitions[c].matcher.matches(input) == true)
					{
						std::vector<int> copyMemory = memory;
						int nextIterator;
						// Check if the matcher is an epsilon
						if (states[currentState].stateTransitions[c].matcher.isEpsilon())
						{
							// Checks if toState is in memory vector
							if (std::count(memory.begin(), memory.end(), toState))
								{
									continue;
								}
							copyMemory.push_back(currentState);
						}
						else
						{
							copyMemory.clear();
						}

						if (states[currentState].stateTransitions[c].matcher.isEpsilon())
						{
							nextIterator = i;
						}
						else
						{
							nextIterator = i + 1;
						}

						Triple newStackMember(nextIterator, toState, copyMemory);
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

//	std::vector<State> states_vector{State("q0"), State("q1"), State("q2")};
//	nfa.declareStates(states_vector);
//
//	CharacterMatcher a("a");
//	EpsilonMatcher eps;
//	CharacterMatcher b("b");
//
//	nfa.addTransition(0, 1, a);
//	nfa.addTransition(1, 1, eps);
//	nfa.addTransition(1, 2, b);
//	std::cout<< "Should return true: " << nfa.compute("ab") << " ... and not be stuck forever" << std::endl;
}
