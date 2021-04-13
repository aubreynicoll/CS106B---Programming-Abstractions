/* Exercise 3.19
 *
 * This program implements the function invertKey, which returns the the cipher
 * used to decode messages encoded by the supplied key.
 * */

#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, char> getReverseCipher(string key = "ZYXWVUTSRQPONMLKJIHGFEDCBA");

int main() { return 0; }

map<char, char> getReverseCipher(string key) {
  map<char, char> reverseCipher;

  for (int i = 0; i < 26; i++) {
    reverseCipher[toupper(key[i])] = i + 'A';
  }

  return reverseCipher;
}