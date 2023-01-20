/*
 * naiveRegex.hpp
 *
 *  Created on: Jan 17, 2023
 *      Author: villani
 */

#include "naiveRegex.hpp"
#include <vector>
#include <string>

typedef std::vector<std::vector<bool> > bmatrix;
typedef std::vector<bool> bvector;

naiveRegex::naiveRegex() {

	expr = ".*";

};

naiveRegex::naiveRegex(std::string s) {

	expr = s;

};

bool naiveRegex::naiveMatch(std::string const& match, int i, int j) {
	// naive recursive matching
	// currently supports only [.] and [*] no other special characters
	// top -down 
	if ((i >= (int) match.length()) and (j >= (int) expr.length()))
			return true;

	if (j >= (int)expr.length())
		return false;

	bool corr = ((i < (int)match.length()) and ((expr[j] == '.') or (expr[j] == match[i])));
	if ((j + 1 < (int) expr.length()) and (expr[j + 1] == '*'))
		return (naiveMatch(match, i, j + 2) 
			or (corr and naiveMatch(match, i + 1, j)));

	if (corr) {
		return naiveMatch(match, i + 1, j + 1);
	}


	return false;
};

bool naiveRegex::dynamicMatch(std::string const& text) {
	// dynamical programming matching
	// top -down 

	bmatrix T(text.length() + 1, bvector(expr.length() + 1));            // Allocates space for MX

	T[0][0] = true;

	for (int i = 1; i < (int) T[0].size(); i++) {
		if (expr[i - 1] == '*') {

			T[0][i] = T[0][i - 2];
		}
	}

	for (int i = 1; i < (int) T.size(); i++) {
		for (int j = 1; j < (int) T[0].size(); j++) {
			if (expr[j - 1] == '.' or expr[j - 1] == text[i - 1]) {
				T[i][j] = T[i - 1][j - 1];
			}
			else if (expr[j - 1] == '*') {
				T[i][j] = T[i][j - 2];
				if (expr[j - 2] == '.' or expr[j - 2] == text[i - 1]) {
					T[i][j] = T[i][j] or T[i - 1][j];
				}
			}
			else {
				T[i][j] = false;
			}
		}
	}
	return T[text.length()][expr.length()];
};

