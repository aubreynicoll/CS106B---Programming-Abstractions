/* Exercise 3.12
 *
 * This program implements the function createRegularPlural, which pluralizes
 * words correctly based on English rules.
 * */

#include <iostream>
#include <string>

using namespace std;

string createRegularPlural(string word);

int main() {
  cout << "This program pluralizes words." << endl;

  string word;
  cout << "Enter a word: ";
  getline(cin, word);

  cout << createRegularPlural(word) << endl;

  return 0;
}

string createRegularPlural(string word) {
  string last, last2;

  last = word.substr(word.length() - 1);
  last2 = word.substr(word.length() - 2);

  if (last == "s" || last == "x" || last == "z" || last2 == "ch" ||
      last2 == "sh") {
    word += "es";
  } else if (last == "y") {
    switch (last2[0]) {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
        word += 's';
        break;
      default:
        word[word.length() - 1] = 'i';
        word += "es";
        break;
    }
  } else {
    word += "s";
  }

  return word;
}