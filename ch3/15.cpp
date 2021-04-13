/* Exercise 3.15
 *
 * This program converts English to Pig Latin.
 * */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string stringToPigLatin(string s);
string wordToPigLatin(string word);
bool isVowel(char c);

int main() {
  cout << "This program converts English to Pig Latin." << endl;

  string s;

  cout << "Enter a string: ";
  getline(cin, s);

  cout << stringToPigLatin(s) << endl;

  return 0;
}

string stringToPigLatin(string s) {
  string pigLatin, token;

  for (int i = 0; i < s.length(); i++) {
    if (isalpha(s[i]) || ispunct(s[i]) && isalpha(s[i + 1])) {
      token += s[i];
    } else {
      pigLatin += wordToPigLatin(token);
      token = "";
      pigLatin += s[i];
    }
  }
  pigLatin += wordToPigLatin(token);
  return pigLatin;
}

string wordToPigLatin(string word) {
  int i = -1;
  while (!isVowel(word[++i]))
    if (i == word.length()) break;

  bool hasVowel = i != word.length();
  bool hasCapital = word[0] >= 'A' && word[0] <= 'Z';

  if (hasVowel && i == 0) {
    word += "way";
  } else if (hasVowel) {
    if (hasCapital) word[0] = tolower(word[0]);
    word = word.substr(i) + word.substr(0, i) + "ay";
    if (hasCapital) word[0] = toupper(word[0]);
  }

  return word;
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