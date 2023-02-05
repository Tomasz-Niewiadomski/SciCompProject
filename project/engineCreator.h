#pragma once
#include "Matcher.h"
#include "State.h"
#include "CharacterMatcher.h"
#include "EpsilonMatcher.h"
#include "EngineNFA.h"
#include "Ast.h"
#include <memory>


typedef std::shared_ptr<Ast> AstPointer;


EngineNFA oneStepNFA(Matcher& matcher);

EngineNFA EpsTransition();

EngineNFA addQuantifier(EngineNFA& input, char quantifier);

EngineNFA questionMark(EngineNFA& input);

EngineNFA plus(EngineNFA& input);

EngineNFA star(EngineNFA& input);

EngineNFA engineCreator(AstPointer input);

