/*
 * naiveRegex.hpp
 *
 *  Created on: Jan 17, 2023
 *      Author: villani
 */

#ifndef NAIVEREGEX_HPP_
#define NAIVEREGEX_HPP_

#include <vector>
#include <string>

class naiveRegex {
protected:

	std::string expr;

public:

	naiveRegex();

	naiveRegex(std::string s);

	bool naiveMatch(std::string const& match, int i = 0, int j = 0);
	// naive recursive matching
		// currently supports only [.] and [*] no other special characters


	bool dynamicMatch(std::string const& match);







};



#endif /* NAIVEREGEX_HPP_ */
