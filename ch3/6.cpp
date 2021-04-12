/* Exercise 3.6
 *
 * This program prompts the user for a string and returns an acronym
 * */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string toAcronym(string str);

int main() {
  cout << "This program returns an acronym." << endl;

  string s;

  cout << "Enter a string: ";
  getline(cin, s);

  cout << toAcronym(s) << endl;

  return 0;
}

string toAcronym(string str) {
  string acronym;
  bool isFirstLetter = true;

  for (int i = 0; i < str.length(); i++) {
    if (isFirstLetter && isalpha(str[i])) {
      acronym += toupper(str[i]);
      isFirstLetter = false;
    } else if (!isFirstLetter && !isalpha(str[i])) {
      isFirstLetter = true;
    }
  }

  return acronym;
}