/* Exercise 3.11
 *
 * This program implements the isSentencePalindrome predicate, which checks that
 * a sentence is a palindrome while ignoring case and punctuation.
 * */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

bool isSentencePalindrome(string sentence);

int main() {
  cout << "This program checks to see if a sentence is a palindrome." << endl;

  string s;

  cout << "Enter a sentence: ";
  getline(cin, s);

  if (isSentencePalindrome(s)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}

bool isSentencePalindrome(string sentence) {
  int i = -1;
  int j = sentence.length();

  while (i < j) {
    while (!isalpha(sentence[++i]))
      ;
    while (!isalpha(sentence[--j]))
      ;

    if (tolower(sentence[i]) != tolower(sentence[j])) return false;
  }

  return true;
}