#include "parser.h"
#include "Ast.h"
#include "AstAlternative.h"
#include "Atom.h"
#include "SpecialAst.h"
#include <string>
#include <vector>
#include <memory>
#include <iostream>

typedef std::shared_ptr<Ast> AstPointer;


AstPointer parser(std::string input) {

	int k = findOr(input);

	AstPointer tree;

	// The string contains an 'or' operator.
	if (k > 0) 
	{
		std::string string1 = input.substr(0, k);
		std::string string2 = input.substr(k + 1);


		tree = AstPointer(new AstAlternative(parser(string1), parser(string2)));
	}
	// The string doesn't contain an 'or' operator.
	else
	{
		tree = AstPointer(new Ast(input));

		int max = static_cast<int>(input.length());

		// Iterates over the string.
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

			if (input[i] == '[') {

				int k = findSquaredClosure(input, i);

				std::string substr = input.substr(i + 1, k - i - 1);

				AstPointer clas(new SpecialAst(specialAstAssembly(substr)));

				tree->addSubExpr(clas);

				if ((k + 1 < max) and isAQuantifier(input[k + 1])) {
					k = k + 1;
					clas->quantifier = input[k];
				}


				i = k + 1;
				continue;
			}
			
			if (input[i] == '.') {

				SpecialAst dot;

				dot.setRanges('\n', '\n', false);

				if ((i + 1 < max) and (isAQuantifier(input[i + 1]))) {
					i = i + 1;
					dot.quantifier = input[i];
				}

				AstPointer add(new SpecialAst(dot));

				tree->addSubExpr(add);

				i = i + 1;

				continue;
			}

			if (input[i] == '\\')
			{
				if ((i + 1 < max) and (isReserved(input[i + 1])))
				{
					i = i + 1;

					std::string corr = correspondingString(input[i]);

					AstPointer clas(new SpecialAst(specialAstAssembly(corr)));


					tree->addSubExpr(clas);

					if ((i + 1 < max) and isAQuantifier(input[i + 1])) {
						i = i + 1;
						clas->quantifier = input[i];
					}
					i = i + 1;
					continue;
				}
				
				i = i + 1;
			}
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

SpecialAst specialAstAssembly(std::string& input) {

	SpecialAst ret;

	int max = static_cast<int>(input.length());

	bool notNeg = true;

	for (int i = 0; i < max; ) {

		if (input[i] == '^') {
			notNeg = false;

			i = i + 1;

			continue;
		}

		if ((input[i] == '\\') and (i + 1 < max) and (isReserved(input[i + 1]))) {

			std::string corr = correspondingString(input[i + 1]);

			SpecialAst ast = specialAstAssembly(corr);

			for (auto& element : ast.ranges) {
				ret.setRanges(element);
			}

			i = i + 2;

			notNeg = true;

			continue;

		}

		if ((i + 2 < max) and (input[i + 1] == '-'))
		{
			ret.setRanges(input[i], input[i + 2], notNeg);

			notNeg = true;

			i = i + 3;

			continue;
		}

		ret.setRanges(input[i], input[i], notNeg);

		notNeg = true;

		i = i + 1;
	}
	return ret;
}

/// \related SpecialAst
/// Given the special character, returns the string corresponding to the range of this special character.
std::string correspondingString(char c)
{
	switch (c)
	{
	case'd': // digits
		return "0-9";

	case 'D':
		return "^"+correspondingString('d');

	case 'l': // lower case letter
		return "a-z";

	case 'L':
		return "^" + correspondingString('l');

	case 'u': // upper case letter
		return "A-Z";

	case 'U':
		return "^" + correspondingString('u');

	case 'w': // alphanumeric charact
		return correspondingString('d')+ correspondingString('l') + correspondingString('u') + "_";

	case 'W':
		return correspondingString('D') + correspondingString('L') + correspondingString('U') + "^" + "_";

	default:
		return "";

	}
}
/// \related AstAlternative
/// Find the first occurence of the 'or' operator in a string. Default value is -1 if no occurence is found.
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
/// \related Ast
/// Finds the position of the closing parenthesis of a subexpression.
int findClosure(std::string& input, int start) {

	int i;

	int found = -1;

	int length = static_cast<int>(input.length());

	if (start + 1 > length)
	{
		std::cerr << "The Regex is badly written (find closure)" << std::endl;
	}

	for (i = start + 1; i < length; i = i + 1) {

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
/// \related Range
/// Finds the position of the closing square bracket of a subexpression.
int findSquaredClosure(std::string& input, int start) {

	int i;

	int found = -1;

	int length = static_cast<int>(input.length());

	if (start + 1 > length)
	{
		std::cerr << "The Regex is badly written (find closure)" << std::endl;
	}

	for (i = start + 1; i < length; i = i + 1) {

		if (input[i] == ']')
			found = found - 1;

		if (input[i] == '[')
			found = found + 1;

		if (input[i] == '\\')
			i = i + 1;


		if (found == 0)
			break;

	}
	return i;
}

/// \related Ast
/// Checks if a character is one of: "+", "*", "?".
bool isAQuantifier(char c) {
	return ((c == '+') or (c == '*') or (c == '?'));
}

/// \related SpecialAst
/// Checks if a character is one of: "d", "D", "l", "L", "u", "U", "w" , "W".
bool isReserved(char c)
{
	switch (c) 
	{
	case'd': // digits
		return true;

	case 'D':
		return true;

	case 'l': // lower case letter
		return true;

	case 'L':
		return true;

	case 'u': // upper case letter
		return true;

	case 'U':
		return true;

	case 'w': // alphanumeric charact
		return true;

	case 'W':
		return true;

	default:
		return false;

	}
}
