/* Exercise 3.18
 *
 * This program implements a letter-substitution cipher. It asks the user for a
 * 26-letter key, and then maps the alphabet to these letters. It may then
 * encode any number of messages using this map.
 * */

#include <cctype>
#include <iostream>
#include <map>
#include <string>

using namespace std;

map<char, char> getCipher(string key = "ZYXWVUTSRQPONMLKJIHGFEDCBA");
string encodeMessage(string message, map<char, char> &cipher);

int main() {
  cout << "This program allows the user to enter a 26-character cipher, then "
          "encode messages with it."
       << endl;

  cout << "Enter a 26 character key of unique symbols: ";

  string key;
  getline(cin, key);

  map<char, char> cipher = (key.length() != 26) ? getCipher() : getCipher(key);

  while (true) {
    cout << "Enter a message: ";

    string message;
    getline(cin, message);

    if (message == "") break;

    cout << encodeMessage(message, cipher) << endl;
  }
  return 0;
}

map<char, char> getCipher(string key) {
  map<char, char> cipher;

  for (int i = 0; i < 26; i++) {
    cipher[i + 'A'] = toupper(key[i]);
  }

  return cipher;
}

string encodeMessage(string message, map<char, char> &cipher) {
  for (int i = 0; i < message.length(); i++) {
    if (isalpha(message[i])) {
      bool isLowercase = message[i] >= 'a' && message[i] <= 'z';

      if (isLowercase) message[i] = toupper(message[i]);
      message[i] = cipher.at(message[i]);
      if (isLowercase) message[i] = tolower(message[i]);
    }
  }
  return message;
}