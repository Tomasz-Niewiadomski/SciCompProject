// Group 21: Basak Atalay, Tomasz Niewiadomski, Yunus Emre Sunay, Paolo Villani
#define PCRE2_STATIC
#define PCRE2_CODE_UNIT_WIDTH 8

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
#include <pcre2.h>

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
	cout << "-----------------------------------------------+----------------------+---------------------"<<endl;
	cout << "Pattern                                        |   pcre2              |  Match              "<<endl;
	cout << "-----------------------------------------------+----------------------+---------------------"<<endl;
}

char* stringtochar (string string_input)
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


void pcre_regex_engine(string &match_res, string &pattern_string, string &regex_input, double &regex_time)
{
	
	pcre2_code *re;
	pcre2_compile_context *comp_ctx;
    pcre2_match_data *match_data;
    pcre2_match_context *match_ctx;
    int err_code;
    PCRE2_SIZE err_offset;
    pcre2_jit_stack *stack = NULL;
    PCRE2_SIZE *ovector;
   
    int len;
    int found = 0;
	comp_ctx = pcre2_compile_context_create(NULL);
	pcre2_set_newline(comp_ctx, PCRE2_NEWLINE_ANYCRLF);
	char* pattern = stringtochar (regex_input);
	char* ptr = stringtochar (pattern_string);
	len = strlen(ptr);

	auto start = chrono::high_resolution_clock::now(); // starting time
	
	re = pcre2_compile(
        (PCRE2_SPTR8) pattern,    /* the pattern */
        PCRE2_ZERO_TERMINATED,    /* length */
        PCRE2_MULTILINE,    /* options */
        &err_code,        /* for error code */
        &err_offset,        /* for error offset */
        comp_ctx);        /* use default character tables */
	
	pcre2_compile_context_free(comp_ctx);	
	match_ctx = pcre2_match_context_create(NULL);
	match_data = pcre2_match_data_create(32, NULL);
    ovector = pcre2_get_ovector_pointer(match_data);

	err_code = pcre2_match(
                    re,            /* the compiled pattern */
                    (PCRE2_SPTR8) ptr,    /* the subject string */
                    len,            /* the length of the subject */
                    0,            /* start at offset 0 in the subject */
                    0,            /* default options */
                    match_data,        /* match data */
                    match_ctx);        /* match context */
					
	if( err_code >= 0)  match_res = "ok";
	auto end = chrono::high_resolution_clock::now(); //ending time
    chrono::duration<double>diff = chrono::duration_cast<chrono::duration<double>>(end - start); //duration
	
	regex_time = diff.count()* 1000;
	cout <<  setw(45) << pattern;	
	cout <<  setw(20) << regex_time ; 
	cout << setw(20) << match_res << endl; 
	
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

	pcre_regex_engine	(match_res, pattern_string, regex_test_inputs[no_test_pattern], regex_time);

	} 
	
    return 0;
}