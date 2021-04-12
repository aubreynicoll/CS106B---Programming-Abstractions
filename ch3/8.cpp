/* Exercise 3.8
 *
 * This program implements a version of removeCharacters that operates in place.
 * */

#include <iostream>
#include <string>

using namespace std;

void removeCharacters(string &s, string toRemove);

int main() {
  cout << "This program removes characters from a string." << endl;

  string s, toRemove;

  cout << "Enter a string: ";
  getline(cin, s);

  cout << "Enter characters to remove: ";
  getline(cin, toRemove);

  removeCharacters(s, toRemove);

  cout << s << endl;

  return 0;
}

void removeCharacters(string &s, string toRemove) {
  for (int i = 0; i < toRemove.length(); i++) {
    int index = 0;
    while ((index = s.find(toRemove[i], index)) != string::npos) {
      s.erase(index, 1);
    }
  }
}