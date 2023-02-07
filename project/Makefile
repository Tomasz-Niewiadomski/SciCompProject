CXX = g++ -std=c++17
CXXFLAGS = -Wall

main: main.o
	$(CXX) $(CXXFLAGS) -O -o main main.o engineCreator.o EngineNFA.o State.o EpsilonMatcher.o CharacterMatcher.o DotMatcher.o Matcher.o parser.o Ast.o AstAlternative.o Atom.o

main.o: main.cpp parser.o engineCreator.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

engineCreator.o: engineCreator.cpp engineCreator.h Ast.o EngineNFA.o
	$(CXX) $(CXXFLAGS) -c engineCreator.cpp -o engineCreator.o

parser.o: parser.cpp parser.h Ast.o AstAlternative.o Atom.o
	$(CXX) $(CXXFLAGS) -c parser.cpp -o parser.o
		
Atom.o: Ast.cpp Ast.h Atom.cpp Atom.h
	$(CXX) $(CXXFLAGS) -c Atom.cpp -o Atom.o

AstAlternative.o: Ast.cpp Ast.h AstAlternative.cpp AstAlternative.h
	$(CXX) $(CXXFLAGS) -c AstAlternative.cpp -o AstAlternative.o

Ast.o: Ast.cpp Ast.h
	$(CXX) $(CXXFLAGS) -c Ast.cpp -o Ast.o
	
EngineNFA.o: EngineNFA.cpp EngineNFA.h State.o EpsilonMatcher.o CharacterMatcher.o DotMatcher.o Matcher.o
	$(CXX) $(CXXFLAGS) -c EngineNFA.cpp -o EngineNFA.o
	
State.o: State.cpp State.h
	$(CXX) $(CXXFLAGS) -c State.cpp -o State.o
	
EpsilonMatcher.o: Matcher.cpp Matcher.h EpsilonMatcher.cpp EpsilonMatcher.h
	$(CXX) $(CXXFLAGS) -c EpsilonMatcher.cpp -o EpsilonMatcher.o

CharacterMatcher.o: Matcher.cpp Matcher.h CharacterMatcher.cpp CharacterMatcher.h
	$(CXX) $(CXXFLAGS) -c CharacterMatcher.cpp -o CharacterMatcher.o

DotMatcher.o: Matcher.cpp Matcher.h DotMatcher.cpp DotMatcher.h
	$(CXX) $(CXXFLAGS) -c DotMatcher.cpp -o DotMatcher.o

Matcher.o: Matcher.cpp Matcher.h
	$(CXX) $(CXXFLAGS) -c Matcher.cpp -o Matcher.o
	

.PHONY: clean
clean:
	rm -r *.o
