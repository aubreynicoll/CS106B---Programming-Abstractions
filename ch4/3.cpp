/* Exercise 4.3
 *
 * This program prints the longest line in a file selected by the user.
 * */

#include <fstream>
#include <iostream>

using namespace std;

string getLongestLine(ifstream &file);

int main() {
  ifstream file;

  do {
    cout << "Enter filename: ";
    string filename;
    getline(cin, filename);
    file.open(filename);
  } while (file.fail());

  string longest = getLongestLine(file);

  cout << longest << endl;

  return 0;
}

string getLongestLine(ifstream &file) {
  string line, longestLine;

  while (getline(file, line)) {
    if (line.length() > longestLine.length()) longestLine = line;
  }

  return longestLine;
}