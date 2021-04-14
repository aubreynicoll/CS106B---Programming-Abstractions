/* Exercise 4.4
 *
 * This program reads in a file and counts the lines, words, and characters
 * */

#include <cctype>
#include <fstream>
#include <iostream>

using namespace std;

int main() {
  ifstream file;

  do {
    cout << "Enter filename: ";
    string filename;
    getline(cin, filename);
    file.open(filename);
  } while (file.fail());

  int lines = 0, words = 0, characters = 0;

  string line;
  while (getline(file, line)) {
    lines++;
    characters += line.length();

    bool insideWord = false;
    for (int i = 0; i < line.length(); i++) {
      if (!insideWord && isalpha(line[i])) {
        words++;
        insideWord = true;
      } else if (isblank(line[i])) {
        insideWord = false;
      }
    }
  }

  cout << "Lines: " << lines << endl;
  cout << "Words: " << words << endl;
  cout << "Chars: " << characters << endl;

  return 0;
}