/* Exercise 3.2
 *
 * This program implements the common function trim(), which removes heading and
 * tailing whitespaces.
 * */

#include <cctype>
#include <iostream>
#include <string>

using namespace std;

string trim(string str);

int main() {
  string str = "  This string has 5 spaces to trim   ";
  string trimmed = trim(str);

  cout << str << endl;
  cout << str.length() << endl;
  cout << trimmed << endl;
  cout << trimmed.length() << endl;

  return 0;
}

string trim(string str) {
  int i = 0;
  while (isblank(str[i])) i++;
  str.erase(0, i);

  i = str.length() - 1;
  while (isblank(str[i])) i--;
  str.erase(i + 1);

  return str;
}