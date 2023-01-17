/*
 * naiveRegex.hpp
 *
 *  Created on: Jan 17, 2023
 *      Author: villani
 */

#include "naiveRegex.hpp"
#include <vector>
#include <string>


naiveRegex::naiveRegex(){

	expr=".*";

};

naiveRegex::naiveRegex(std::string s){

	expr=s;

};

bool naiveRegex::naiveMatch(std::string const& match, int i=0, int j=0){
	// naive recursive matching
	// currently supports only [.] and [*] no other special characters

	if (i>=match.length()){
		if (j>=expr.length())
			return true;
		return false;
	}

	if (j>=expr.length())
				return false;

	if ((j+1 < expr.length()) and (expr[j+1]=='*'))
		return (naiveMatch(match,i, j+2) or (((expr[j]=='.') or (expr[j]==match[i])) and naiveMatch(match,i+1,j)));

	if ((expr[j]=='.') or (expr[j]==match[i])){

		return naiveMatch(match, i+1, j+1);
	}


	return naiveMatch(match, i, j+1);
};

bool naiveRegex::dynamicMatch(std::string const& match){

	bool res=false;

	for (int i=0; i <match.length();  i++ ){
		for (int j=0; ((j< expr.length()) and (res==false)); ){

		}
	}


	return res;
};










