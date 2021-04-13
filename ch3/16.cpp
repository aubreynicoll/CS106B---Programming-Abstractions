/* Exercise 3.16
 *
 * This program takes an English word and converts in to Obenglobish.
 * */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string toOben(string word);
bool isVowel(char c);

int main() {
  cout << "This program converts words to Obenglobish." << endl;

  while (true) {
    cout << "Enter an English word: ";

    string s;
    getline(cin, s);

    cout << s << " -> " << toOben(s) << endl;
  }

  return 0;
}

string toOben(string s) {
  string obenglobish;
  char prev = '\0';
  bool hasCapital = s[0] >= 'A' && s[0] <= 'Z';

  if (hasCapital) s[0] = tolower(s[0]);
  for (int i = 0; i < s.length(); i++) {
    if (toupper(s[i]) == 'E' && i == s.length() - 1) {
      obenglobish += s[i];
    } else if (isVowel(s[i]) && !isVowel(prev)) {
      obenglobish = obenglobish + "ob" + s[i];
    } else {
      obenglobish += s[i];
    }
    prev = s[i];
  }
  if (hasCapital) obenglobish[0] = toupper(obenglobish[0]);
  return obenglobish;
}

bool isVowel(char c) {
  c = toupper(c);

  switch (c) {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
      return true;
    default:
      return false;
  }
}