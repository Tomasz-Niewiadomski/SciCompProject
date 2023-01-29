#include "Ast.h"
#include "AstAlternative.h"
#include "Atom.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

typedef std::shared_ptr<Ast> AstPointer;

int findOr(std::string & input);

int findClosure(std::string & input, int start);

bool isAQuantifier(char c);


AstPointer parser(std::string input) {

	int k = findOr(input);

	AstPointer tree;

	if (k > 0)
	{
		std::string string1 = input.substr(0, k);
		std::string string2 = input.substr(k + 1);

		
		tree = AstPointer(new AstAlternative(parser(string1), parser(string2)));
	}
	else
	{
		tree = AstPointer(new Ast(input));

		int max = static_cast<int>(input.length());

		for (int i = 0; i < max; )
		{
			if (input[i] == '(')
			{
				int k = findClosure(input, i);

				std::string substr = input.substr(i + 1, k - i - 1);

				AstPointer iter(new Ast);
				iter = parser(substr);
				tree->addSubExpr(iter);

				if ((k + 1 < max) and isAQuantifier(input[k + 1])) {
					k = k + 1;
					iter->quantifier = input[k];
				}


				i = k + 1;

				continue;
			}

			if (input[i] == '\\')
				i = i + 1;

			AstPointer car(new Atom(input[i]));

			if ((i + 1 < max) and (isAQuantifier(input[i + 1]))) {
				i = i + 1;
				car->quantifier = input[i];
			}

			tree->addSubExpr(car);

			i = i + 1;

		}

	}

	return tree;
}

int main() {

	std::string expr = "a+b|bc(e|f)?";

	parser(expr)->whoAmI();

	return 0;
}

int findOr(std::string& input) {
	int pos = -1;

	int length = static_cast<int>(input.length());

	for (int i = 0; i < length;) {
		if (input[i] == '(') {
			i = findClosure(input, i) + 1;
			continue;
		}
		if (input[i] == '\\') {
			i = i + 2;
			continue;
		}
		if (input[i] == '|') {
			pos = i;
			break;
		}
		i = i + 1;
	}


	return pos;
}

int findClosure(std::string& input, int start) {

	int i;

	int found=-1;

	int length = static_cast<int>(input.length());

	if (start + 1 > length)
	{
		std::cerr << "The Regex is badly written (find closure)" << std::endl;
	}

	for (i = start+1; i < length;i=i+1) {
		
		if (input[i] == '(') 
			found = found - 1;

		if (input[i] == ')')
			found = found + 1;

		if (input[i] == '\\')
			i = i + 1;
		

		if (found == 0)
			break;

	}
	return i;
}

bool isAQuantifier(char c) {
	return ((c == '+') or (c == '*') or (c == '?'));
}