CXX = g++ -std=c++17
CXXFLAGS = -Wall -Werror

main: main.o
	$(CXX) $(CXXFLAGS) -O -o main main.o engineCreator.o EngineNFA.o State.o SpecialMatcher.o EpsilonMatcher.o CharacterMatcher.o Matcher.o parser.o Ast.o AstAlternative.o Atom.o SpecialAst.o Range.o

main.o: main.cpp parser.o engineCreator.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

engineCreator.o: engineCreator.cpp engineCreator.h Ast.o EngineNFA.o SpecialAst.o
	$(CXX) $(CXXFLAGS) -c engineCreator.cpp -o engineCreator.o

parser.o: parser.cpp parser.h Ast.o AstAlternative.o Atom.o SpecialAst.o
	$(CXX) $(CXXFLAGS) -c parser.cpp -o parser.o
		
SpecialAst.o: Ast.o SpecialAst.h SpecialAst.cpp
	$(CXX) $(CXXFLAGS) -c SpecialAst.cpp -o SpecialAst.o

Atom.o: Ast.o Atom.cpp Atom.h
	$(CXX) $(CXXFLAGS) -c Atom.cpp -o Atom.o

AstAlternative.o: Ast.o AstAlternative.cpp AstAlternative.h
	$(CXX) $(CXXFLAGS) -c AstAlternative.cpp -o AstAlternative.o

Ast.o: Ast.cpp Ast.h Range.o
	$(CXX) $(CXXFLAGS) -c Ast.cpp -o Ast.o
	
EngineNFA.o: EngineNFA.cpp EngineNFA.h State.o SpecialMatcher.o EpsilonMatcher.o CharacterMatcher.o Matcher.o
	$(CXX) $(CXXFLAGS) -c EngineNFA.cpp -o EngineNFA.o
	
State.o: State.cpp State.h
	$(CXX) $(CXXFLAGS) -c State.cpp -o State.o
	
SpecialMatcher.o: Matcher.o SpecialMatcher.cpp SpecialMatcher.h Range.o
	$(CXX) $(CXXFLAGS) -c SpecialMatcher.cpp -o SpecialMatcher.o

EpsilonMatcher.o: Matcher.o EpsilonMatcher.cpp EpsilonMatcher.h
	$(CXX) $(CXXFLAGS) -c EpsilonMatcher.cpp -o EpsilonMatcher.o

CharacterMatcher.o: Matcher.o CharacterMatcher.cpp CharacterMatcher.h
	$(CXX) $(CXXFLAGS) -c CharacterMatcher.cpp -o CharacterMatcher.o

Matcher.o: Matcher.cpp Matcher.h
	$(CXX) $(CXXFLAGS) -c Matcher.cpp -o Matcher.o
	
Range.o: Range.h Range.cpp
	$(CXX) $(CXXFLAGS) -c Range.cpp -o Range.o

.PHONY: clean
clean:
	rm -r *.o