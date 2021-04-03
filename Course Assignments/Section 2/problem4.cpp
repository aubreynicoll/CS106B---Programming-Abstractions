/* Problem 4: Map Warm-up
 *
 * This program contains a function that receives a reference to a file stream
 * and a reference to an int. It then proceeds to count the number of each
 * character found in the file, storing the greatest number of occurrences to
 * the int reference and returning the most common character.
 *
 * The program does not count blanks.
 * */

#include <map>

#include "../Library/common.h"

char mostFrequentCharacter(ifstream &file, int &numOfOccurrences);

int main() {
  ifstream file;
  int numOfOccurrences = 0;
  char mostFrequentChar = '\0';

  do {
    string filename;
    cout << "Enter filename: ";
    getline(cin, filename);
    file.open(filename);
  } while (file.fail());

  mostFrequentChar = mostFrequentCharacter(file, numOfOccurrences);

  cout << char(mostFrequentChar) << " appeared " << numOfOccurrences
       << " times." << endl;

  return 0;
}

char mostFrequentCharacter(ifstream &file, int &numOfOccurrences) {
  map<char, int> occurrencesMap;

  int c;
  while ((c = file.get()) != EOF) {
    if (c == ' ') continue;

    if (occurrencesMap.count(c)) {
      occurrencesMap[c]++;
    } else {
      occurrencesMap[c] = 1;
    }
  }

  char mostFrequentChar = '\0';
  for (map<char, int>::iterator it = occurrencesMap.begin();
       it != occurrencesMap.end(); it++) {
    if (it->second > numOfOccurrences) {
      numOfOccurrences = it->second;
      mostFrequentChar = it->first;
    }
  }
  return mostFrequentChar;
}