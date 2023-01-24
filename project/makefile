CXX = g++ -std=c++17 
CXXFLAGS = -Wall -Werror

core: core.o
	$(CXX) $(CXXFLAGS) core.o -o core

core.o: core.cpp
	$(CXX) $(CXXFLAGS) -c core.cpp -o core

.PHONY: clean
clean:
	rm -r *.o
