#include "naiveRegex.hpp"
#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <cstring>

int main() {

	
	
	std::cout << "Welcome to the naive Regex search and match program by G21!" << std::endl;

	std::cout << "Press 1 to search, 0 to match" << std::endl;
	bool inp;
	std::cin >> inp;

	std::cout << std::endl;
	std::cout << "Insert your pattern:" << std::endl;
	std::string pattern;
	std::cin >> pattern;

	if (inp == 1) {
		pattern=".*"+pattern+".*";
	}
	std::cout << std::endl;

	std::cout << "Searching your pattern in our test library." << std::endl;
	std::string text;
	std::string filename = "library.txt";
	std::ifstream in(filename.c_str());
	std::getline(in, text, std::string::traits_type::to_char_type(
		std::string::traits_type::eof()));

	naiveRegex regex = naiveRegex(pattern);
	std::cout << std::endl;

	std::cout << "Recursive algorithm says: ";

	auto start = std::chrono::high_resolution_clock::now(); // starting time

	if (regex.naiveMatch(text) == true)
		std::cout << "There is a match! :)" << std::endl;
	else
		std::cout << "No match unfortunately :(" << std::endl;

	auto end = std::chrono::high_resolution_clock::now(); //ending time
	std::chrono::duration<double> diff = std::chrono::duration_cast<std::chrono::duration<double>>(end - start); //duration
	std::cout << std::endl;
	std::cout << "Time: " << diff.count() << " s" << std::endl; // time taken
	
	std::cout << std::endl;
	std::cout << "Dynamical programming algorithm: ";

	auto start1 = std::chrono::high_resolution_clock::now(); // starting time

	if (regex.dynamicMatch(text)==true)
		std::cout << "There is a match! :)" << std::endl;
	else
		std::cout << "No match unfortunately :(" << std::endl;

	auto end1 = std::chrono::high_resolution_clock::now(); //ending time
	std::chrono::duration<double> diff1 = std::chrono::duration_cast<std::chrono::duration<double>>(end1 - start1); //duration
	std::cout << std::endl;
	std::cout << "Time: " << diff1.count() << " s" << std::endl; // time taken
	std::cout << std::endl;


	std::cout << "Thank you for using our Regex engine!" << std::endl;
return 0;
}