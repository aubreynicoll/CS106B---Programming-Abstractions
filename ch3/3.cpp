/* Exercise 3.3
 *
 * This program includes an implementation of the common string function
 * substring, which returns a segment of a string.
 * */

#include <cctype>
#include <iostream>
#include <string>

#include "error.h"

using namespace std;

string substring(string str, int pos);
string substring(string str, int pos, int numChars);

int main() {
  string s1 = "bo diddly bo diddly bo";
  string s2 = "I got 99 problems but a";

  cout << substring(s1, 5) << endl;
  cout << substring(s2, 0, 10) << endl;

  return 0;
}

string substring(string str, int pos) {
  if (pos >= str.length() || pos < 0) error("Position is out of bounds.");

  string sub;
  for (int i = pos; i < str.length(); i++) {
    sub += str[i];
  }

  return sub;
}

string substring(string str, int pos, int numChars) {
  if (pos >= str.length() || pos < 0) error("Position is out of bounds.");

  string sub;
  for (int i = pos; i < str.length() && i < pos + numChars; i++) {
    sub += str[i];
  }

  return sub;
}