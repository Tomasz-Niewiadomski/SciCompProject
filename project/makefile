CXX = g++ -std=c++17
CXXFLAGS = -Wall -Werror

main : main.o
	$(CXX) $(CXXFLAGS) -O -o main main.o EngineNFA.o State.o EpsilonMatcher.o CharacterMatcher.o Matcher.o

main.o: main.cpp EngineNFA.o State.o EpsilonMatcher.o CharacterMatcher.o Matcher.o
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o
	
EngineNFA.o: EngineNFA.cpp EngineNFA.h
	$(CXX) $(CXXFLAGS) -c EngineNFA.cpp -o EngineNFA.o
	
State.o: State.cpp State.h
	$(CXX) $(CXXFLAGS) -c State.cpp -o State.o
	
EpsilonMatcher.o: Matcher.cpp Matcher.h EpsilonMatcher.cpp EpsilonMatcher.h
	$(CXX) $(CXXFLAGS) -c EpsilonMatcher.cpp -o EpsilonMatcher.o

CharacterMatcher.o: Matcher.cpp Matcher.h CharacterMatcher.cpp CharacterMatcher.h
	$(CXX) $(CXXFLAGS) -c CharacterMatcher.cpp -o CharacterMatcher.o

Matcher.o: Matcher.cpp Matcher.h
	$(CXX) $(CXXFLAGS) -c Matcher.cpp -o Matcher.o
	

.PHONY: clean
clean:
	rm -r *.o