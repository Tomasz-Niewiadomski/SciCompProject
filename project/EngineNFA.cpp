#include <map>
#include <string>
#include "State.hpp"
#include  "Matcher.hpp"


class EngineNFA
{
  public:
    std::map<std::string, State> states;
    State startState;
    State endState;

    void setStartState(State givenState)
    {
      startState = givenState;
    }

    void setEndState(std::string name)
    {
     states[name] = State(name); 
    }

    void addTransition(State fromState, State toState, Matcher matcher)
    {
      // Uses the addTransition() from State class
      states[fromState].addTransition(states[toState], matcher);
    }
	
	// The elephant in the room
    void compute(std::string)
    {

    }
};
