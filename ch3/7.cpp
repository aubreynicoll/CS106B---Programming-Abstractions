/* Exercise 3.7
 *
 * This program implements the removeCharacters function, which removes from the
 * first string all the characters contained in the second string.
 * */

#include <iostream>
#include <string>

using namespace std;

string removeCharacters(string s, string toRemove);

int main() {
  cout << "This program removes characters from a string." << endl;

  string s, toRemove;

  cout << "Enter a string: ";
  getline(cin, s);

  cout << "Enter characters to remove: ";
  getline(cin, toRemove);

  cout << removeCharacters(s, toRemove) << endl;

  return 0;
}

string removeCharacters(string s, string toRemove) {
  string censored;
  for (int i = 0; i < s.length(); i++) {
    if (toRemove.find(s[i]) == string::npos) censored += s[i];
  }
  return censored;
}