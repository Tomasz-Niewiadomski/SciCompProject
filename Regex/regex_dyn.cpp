#include <iostream>
#include <vector>
#include <string>


using namespace std;


typedef vector<vector<bool> > bmatrix;
typedef vector<bool> bvector;

bool match(string text, string pattern)
{
  bmatrix T(text.length() + 1, bvector(pattern.length() + 1));            // Allocates space for MX

  T[0][0] = true;

  for (int i = 1; i < T[0].size(); i++){
    if (pattern[i-1] == '*'){

      T[0][i] = T[0][i-2];
    }
  }

  for (int i = 1; i < T.size(); i++){
    for (int j = 1; j < T[0].size(); j++){
      if (pattern[j-1] == '.' or pattern[j-1] == text[i-1]){
        T[i][j] = T[i-1][j-1];
      }
      else if (pattern[j-1] == '*'){
        T[i][j] = T[i][j-2];
        if (pattern[j-2] == '.' or pattern[j-2] == text[i-1]){
          T[i][j] = T[i][j] or T[i-1][j];
        }
      }
      else{
        T[i][j] = false;
      }
    }
  }
  return T[text.length()][pattern.length()];
}

int main()
{
  string text = "This sentence is interesting!";
  string pattern = ".*sant.*";

  int result_int = match(text, pattern);
  string result_str;

  switch (result_int){
    case 0:
      result_str = "False";
      break;
    case 1:
      result_str = "True";
      break;
  }


  cout << "Text provided: " << text << endl
       << "Pattern provided: " << pattern << endl
       << "Match? : " << result_str << endl;

}
