/* Exercise 3.13
 *
 * This program implements getOrdinalForm(), which appends the ordinal suffix
 * to an integer according to the rules of English.
 * */

#include <simpio.h>

#include <iostream>
#include <string>

using namespace std;

string getOrdinalForm(int n);

int main() {
  cout << "This program appends the ordinal suffix to an integer." << endl;

  for (int i = 0; i < 100; i++) {
    cout << getOrdinalForm(i) << endl;
  }
  return 0;
}

string getOrdinalForm(int n) {
  string number = to_string(n);

  if (number.length() > 1 && number[number.length() - 2] == '1') {
    number += "th";
  } else {
    switch (number[number.length() - 1]) {
      case '1':
        number += "st";
        break;
      case '2':
        number += "nd";
        break;
      case '3':
        number += "rd";
        break;
      default:
        number += "th";
        break;
    }
  }

  return number;
}