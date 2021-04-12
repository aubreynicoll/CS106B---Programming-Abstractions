/* Exercise 3.9
 *
 * This program takes a string and removes all duplicate consecutive characters.
 * */

#include <iostream>
#include <string>

using namespace std;

string removeConsecutiveChars(string s);

int main() {
  cout << "This program removes consecutive duplicates in a string." << endl;

  string s;
  cout << "Enter a string: ";
  getline(cin, s);

  cout << removeConsecutiveChars(s) << endl;

  return 0;
}

string removeConsecutiveChars(string s) {
  string postOp;
  char prev = '\0';

  for (int i = 0; i < s.length(); i++) {
    if (s[i] != prev) {
      postOp += s[i];
      prev = s[i];
    }
  }

  return postOp;
}