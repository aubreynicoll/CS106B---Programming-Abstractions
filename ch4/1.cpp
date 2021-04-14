/* Exercise 4.1
 *
 * This program prints a table of sine and cosine values for a number of angles.
 * */

#include <iomanip>
#include <iostream>

using namespace std;

const double PI = 3.14159265359;

void printTrigFuncs();

int main() {
  printTrigFuncs();
  return 0;
}

void printTrigFuncs() {
  cout << " theta | sin(theta) | cos(theta) |" << endl;
  cout << "-------+------------+------------+" << endl;

  cout << right << fixed << setprecision(7);

  for (int theta = -90; theta <= 90; theta += 15) {
    cout << setw(5) << theta << "  | " << setw(10) << sin(theta * PI / 180)
         << " | " << setw(10) << cos(theta * PI / 180) << " |" << endl;
  }

  return;
}