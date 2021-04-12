/* String Censor
 *
 * This program asks for two strings. It prints the first string with all the
 * characters from the second string removed.
 * */

#include <iostream>
#include <string>

using namespace std;

string getLine(void);
string stringCensor1(string s1, string s2);
int stringCensor2(string &s1, string s2);

int main() {
  cout << "Enter a string: ";
  string text = getLine();

  cout << "Enter letters to remove: ";
  string censor = getLine();

  stringCensor2(text, censor);
  cout << text << endl;

  return 0;
}

string getLine() {
  string s;
  getline(cin, s);
  return s;
}

string stringCensor1(string s1, string s2) {
  string censoredString;
  for (int i = 0; i < s1.length(); i++) {
    if (s2.find(s1[i]) == string::npos) censoredString += s1[i];
  }
  return censoredString;
}

int stringCensor2(string &s1, string s2) {
  for (int i = 0; i < s2.length(); i++) {
    int index = 0;
    while ((index = s1.find(s2[i], index)) != string::npos) {
      s1.erase(index, 1);
    }
  }
  return 0;
}
