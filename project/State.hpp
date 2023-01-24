#ifndef STATE_HPP_
#define STATE_HPP_

#include <string>
#include <tuple>

class State
{
	public:
		std::string stateName;
		std::vector<std::tuple<State, Matcher> > stateTransitions;
		
		State(std::string name);
		void addTransition(std::string toState, Matcher matcher)
};


#endif
