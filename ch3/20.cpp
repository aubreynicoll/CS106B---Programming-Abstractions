/* Exercise 3.20
 *
 * This program accepts two DNA sequences, and returns the first index at which
 * the second sequence may attach to the first. DNA matches in the following
 * pattern: A <-> T C <-> G
 *
 * The function attempts to pattern match by inverting the second sequence. It
 * then looks for a match in the original sequence. It also checks for a reverse
 * match. If no match is found, it returns -1.
 * */

#include <iostream>
#include <string>

using namespace std;

int findDNAMatch(string s1, string s2, int startIndex = 0);
string getInvertedSequence(string dna);
char getInvertedBase(char base);
string getReversedSequence(string dna);

int main() {
  cout << "This program matches one dna sequence to another." << endl;

  while (true) {
    cout << "Enter the sequence to search within: ";

    string s1;
    getline(cin, s1);

    cout << "Enter the sequence to search for: ";

    string s2;
    getline(cin, s2);

    int index = findDNAMatch(s1, s2);

    if (index == -1) {
      cout << "No match." << endl;
    } else {
      cout << "DNA Sequence 2 can attach at index: " << index << endl;
    }
  }
  return 0;
}

int findDNAMatch(string s1, string s2, int startIndex) {
  if (s2.length() > s1.length()) return -1;

  string reversedSequence = getReversedSequence(s2);

  int sequenceMatch = s1.find(getInvertedSequence(s2), startIndex);
  int reversedSequenceMatch =
      s1.find(getInvertedSequence(reversedSequence), startIndex);

  if (sequenceMatch == string::npos && reversedSequenceMatch == string::npos) {
    return -1;
  } else if (sequenceMatch == string::npos ||
             reversedSequenceMatch == string::npos) {
    return sequenceMatch != string::npos ? sequenceMatch
                                         : reversedSequenceMatch;
  } else {
    return (sequenceMatch < reversedSequenceMatch) ? sequenceMatch
                                                   : reversedSequenceMatch;
  }
}

string getInvertedSequence(string dna) {
  for (int i = 0; i < dna.length(); i++) {
    dna[i] = getInvertedBase(dna[i]);
  }
  return dna;
}

char getInvertedBase(char base) {
  switch (base) {
    case 'A':
      return 'T';
    case 'C':
      return 'G';
    case 'G':
      return 'C';
    case 'T':
      return 'A';
    default:
      return '?';
  }
}

string getReversedSequence(string dna) {
  for (int i = 0, j = dna.length() - 1; i < j; i++, j--) {
    char temp = dna[i];
    dna[i] = dna[j];
    dna[j] = temp;
  }
  return dna;
}