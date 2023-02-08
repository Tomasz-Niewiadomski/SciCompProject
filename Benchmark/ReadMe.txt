In this benchmark, following regex engines are tested;

-TRE
https://github.com/laurikari/tre/
-Boost regex engine
https://www.boost.org/users/download/
-C++ standart library 
-RE2 - Google
https://github.com/google/re2
-PCRE2
https://github.com/PCRE2Project/pcre2
-Oniguruma
https://github.com/kkos/oniguruma

Input file: "mtent12.txt"
-3.5 million words
-750000 lines
-20 million document length(character and whitespace character)

Input regex characters: "regex_search_input.txt"
-Twain
-[a-z]shing
-Huck[a-zA-Z]+|Saw[a-zA-Z]+
-\b\w+nn\b
-[a-q][^u-z]{13}x
-Tom|Sawyer|Huckleberry|Finn
-.{0,2}(Tom|Sawyer|Huckleberry|Finn)
-emre
