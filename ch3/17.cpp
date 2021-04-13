/* Exercise 3.17
 *
 * This program implements Caesar's cipher, shifting alphabetical characters by
 * a fixed amount.
 * */

#include <cctype>
#include <iostream>
#include <string>

#include "simpio.h"

using namespace std;

string encode(string s, int shift);

int main() {
  cout << "This program encrypts a message poorly." << endl;

  while (true) {
    cout << "Enter a message: ";

    string s;
    getline(cin, s);

    if (s == "") break;

    int shift = getInteger("Enter an offset value: ");

    cout << encode(s, shift) << endl;
  }

  return 0;
}

string encode(string s, int shift) {
  for (int i = 0; i < s.length(); i++) {
    if (shift < 0) shift = 26 + shift % 26;

    if (s[i] >= 'a' && s[i] <= 'z') {
      s[i] = (s[i] - 'a' + shift) % 26 + 'a';
    } else if (s[i] >= 'A' && s[i] <= 'Z') {
      s[i] = (s[i] - 'A' + shift) % 26 + 'A';
    }
  }
  return s;
}