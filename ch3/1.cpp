/* Exercise 3.1
 *
 * This program implements the string function endsWith(str, suffix).
 *
 * The function returns true if the supplied string ends with the suffix.
 * */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool endsWith(string str, string suffix);
bool endsWith(string str, char suffix);

int main() {
  cout << "This program checks to see if one string is the suffix of another."
       << endl;

  string str;
  string suffix;

  cout << "Enter a string: ";
  getline(cin, str);

  cout << "Enter a suffix: ";
  getline(cin, suffix);

  if (endsWith(str, suffix)) {
    cout << "Yes! It is a suffix!" << endl;
  } else {
    cout << "No! It is NOT a suffix!" << endl;
  }

  return 0;
}

bool endsWith(string str, string suffix) {
  if (str.length() < suffix.length()) return false;
  for (int strPtr = str.length() - 1, suffixPtr = suffix.length() - 1;
       suffixPtr >= 0; strPtr--, suffixPtr--) {
    if (str[strPtr] != suffix[suffixPtr]) return false;
  }
  return true;
}

bool endsWith(string str, char suffix) {
  return str.length() > 0 && str[str.length() - 1] == suffix;
}