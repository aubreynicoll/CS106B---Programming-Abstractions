/* Exercise 3.20
 *
 * This program accepts two DNA sequences, and returns the first index at which
 * the second may attach to the first. DNA matches in the following pattern:
 * A <-> T
 * C <-> G
 * */

#include <iostream>
#include <string>

using namespace std;

int findDNAMatch(string s1, string s2, int startIndex = 0);
string getInverseSequence(string dna);
char getInverseBase(char base);
string getReverseSequence(string dna);

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

  string reverseSequence = getReverseSequence(s2);

  int sequenceMatch = s1.find(getInverseSequence(s2), startIndex);
  int reverseSequenceMatch =
      s1.find(getInverseSequence(reverseSequence), startIndex);

  if (sequenceMatch != string::npos && reverseSequenceMatch != string::npos) {
    return (sequenceMatch < reverseSequenceMatch) ? sequenceMatch
                                                  : reverseSequenceMatch;
  } else if (sequenceMatch != string::npos ||
             reverseSequenceMatch != string::npos) {
    return sequenceMatch != string::npos ? sequenceMatch : reverseSequenceMatch;
  } else {
    return -1;
  }
}

string getInverseSequence(string dna) {
  for (int i = 0; i < dna.length(); i++) {
    dna[i] = getInverseBase(dna[i]);
  }
  return dna;
}

char getInverseBase(char base) {
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

string getReverseSequence(string dna) {
  for (int i = 0, j = dna.length() - 1; i < j; i++, j--) {
    char temp = dna[i];
    dna[i] = dna[j];
    dna[j] = temp;
  }
  return dna;
}