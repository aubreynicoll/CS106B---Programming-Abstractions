/* Exercise 3.5
 *
 * This program calculates Scrabble scores.
 * */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

int getScrabbleScore(string word);
int getLetterScore(char letter);

int main() {
  cout << "This program calculates Scrabble scores." << endl;
  cout << "Enter a word: (spacebar for blank tiles) ";

  string word;
  getline(cin, word);

  cout << getScrabbleScore(word) << " points." << endl;
  return 0;
}

int getScrabbleScore(string word) {
  int score = 0;
  for (int i = 0; i < word.length(); i++) {
    score += getLetterScore(toupper(word[i]));
  }
  return score;
}

int getLetterScore(char letter) {
  switch (letter) {
    case 'A':
    case 'E':
    case 'I':
    case 'L':
    case 'N':
    case 'O':
    case 'R':
    case 'S':
    case 'T':
    case 'U':
      return 1;
    case 'D':
    case 'G':
      return 2;
    case 'B':
    case 'C':
    case 'M':
    case 'P':
      return 3;
    case 'F':
    case 'H':
    case 'V':
    case 'W':
    case 'Y':
      return 4;
    case 'K':
      return 5;
    case 'J':
    case 'X':
      return 8;
    case 'Q':
    case 'Z':
      return 10;
    default:
      return 0;
  }
}