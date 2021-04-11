/* Exercise 3.4
 *
 * This program implements the function capitalize(), which capitalizes the
 * first character in a string if it is a letter, and minescules the rest.
 *
 * Not a very complete version of what the function could be, but it is what the
 * book asks for.
 * */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string capitalize(string str);

int main() {
  cout << capitalize("BOOLEAN") << endl;
  cout << capitalize("boolean") << endl;
  return 0;
}

string capitalize(string str) {
  str[0] = toupper(str[0]);
  for (int i = 1; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
  return str;
}