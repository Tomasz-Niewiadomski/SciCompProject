CXX = g++ -std=c++17
CXXFLAGS = -Wall -Werror

parser : parser.o
	$(CXX) $(CXXFLAGS) -O -o parser parser.o Atom.o AstAlternative.o Ast.o

parser.o: parser.cpp Ast.o AstAlternative.o Atom.o AstAlternative.o Ast.o
	$(CXX) $(CXXFLAGS) -c parser.cpp -o parser.o
		
Atom.o: Ast.cpp Ast.h Atom.cpp Atom.h
	$(CXX) $(CXXFLAGS) -c Atom.cpp -o Atom.o

AstAlternative.o: Ast.cpp Ast.h AstAlternative.cpp AstAlternative.h
	$(CXX) $(CXXFLAGS) -c AstAlternative.cpp -o AstAlternative.o

Ast.o: Ast.cpp Ast.h
	$(CXX) $(CXXFLAGS) -c Ast.cpp -o Ast.o
	

.PHONY: clean
clean:
	rm -r *.o