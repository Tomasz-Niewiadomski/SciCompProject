#pragma once
#include <string>
#include <vector>
#include "Matcher.h"
#include "CharacterMatcher.h"
#include "EpsilonMatcher.h"
#include <memory>

/// Used to retain the inheritance properties of the Matcher children classes.
typedef std::shared_ptr<Matcher> MatchPointer;

/// @brief Struct local to the state's class used to pass the transition information
/// @details  Created for the transition information to be passed in a vector without losing the inheritance properties of the Matcher children classes.
struct Transition
	{
		int toState;
		MatchPointer matcher;

		/// Constructor for the Transition struct
		Transition(int givenState, MatchPointer givenMatcher) : toState(givenState){
			matcher = givenMatcher;
		}
};

/** @brief Individual state in an NFA
*/
class State
{	
public:

	/// Name of the state (used for debugging)
	std::string stateName;
	/// Vector of transitions from this state
	std::vector<Transition> stateTransitions;

	State();
	State(std::string name);

	/// @brief Adds a transition to the stateTransitions vector of this state
	/// @param givenToState The index of a state to which the transition leads
	/// @param givenMatcher The matcher associated with the transition
	void addTransition(int givenToState, Matcher& givenMatcher);

	void moveTransitions(int traslation);

	void myState();
	
};

