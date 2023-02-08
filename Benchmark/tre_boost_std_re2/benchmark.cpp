// Group 21: Basak Atalay, Tomasz Niewiadomski, Yunus Emre Sunay, Paolo Villani

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <chrono>
#include <string>
#include <cstring>
#include <cstring>
#include <complex>
#include <regex>
#include <iomanip>
#include <map>
#include <tre/tre.h>
#include <boost/regex.hpp>
#include <regex>
#include <re2/re2.h>


using namespace std;

void read_regex_input_file (string &regex_input_file, vector<string> &regex_test_inputs )
{
	string temp;	
	string pattern_string;
	
	ifstream input;	
	input.open(regex_input_file);	
	
	
	while (true) {
		input >> temp;
		regex_test_inputs.push_back(temp);
		
		if(input.eof()) break;

	}
	input.close();
	
	return ;
}

void write_results_table_head()
{
	cout << "-----------------------------------------------+----------------------+---------------------+---------------------+---------------------+---------------------"<<endl;
	cout << "Pattern                                        |   Tre                |  Booost_regex       |  C++ Standart       |  RE2-Google         |  Match              "<<endl;
	cout << "-----------------------------------------------+----------------------+---------------------+---------------------+---------------------+---------------------"<<endl;
}

const char* stringtochar (string string_input)
{
    // create a new array of chars to copy to (+1 for a null terminator)
    char* char_array = new char[string_input.length() + 1];
   
    // make sure that the new string is null terminated
    char_array[string_input.length()] = '\0';
     
    for (int i = 0; i < string_input.length(); i++) {
        char_array[i] = string_input[i];
    }
 
    //std::cout << char_array;
	return char_array;

}

string read_input_file (string input_file )
{
	string temp;	
	string pattern_string;
	
	ifstream input;	
	input.open(input_file);	
	
	while (true) 
	{
		getline(input,temp);
		pattern_string.append(temp);
		if(input.eof()) break;
	}
	
	input.close();
	cout << "Input file is " << input_file << " and has " << pattern_string.length() << " characters" << endl ;
	write_results_table_head();
	
	return pattern_string;
}

void tre_regex_engine(string &match_res, string &pattern_string, string &regex_input, double &regex_time)
{
	regex_t regex;
	regmatch_t match[1];
	
	const char* pattern = stringtochar (regex_input);

	const char* ptr = stringtochar (pattern_string);
	int len = strlen(ptr);
	
 	auto start = chrono::high_resolution_clock::now(); // starting time
	
	int err_val = tre_regcomp(&regex, pattern, REG_EXTENDED | REG_NEWLINE);

	if( tre_regnexec(&regex, ptr, len, 1,  match, 0)==0)  match_res = "ok";

	auto end = chrono::high_resolution_clock::now(); //ending time
    chrono::duration<double>diff = chrono::duration_cast<chrono::duration<double>>(end - start); //duration
	
	regex_time = diff.count()* 1000;	
	cout <<  setw(20) << regex_time ; 
}

void boost_regex_engine(string &match_res, string &pattern_string, string &regex_input, double &regex_time)
{
	boost::smatch what;
	
 	auto start = chrono::high_resolution_clock::now(); // starting time

	boost::regex search_file(regex_input);
	if ( boost::regex_search(pattern_string, what, search_file))  match_res = "ok" ;

	auto end = chrono::high_resolution_clock::now(); //ending time
    chrono::duration<double>diff = chrono::duration_cast<chrono::duration<double>>(end - start); //duration
	
	regex_time = diff.count()* 1000;	
	cout <<  setw(20) << regex_time ; 
}

void std_regex_engine(string &match_res, string &pattern_string, string &regex_input, double &regex_time)
{
	smatch m;
	
 	auto start = chrono::high_resolution_clock::now(); // starting time

	regex search_file  (regex_input);
	if ( regex_search (pattern_string,m,search_file))  match_res = "ok" ;

	auto end = chrono::high_resolution_clock::now(); //ending time
    chrono::duration<double>diff = chrono::duration_cast<chrono::duration<double>>(end - start); //duration
	
	regex_time = diff.count()* 1000;	
	cout <<  setw(20) << regex_time ; 
}

void re2_regex_engine(string &match_res, string &pattern_string, string &regex_input, double &regex_time)
{

 	auto start = chrono::high_resolution_clock::now(); // starting time

	re2::StringPiece string_search(pattern_string);
	re2::RE2 search_file(regex_input);
	if ( re2::RE2::PartialMatch(string_search, search_file))  match_res = "ok" ;

	auto end = chrono::high_resolution_clock::now(); //ending time
    chrono::duration<double>diff = chrono::duration_cast<chrono::duration<double>>(end - start); //duration
	
	regex_time = diff.count()* 1000;	
	cout <<  setw(20) << regex_time ; 
}


int main(int argc, char **argv)
{
	string input_file = "mtent12.txt"; //gets filename
	string regex_input_file = "regex_search_input.txt";
	//string pattern = "[a-z]shing";
	
	vector<string>  regex_test_inputs;

	string pattern_string = read_input_file(input_file);
	read_regex_input_file(regex_input_file , regex_test_inputs);
	
	double regex_time;
	
 	for (int no_test_pattern = 0;  
			no_test_pattern <= regex_test_inputs.size()-1;
			no_test_pattern++)
	{
	
	string match_res = "not ok";
	
	cout <<  setw(45) << regex_test_inputs[no_test_pattern];
	
	tre_regex_engine	(match_res, pattern_string, regex_test_inputs[no_test_pattern], regex_time);
	boost_regex_engine	(match_res, pattern_string, regex_test_inputs[no_test_pattern], regex_time);
	std_regex_engine	(match_res, pattern_string, regex_test_inputs[no_test_pattern], regex_time);
	re2_regex_engine	(match_res, pattern_string, regex_test_inputs[no_test_pattern], regex_time);
	
	cout << setw(20) << match_res << endl;
	
	} 
	
    return 0;
}