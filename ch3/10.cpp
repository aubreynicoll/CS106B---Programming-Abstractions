/* Exercise 3.10
 *
 * This program implements the function replaceAll().
 * */

#include <iostream>
#include <string>

using namespace std;

string replaceAll(string s, char c1, char c2);
string replaceAll(string s1, char c, string s2);
string replaceAll(string s1, string s2, string s3);

int main() {
  cout << "This program takes a string and two characters, replacing each "
          "occurrence of the first character with the second inside the string."
       << endl;

  cout << replaceAll("poke the pokemon in the wild.", "poke", "pika!") << endl;
  return 0;
}

string replaceAll(string s, char c1, char c2) {
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == c1) s[i] = c2;
  }
  return s;
}

string replaceAll(string s1, char c, string s2) {
  string newString;
  for (int i = 0; i < s1.length(); i++) {
    if (s1[i] == c) {
      newString += s2;
    } else {
      newString += s1[i];
    }
  }
  return newString;
}

string replaceAll(string s1, string s2, string s3) {
  string newString;
  for (int i = 0; i < s1.length(); i++) {
    if (s1.substr(i, s2.length()) == s2) {
      newString += s3;
      i += s2.length() - 1;
    } else {
      newString += s1[i];
    }
  }
  return newString;
}