CXX = g++ -std=c++17
CXXFLAGS = -Wall -Werror

test : test.o naiveRegex.o
	$(CXX) $(CXXFLAGS) -O -o test test.o naiveRegex.o

test.o: test.cpp naiveRegex.hpp naiveRegex.cpp
	 $(CXX) $(CXXFLAGS) -c test.cpp -o test.o

naiveRegex.o: naiveRegex.cpp
	 $(CXX) $(CXXFLAGS) -c naiveRegex.cpp -o naiveRegex.o
	 
.PHONY: clean
clean:
	rm -r *.o