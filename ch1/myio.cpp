/* My IO
 *
 * This is an early attempt at writing my own reusable code.
 *
 * My IO contains functions for reading input from the user in a way that is
 * consistent and safe.
 * */

#include "myio.h"

using namespace std;

int getInt(string prompt) {
  int n;

  while (true) {
    string s;
    istringstream stream;

    cout << prompt;
    getline(cin, s);
    stream.str(s);
    stream >> n;

    if (!stream.fail()) break;

    cerr << "Bad input." << endl;
  }

  return n;
}

double getDouble(string prompt) {
  double d;

  while (true) {
    string s;
    istringstream stream;

    cout << prompt;
    getline(cin, s);
    stream.str(s);
    stream >> d;

    if (!stream.fail()) break;

    cerr << "Bad input." << endl;
  }

  return d;
}